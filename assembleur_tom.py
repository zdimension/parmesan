#!/usr/bin/env python3

import re

regexes = { re.compile(k): v for k, v in 
	[
		(r"(?:\{(R\w+)\})", r"(?:r(?P<\1>\\d))"),
		(r"(?:\{(imm\d)\})", r"#(?P<\1>\\d+)"),
		(r"\{cond\}", r"(?P<cond>(?:[a-z]{2})?)"),
		(r"\{label\}", r"(?P<label>[\.\\w]+)")
	]
}

conds = ["eq", "ne", "cs", "cc", "mi", "pl", "vs", "vc", "hi", "ls", "ge", "lt", "gt", "le", "al"]

ins = {}

for k, v in {
	# shift, add, sub, mov
	"lsls {Rd}, {Rm}, {imm5}":      (0b000_00, "imm5", "Rm", "Rd"),
	"lsrs {Rd}, {Rm}, {imm5}":      (0b000_01, "imm5", "Rm", "Rd"),
	"asrs {Rd}, {Rm}, {imm5}":      (0b000_10, "imm5", "Rm", "Rd"),
	"adds {Rd}, {Rn}, {Rm}":        (0b000_11_00, "Rm", "Rn", "Rd"),
	"subs {Rd}, {Rn}, {Rm}":        (0b000_11_01, "Rm", "Rn", "Rd"),
	"adds {Rd}, {Rn}, {imm3}":      (0b000_11_10, "imm3", "Rn", "Rd"),
	"subs {Rd}, {Rn}, {imm3}":      (0b000_11_11, "imm3", "Rn", "Rd"),
	"movs {Rd}, {imm8}":            (0b001_00, "Rd", "imm8"),
	
	# data processing
	"ands {Rdn}, {Rm}":             (0b010000_0000, "Rm", "Rdn"),
	"eors {Rdn}, {Rm}":             (0b010000_0001, "Rm", "Rdn"),
	"lsls {Rdn}, {Rm}":             (0b010000_0010, "Rm", "Rdn"),
	"lsrs {Rdn}, {Rm}":             (0b010000_0011, "Rm", "Rdn"),
	"asrs {Rdn}, {Rm}":             (0b010000_0100, "Rm", "Rdn"),
	"adcs {Rdn}, {Rm}":             (0b010000_0101, "Rm", "Rdn"),
	"sbcs {Rdn}, {Rm}":             (0b010000_0110, "Rm", "Rdn"),
	"rors {Rdn}, {Rm}":             (0b010000_0111, "Rm", "Rdn"),
	"tst {Rn}, {Rm}":               (0b010000_1000, "Rm", "Rn"),
	"rsbs {Rd}, {Rn}, #0":          (0b010000_1001, "Rm", "Rdn"),
	"cmp {Rn}, {Rm}":               (0b010000_1010, "Rm", "Rn"),
	"cmn {Rn}, {Rm}":               (0b010000_1011, "Rm", "Rn"),
	"orrs {Rdn}, {Rm}":             (0b010000_1100, "Rm", "Rdn"),
	"muls {Rdm}, {Rn}, {Rdm_}":     (0b010000_1101, "Rn", "Rdm"),
	"bics {Rdn}, {Rm}":             (0b010000_1110, "Rm", "Rdn"),
	"mvns {Rd}, {Rm}":              (0b010000_1111, "Rm", "Rd"),
	
	# load/store
	"str {Rt}, [sp(?:, {imm8})?]":  (0b1001_0, "Rt", "imm8"),
	"ldr {Rt}, [sp(?:, {imm8})?]":  (0b1001_1, "Rt", "imm8"),
	
	# miscellaneous
	"add (sp, )?sp, {imm7}":        (0b1011_0000_0, "imm7"),
	"sub (sp, )?sp, {imm7}":        (0b1011_0000_1, "imm7"),
	
	# branch
	"b({cond})? {label}":           (0b1101, "cond", "label")
}.items():
	k = k.replace("[", "\\[").replace("]", "\\]")
	for rg, sub in regexes.items():
		k = rg.sub(sub, k)
	ins[re.compile(k)] = v
	
log = []
jumps = []

def assemble(line, labels, pc):
	instr, args = line.split(None, 1)
	args = ", ".join(map(str.strip, filter(len, args.split(","))))
	for i in ins:
		m = i.match(instr + " "+ args)
		if m:
			break
	else:
		print("Invalid instruction:", line)
		exit()
	dic = m.groupdict()
	for k, v in dic.items():
		if v is None:
			v = 0
		if k[0] == "R":
			dic[k] = int(v)
			if not (0 <= dic[k] <= 7):
				print("Invalid register:", v)
				exit()
		elif k == "cond":
			if not v:
				v = "al"
			try:
				dic[k] = conds.index(v)
			except ValueError:
				print("Invalid condition:", v)
				exit()
		elif k == "label":
			try:
				dic[k] = labels[v] - pc - 3
				jumps.append((pc, labels[v]))
			except KeyError:
				print("Invalid label:", v)
				print("Available:", ", ".join(labels.keys()))
				exit()
		elif k.startswith("imm"):
			dic[k] = int(v)
			if not (0 <= dic[k] < 2 ** int(k[3:])):
				print("Immediate value out of bounds:", v)
				exit()
	output = ins[i]
	res = 0
	pos = 0
	for val in output:
		width = 0
		if type(val) == str:
			if val[0] == "R":
				width = 3
			elif val.startswith("imm"):
				width = int(k[3:])
			elif val == "label":
				width = 8
			elif val == "cond":
				width = 4
			val = dic[val]
		res <<= width
		if width != 0:
			val &= 2 ** width - 1
		res += val 
	log.append(f"{pc*2:02x} | {res:04x} | {instr + ' ' + args:20} | {', '.join(f'{k}={v}' for k, v in dic.items()):20}")
	return res

import sys

if len(sys.argv) == 2:
	fn = sys.argv[1]
	fp = open(fn, "r")
	import os
	fo = open(os.path.splitext(fn)[0] + ".bin", "w")
else:
	fp = sys.stdin
	fo = sys.stdout
data = []

rlbl = re.compile(r"([\.\w]+):")
with fp:
	pc = 0
	labels = {}
	lines = filter(len, map(str.strip, map(str.lower, fp.readlines())))
	instrs = []
	for line in lines:
		if line[0] == "@":
			continue
		m = rlbl.match(line)
		if m:
			labels[m.group(1)] = pc
			continue
		else:
			if line[0] == ".":
				continue
			else:
				instrs.append(line)
				pc += 1
	print(labels)
	pc = 0
	columns = f"PC |  OP  | {'Instruction':^20} | {'Arguments':^20}"
	
	for line in instrs:
		try:
			data.append(assemble(line, labels, pc))
		except Exception as e:
			print(repr(line))
			print(e)
			exit()
		pc += 1
	print(columns)
	print("-" * len(columns))
	def set(s, i, c):
		if len(s) < i:
			s = s.ljust(i)
		return s[:i] + c + s[i+len(c):]
	for depth, (src, dst) in enumerate(jumps):
		conflict = sum(1 for s, d in jumps[:depth] if s <= src <= d)
		pos = conflict * 6
		dsh = "─" * 3
		# start, end = "┐", "┘"
		start, end = "╮", "╯"
		step = 1
		if dst < src:
			start, end = end, start
			step = -1
		log[src] = set(log[src], 55 + pos, ">" + dsh + start)
		for i in range(src + step, dst, step):
			log[i] = set(log[i], 59 + pos, "│")
		log[dst] = set(log[dst], 55 + pos, "<" + dsh + end)
	for line in log:
		print(line)
	print("-" * len(columns))
	print(columns)

with fo:
	fo.write("v2.0 raw\n")
	for word in data:
		fo.write(f"{word:04x} ")
	fo.write("\n")