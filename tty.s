	.text
	.syntax unified
	.eabi_attribute	67, "2.09"
	.cpu	cortex-m0
	.eabi_attribute	6, 12
	.eabi_attribute	7, 77
	.eabi_attribute	8, 0
	.eabi_attribute	9, 1
	.eabi_attribute	34, 0
	.eabi_attribute	17, 1
	.eabi_attribute	20, 1
	.eabi_attribute	21, 1
	.eabi_attribute	23, 3
	.eabi_attribute	24, 1
	.eabi_attribute	25, 1
	.eabi_attribute	38, 1
	.eabi_attribute	18, 4
	.eabi_attribute	26, 2
	.eabi_attribute	14, 0
	.file	"tty.c"
	.globl	run
	.p2align	1
	.type	run,%function
	.code	16
	.thumb_func
run:
	.fnstart
	.pad	#64
	sub	sp, #64
	@APP
	sub	sp, #508
	@NO_APP
	@APP
	sub	sp, #452
	@NO_APP
	movs	r0, #80
	str	r0, [sp]
	movs	r0, #65
	str	r0, [sp]
	movs	r1, #82
	str	r1, [sp]
	movs	r1, #77
	str	r1, [sp]
	movs	r1, #69
	str	r1, [sp]
	movs	r1, #83
	str	r1, [sp]
	str	r0, [sp]
	movs	r0, #78
	str	r0, [sp]
	movs	r0, #33
	str	r0, [sp]
	b	.LBB0_1
.LBB0_1:
	b	.LBB0_1
.Lfunc_end0:
	.size	run, .Lfunc_end0-run
	.cantunwind
	.fnend


	.ident	"clang version 8.0.0-3~ubuntu18.04.2 (tags/RELEASE_800/final)"
	.section	".note.GNU-stack","",%progbits
	.addrsig
	.eabi_attribute	30, 6