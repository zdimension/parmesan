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
	.file	"prime.c"
	.globl	main
	.p2align	1
	.type	main,%function
	.code	16
	.thumb_func
main:
	.fnstart
	.pad	#36
	sub	sp, #36
	movs	r0, #0
	str	r0, [sp, #32]
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
	movs	r0, #2
	str	r0, [sp, #24]
	b	.LBB0_1
.LBB0_1:
	movs	r0, #2
	str	r0, [sp, #20]
	b	.LBB0_2
.LBB0_2:
	movs	r0, #2
	str	r0, [sp, #16]
	b	.LBB0_3
.LBB0_3:
	ldr	r0, [sp, #20]
	ldr	r1, [sp, #16]
	muls	r1, r0, r1
	ldr	r0, [sp, #24]
	cmp	r1, r0
	bne	.LBB0_5
	b	.LBB0_4
.LBB0_4:
	b	.LBB0_24
.LBB0_5:
	ldr	r0, [sp, #20]
	ldr	r1, [sp, #16]
	muls	r1, r0, r1
	ldr	r0, [sp, #24]
	cmp	r1, r0
	bls	.LBB0_7
	b	.LBB0_6
.LBB0_6:
	b	.LBB0_9
.LBB0_7:
	b	.LBB0_8
.LBB0_8:
	ldr	r0, [sp, #16]
	adds	r0, r0, #1
	str	r0, [sp, #16]
	b	.LBB0_3
.LBB0_9:
	ldr	r0, [sp, #20]
	ldr	r1, [sp, #24]
	cmp	r0, r1
	bls	.LBB0_11
	b	.LBB0_10
.LBB0_10:
	b	.LBB0_13
.LBB0_11:
	b	.LBB0_12
.LBB0_12:
	ldr	r0, [sp, #20]
	adds	r0, r0, #1
	str	r0, [sp, #20]
	b	.LBB0_2
.LBB0_13:
	ldr	r0, [sp, #24]
	str	r0, [sp, #32]
	b	.LBB0_14
.LBB0_14:
	ldr	r0, [sp, #72]
	str	r0, [sp, #12]
	ldr	r0, [sp, #12]
	asrs	r0, r0, #20
	str	r0, [sp, #12]
	movs	r0, #0
	str	r0, [sp, #8]
	str	r0, [sp, #4]
	b	.LBB0_15
.LBB0_15:
	ldr	r0, [sp, #4]
	cmp	r0, #2
	bgt	.LBB0_20
	b	.LBB0_16
.LBB0_16:
	ldr	r0, [sp, #12]
	movs	r1, #15
	ands	r0, r1
	str	r0, [sp]
	ldr	r0, [sp, #12]
	asrs	r0, r0, #4
	str	r0, [sp, #12]
	b	.LBB0_17
.LBB0_17:
	ldr	r0, [sp]
	adds	r0, #48
	str	r0, [sp, #28]
	b	.LBB0_18
.LBB0_18:
	b	.LBB0_19
.LBB0_19:
	ldr	r0, [sp, #4]
	adds	r0, r0, #1
	str	r0, [sp, #4]
	b	.LBB0_15
.LBB0_20:
	b	.LBB0_21
.LBB0_21:
	b	.LBB0_22
.LBB0_22:
	movs	r0, #10
	str	r0, [sp, #28]
	b	.LBB0_23
.LBB0_23:
	b	.LBB0_24
.LBB0_24:
	b	.LBB0_25
.LBB0_25:
	ldr	r0, [sp, #24]
	adds	r0, r0, #1
	str	r0, [sp, #24]
	b	.LBB0_1
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cantunwind
	.fnend


	.ident	"clang version 8.0.0-3~ubuntu18.04.2 (tags/RELEASE_800/final)"
	.section	".note.GNU-stack","",%progbits
	.addrsig
	.eabi_attribute	30, 6
