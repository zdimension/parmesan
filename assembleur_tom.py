#!/usr/bin/env python3

import re, sys, os

regexes = [
	(r"(?:\{(R\w+)\})", r"(?P<F\1>r(?P<\1>\\d))"),
	(r"(?:\{(imm\d)\})", r"(?P<F\1>#(?P<\1>\\d+))"),
	(r"\{cond\}", r"(?P<cond>(?:[a-z]{2})?)"),
	(r"\{label\}", r"(?P<label>[\.\\w]+)")
]
regexes = { re.compile(k): v for k, v in regexes }

conds = ["eq", "ne", "cs", "cc", "mi", "pl", "vs", "vc", "hi", "ls", "ge", "lt", "gt", "le", "al", "nv"]
conds_alias = {"hs": "cs", "lo": "cc"}

ins = {}

for k, v in {
	# 01 - move shifted register
	"lsls {Rd}, {Rm}, {imm5}":      (0b000_00, "imm5", "Rm", "Rd"),
	"lsrs {Rd}, {Rm}, {imm5}":      (0b000_01, "imm5", "Rm", "Rd"),
	"asrs {Rd}, {Rm}, {imm5}":      (0b000_10, "imm5", "Rm", "Rd"),
	"movs {Rd}, {Rm}":              "lsls {Rd}, {Rm}, #0",
	# 2 - add/subtract
	"adds {Rd}, {Rn}, {Rm}":        (0b000_11_00, "Rm", "Rn", "Rd"),
	"subs {Rd}, {Rn}, {Rm}":        (0b000_11_01, "Rm", "Rn", "Rd"),
	"adds {Rd}, {Rn}, {imm3}":      (0b000_11_10, "imm3", "Rn", "Rd"),
	"subs {Rd}, {Rn}, {imm3}":      (0b000_11_11, "imm3", "Rn", "Rd"),
	# 03 - move/compare/add/subtract immediate
	"movs {Rd}, {imm8}":            (0b001_00, "Rd", "imm8"),
	# 04 - ALU operations
	"ands {Rdn}, {Rm}":             (0b010000_0000, "Rm", "Rdn"),
	"eors {Rdn}, {Rm}":             (0b010000_0001, "Rm", "Rdn"),
	"lsls {Rdn}, {Rm}":             (0b010000_0010, "Rm", "Rdn"),
	"lsrs {Rdn}, {Rm}":             (0b010000_0011, "Rm", "Rdn"),
	"asrs {Rdn}, {Rm}":             (0b010000_0100, "Rm", "Rdn"),
	"adcs {Rdn}, {Rm}":             (0b010000_0101, "Rm", "Rdn"),
	"sbcs {Rdn}, {Rm}":             (0b010000_0110, "Rm", "Rdn"),
	"rors {Rdn}, {Rm}":             (0b010000_0111, "Rm", "Rdn"),
	"tst {Rn}, {Rm}":               (0b010000_1000, "Rm", "Rn"),
	"rsbs {Rd}, {Rn}, #0":          (0b010000_1001, "Rn", "Rd"),
	"cmp {Rn}, {Rm}":               (0b010000_1010, "Rm", "Rn"),
	"cmn {Rn}, {Rm}":               (0b010000_1011, "Rm", "Rn"),
	"orrs {Rdn}, {Rm}":             (0b010000_1100, "Rm", "Rdn"),
	"muls {Rdm}, {Rn}, {Rdm_}":     (0b010000_1101, "Rn", "Rdm"),
	"bics {Rdn}, {Rm}":             (0b010000_1110, "Rm", "Rdn"),
	"mvns {Rd}, {Rm}":              (0b010000_1111, "Rm", "Rd"),
	"negs {Rd}, {Rn}":              "rsbs {Rd}, {Rn}, #0",	
	# 11 - load/store
	"str {Rt}, [sp(?:, {imm8})?]":  (0b1001_0, "Rt", "imm8"),
	"ldr {Rt}, [sp(?:, {imm8})?]":  (0b1001_1, "Rt", "imm8"),	
	# 13 - miscellaneous
	"add (sp, )?sp, {imm7}":        (0b1011_0000_0, "imm7"),
	"sub (sp, )?sp, {imm7}":        (0b1011_0000_1, "imm7"),	
	# 16 - branch
	"b({cond})? {label}":           (0b1101, "cond", "label")
}.items():
	k = k.replace("[", "\\[").replace("]", "\\]")
	for rg, sub in regexes.items():
		k = rg.sub(sub, k)
	ins[re.compile("^" + k + "$")] = v
	
log = []
jumps = []

def assemble(line, labels, pc):
	try:
		instr, args = line.split(None, 1)
	except:
		raise Exception(f"Invalid line: {line}")
	oline = line = instr + " " + ", ".join(map(str.strip, filter(len, args.split(","))))
	found = False
	while not found:
		for i, output in ins.items():
			m = i.match(line)
			if m:
				if type(output) == str:
					for c, rep in m.groupdict().items():
						if c[0] == "F":
							output = output.replace(f"{{{c[1:]}}}", rep)
					print(output)
					line = output
				else:
					found = True
				break
		else:
			raise Exception(f"Invalid instruction: {oline}")
	dic = m.groupdict()
	for k, v in dic.items():
		if v is None:
			v = 0
		if k[0] == "R":
			dic[k] = (int(v), 3)
			if not (0 <= dic[k][0] <= 7):
				raise Exception(f"Invalid register: {v}")
		elif k == "cond":
			if not v:
				v = "al"
			try:
				dic[k] = (conds.index(conds_alias.get(v, v)), 4)
			except ValueError:
				raise Exception(f"Invalid condition: {v}")
		elif k == "label":
			try:
				dic[k] = (labels[v] - pc - 3, 8)
				jumps.append((pc, labels[v]))
			except KeyError:
				raise Exception(f"Invalid label: {v} (available: {', '.join(labels.keys())})")
		elif k.startswith("imm"):
			width = int(k[3:])
			dic[k] = (int(v), width)
			if not (0 <= dic[k][0] < 2 ** width):
				raise Exception(f"Immediate value out of bounds: {v}")
	for k, v in dic.items():
		if k[-1] == "_":
			other = dic[k[:-1]]
			if v != other:
				raise Exception(f"{k[:-1]} must have the same value for both parameters (has {other[0]}, {v[0]})")
	res = 0
	for nval in output:
		width = 0
		val = nval
		if type(val) == str:
			val, width = dic[val]
			if nval.startswith("imm") and "sp" in line:
				val >>= 2
		res <<= width
		if width != 0:
			val &= 2 ** width - 1
		res += val 
	return res, f"{pc*2:02x} │ {res:04x} │ {line:20} │ {', '.join(f'{k}={v[0] if v else str()}' for k, v in dic.items() if k[0] != 'F'):20}"

if len(sys.argv) == 2:
	fn = sys.argv[1]
	fp = open(fn, "r")
	fo = open(os.path.splitext(fn)[0] + ".bin", "w")
else:
	fp = sys.stdin
	fo = sys.stdout
data = []

rlbl = re.compile(r"^([\.\w]+)\s*:")
pc = 0
labels = {}
lines = map(str.lower, fp.readlines())
instrs = []
for i, line in enumerate(lines, 1):
	if "@" in line:
		line = line[:line.index("@")]
	while True:
		line = line.strip().lower()
		if not line:
			break
		m = rlbl.match(line)
		if m:
			labels[m.group(1)] = pc
			line = line[line.index(":")+1:]
			continue
		else:
			if line[0] == ".":
				break
			else:
				instrs.append((i, line))
				pc += 1
				break
pc = 0
columns = f"║ PC │  OP  │ {'Instruction':^20} │ {'Arguments':^20} ║"
sep = "╠" + "".join("═╪"[c == "│"] for c in columns[1:-1]) + "╣"
for i, line in instrs:
	try:
		opc, stat = assemble(line, labels, pc)
		data.append(opc)
		log.append("║ " + stat + " ║")
	except Exception as e:
		print(f"Build error on line {i}: {line}")
		print(e)
		exit()
	pc += 1
print("╔" + "".join("═╤"[c == "│"] for c in columns[1:-1]) + "╗")
print(columns)
print(sep)
def set(s, i, c):
	if len(s) < i:
		s = s.ljust(i)
	return s[:i] + c + s[i+len(c):]
root = len(columns) + 1
for depth, (src, dst) in enumerate(jumps):
	conflict = sum(1 for s, d in jumps[:depth] if s <= src <= d)
	dsh = "─" * 3
	pos = conflict * (len(dsh) + 3)
	start, end = "╮", "╯"
	step = 1
	if dst < src:
		start, end = end, start
		step = -1
	log[src] = set(log[src], root + pos, ">" + dsh + start)
	for i in range(src + step, dst, step):
		log[i] = set(log[i], root + pos + len(dsh) + 1, "│")
	log[dst] = set(log[dst], root + pos, "<" + dsh + end)
for line in log:
	print(line)
print(sep)
print(columns)
print("╚" + "".join("═╧"[c == "│"] for c in columns[1:-1]) + "╝")

fo.write("v2.0 raw\n")
for word in data:
	fo.write(f"{word:04x} ")
fo.write("\n")