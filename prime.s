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
	.pad	#56
	sub	sp, #56
	movs	r0, #0
	str	r0, [sp, #52]
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
	str	r0, [sp, #52]
	b	.LBB0_1
.LBB0_1:
	ldr	r0, [sp, #92]
	str	r0, [sp, #44]
	ldr	r0, [sp, #44]
	asrs	r0, r0, #20
	str	r0, [sp, #44]
	movs	r0, #0
	str	r0, [sp, #40]
	str	r0, [sp, #36]
	b	.LBB0_2
.LBB0_2:
	ldr	r0, [sp, #36]
	cmp	r0, #2
	bgt	.LBB0_7
	b	.LBB0_3
.LBB0_3:
	ldr	r0, [sp, #44]
	movs	r1, #15
	ands	r0, r1
	str	r0, [sp, #32]
	ldr	r0, [sp, #44]
	asrs	r0, r0, #4
	str	r0, [sp, #44]
	b	.LBB0_4
.LBB0_4:
	ldr	r0, [sp, #32]
	adds	r0, #48
	str	r0, [sp, #48]
	b	.LBB0_5
.LBB0_5:
	b	.LBB0_6
.LBB0_6:
	ldr	r0, [sp, #36]
	adds	r0, r0, #1
	str	r0, [sp, #36]
	b	.LBB0_2
.LBB0_7:
	b	.LBB0_8
.LBB0_8:
	b	.LBB0_9
.LBB0_9:
	movs	r0, #10
	str	r0, [sp, #48]
	b	.LBB0_10
.LBB0_10:
	movs	r0, #3
	str	r0, [sp, #28]
	b	.LBB0_11
.LBB0_11:
	movs	r0, #2
	str	r0, [sp, #24]
	b	.LBB0_12
.LBB0_12:
	ldr	r0, [sp, #24]
	ldr	r1, [sp, #28]
	cmp	r0, r1
	bhs	.LBB0_23
	b	.LBB0_13
.LBB0_13:
	ldr	r0, [sp, #24]
	str	r0, [sp, #20]
	b	.LBB0_14
.LBB0_14:
	ldr	r0, [sp, #20]
	ldr	r1, [sp, #28]
	cmp	r0, r1
	bhs	.LBB0_21
	b	.LBB0_15
.LBB0_15:
	ldr	r0, [sp, #24]
	ldr	r1, [sp, #20]
	muls	r1, r0, r1
	str	r1, [sp, #16]
	ldr	r0, [sp, #16]
	ldr	r1, [sp, #28]
	cmp	r0, r1
	bls	.LBB0_17
	b	.LBB0_16
.LBB0_16:
	b	.LBB0_21
.LBB0_17:
	ldr	r0, [sp, #16]
	ldr	r1, [sp, #28]
	cmp	r0, r1
	bne	.LBB0_19
	b	.LBB0_18
.LBB0_18:
	b	.LBB0_34
.LBB0_19:
	b	.LBB0_20
.LBB0_20:
	ldr	r0, [sp, #20]
	adds	r0, r0, #1
	str	r0, [sp, #20]
	b	.LBB0_14
.LBB0_21:
	b	.LBB0_22
.LBB0_22:
	ldr	r0, [sp, #24]
	adds	r0, r0, #1
	str	r0, [sp, #24]
	b	.LBB0_12
.LBB0_23:
	ldr	r0, [sp, #28]
	str	r0, [sp, #52]
	b	.LBB0_24
.LBB0_24:
	ldr	r0, [sp, #92]
	str	r0, [sp, #12]
	ldr	r0, [sp, #12]
	asrs	r0, r0, #20
	str	r0, [sp, #12]
	movs	r0, #0
	str	r0, [sp, #8]
	str	r0, [sp, #4]
	b	.LBB0_25
.LBB0_25:
	ldr	r0, [sp, #4]
	cmp	r0, #2
	bgt	.LBB0_30
	b	.LBB0_26
.LBB0_26:
	ldr	r0, [sp, #12]
	movs	r1, #15
	ands	r0, r1
	str	r0, [sp]
	ldr	r0, [sp, #12]
	asrs	r0, r0, #4
	str	r0, [sp, #12]
	b	.LBB0_27
.LBB0_27:
	ldr	r0, [sp]
	adds	r0, #48
	str	r0, [sp, #48]
	b	.LBB0_28
.LBB0_28:
	b	.LBB0_29
.LBB0_29:
	ldr	r0, [sp, #4]
	adds	r0, r0, #1
	str	r0, [sp, #4]
	b	.LBB0_25
.LBB0_30:
	b	.LBB0_31
.LBB0_31:
	b	.LBB0_32
.LBB0_32:
	movs	r0, #10
	str	r0, [sp, #48]
	b	.LBB0_33
.LBB0_33:
	b	.LBB0_34
.LBB0_34:
	b	.LBB0_35
.LBB0_35:
	ldr	r0, [sp, #28]
	adds	r0, r0, #2
	str	r0, [sp, #28]
	b	.LBB0_11
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cantunwind
	.fnend


	.ident	"clang version 8.0.0-3~ubuntu18.04.2 (tags/RELEASE_800/final)"
	.section	".note.GNU-stack","",%progbits
	.addrsig
	.eabi_attribute	30, 6
