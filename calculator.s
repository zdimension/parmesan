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
	.file	"calculator.c"
	.globl	main
	.p2align	1
	.type	main,%function
	.code	16
	.thumb_func
main:
	.fnstart
	.pad	#24
	sub	sp, #24
	movs	r0, #0
	str	r0, [sp, #20]
	@APP
	sub	sp, #120
	@NO_APP
	@APP
	sub	sp, #120
	@NO_APP
	@APP
	sub	sp, #120
	@NO_APP
	@APP
	sub	sp, #120
	@NO_APP
	@APP
	sub	sp, #120
	@NO_APP
	@APP
	sub	sp, #120
	@NO_APP
	@APP
	sub	sp, #120
	@NO_APP
	@APP
	sub	sp, #120
	@NO_APP
	@APP
	sub	sp, #56
	@NO_APP
	str	r0, [sp, #16]
	str	r0, [sp, #12]
	movs	r0, #1
	str	r0, [sp, #8]
	movs	r0, #2
	str	r0, [sp, #4]
	movs	r0, #3
	str	r0, [sp]
	b	.LBB0_1
.LBB0_1:
	ldr	r0, [sp, #36]
	ldr	r1, [sp, #12]
	cmp	r0, r1
	bne	.LBB0_3
	b	.LBB0_2
.LBB0_2:
	ldr	r0, [sp, #28]
	ldr	r1, [sp, #32]
	adds	r0, r0, r1
	str	r0, [sp, #20]
	b	.LBB0_3
.LBB0_3:
	ldr	r0, [sp, #36]
	ldr	r1, [sp, #8]
	cmp	r0, r1
	bne	.LBB0_5
	b	.LBB0_4
.LBB0_4:
	ldr	r0, [sp, #28]
	ldr	r1, [sp, #32]
	subs	r0, r0, r1
	str	r0, [sp, #20]
	b	.LBB0_5
.LBB0_5:
	ldr	r0, [sp, #36]
	ldr	r1, [sp, #4]
	cmp	r0, r1
	bne	.LBB0_7
	b	.LBB0_6
.LBB0_6:
	ldr	r0, [sp, #28]
	ldr	r1, [sp, #32]
	muls	r1, r0, r1
	str	r1, [sp, #20]
	b	.LBB0_7
.LBB0_7:
	ldr	r0, [sp, #36]
	ldr	r1, [sp]
	cmp	r0, r1
	bne	.LBB0_9
	b	.LBB0_8
.LBB0_8:
	ldr	r0, [sp, #28]
	ldr	r1, [sp, #32]
	lsls	r0, r1
	str	r0, [sp, #20]
	b	.LBB0_9
.LBB0_9:
	b	.LBB0_1
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cantunwind
	.fnend


	.ident	"clang version 8.0.1-9 (tags/RELEASE_801/final)"
	.section	".note.GNU-stack","",%progbits
	.addrsig
	.eabi_attribute	30, 6
