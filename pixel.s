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
	.file	"pixel.c"
	.globl	main
	.p2align	1
	.type	main,%function
	.code	16
	.thumb_func
main:
	.fnstart
	.pad	#32
	sub	sp, #32
	movs	r0, #0
	str	r0, [sp, #28]
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
	str	r0, [sp, #24]
	movs	r0, #1
	str	r0, [sp, #20]
	str	r0, [sp, #16]
	movs	r0, #100
	str	r0, [sp, #4]
	b	.LBB0_28
.LBB0_1:
	b	.LBB0_2
.LBB0_2:
	ldr	r0, [sp, #12]
	movs	r1, #7
	subs	r0, r1, r0
	ldr	r1, [sp, #8]
	movs	r2, #3
	ands	r1, r2
	lsls	r1, r1, #3
	orrs	r0, r1
	movs	r1, #1
	lsls	r1, r0
	ldr	r0, [sp, #32]
	orrs	r0, r1
	str	r0, [sp, #32]
	b	.LBB0_3
.LBB0_3:
	b	.LBB0_4
.LBB0_4:
	ldr	r0, [sp, #20]
	movs	r1, #7
	subs	r0, r1, r0
	ldr	r1, [sp, #16]
	movs	r2, #3
	ands	r1, r2
	lsls	r1, r1, #3
	orrs	r0, r1
	movs	r1, #1
	lsls	r1, r0
	ldr	r0, [sp, #32]
	orrs	r0, r1
	str	r0, [sp, #32]
	b	.LBB0_5
.LBB0_5:
	b	.LBB0_6
.LBB0_6:
	movs	r0, #1
	str	r0, [sp, #36]
	b	.LBB0_7
.LBB0_7:
	ldr	r0, [sp, #48]
	cmp	r0, #0
	beq	.LBB0_9
	b	.LBB0_8
.LBB0_8:
	ldr	r0, [sp, #52]
	str	r0, [sp, #4]
	b	.LBB0_9
.LBB0_9:
	b	.LBB0_10
.LBB0_10:
	ldr	r0, [sp, #20]
	movs	r1, #7
	subs	r0, r1, r0
	ldr	r1, [sp, #16]
	movs	r2, #3
	ands	r1, r2
	lsls	r1, r1, #3
	orrs	r0, r1
	movs	r1, #1
	lsls	r1, r0
	ldr	r0, [sp, #32]
	bics	r0, r1
	str	r0, [sp, #32]
	b	.LBB0_11
.LBB0_11:
	movs	r0, #1
	cmp	r0, #0
	bne	.LBB0_14
	b	.LBB0_12
.LBB0_12:
	b	.LBB0_13
.LBB0_13:
	b	.LBB0_1
.LBB0_14:
	ldr	r0, [sp, #4]
	cmp	r0, #113
	bne	.LBB0_16
	b	.LBB0_15
.LBB0_15:
	ldr	r0, [sp, #20]
	subs	r0, r0, #1
	str	r0, [sp, #20]
	b	.LBB0_25
.LBB0_16:
	ldr	r0, [sp, #4]
	cmp	r0, #100
	bne	.LBB0_18
	b	.LBB0_17
.LBB0_17:
	ldr	r0, [sp, #20]
	adds	r0, r0, #1
	str	r0, [sp, #20]
	b	.LBB0_24
.LBB0_18:
	ldr	r0, [sp, #4]
	cmp	r0, #122
	bne	.LBB0_20
	b	.LBB0_19
.LBB0_19:
	ldr	r0, [sp, #16]
	subs	r0, r0, #1
	str	r0, [sp, #16]
	b	.LBB0_23
.LBB0_20:
	ldr	r0, [sp, #4]
	cmp	r0, #115
	bne	.LBB0_22
	b	.LBB0_21
.LBB0_21:
	ldr	r0, [sp, #16]
	adds	r0, r0, #1
	str	r0, [sp, #16]
	b	.LBB0_22
.LBB0_22:
	b	.LBB0_23
.LBB0_23:
	b	.LBB0_24
.LBB0_24:
	b	.LBB0_25
.LBB0_25:
	ldr	r0, [sp, #20]
	movs	r1, #7
	ands	r0, r1
	str	r0, [sp, #20]
	ldr	r0, [sp, #16]
	movs	r1, #3
	ands	r0, r1
	str	r0, [sp, #16]
	ldr	r0, [sp, #20]
	ldr	r1, [sp, #12]
	cmp	r0, r1
	bne	.LBB0_34
	b	.LBB0_26
.LBB0_26:
	ldr	r0, [sp, #16]
	ldr	r1, [sp, #8]
	cmp	r0, r1
	bne	.LBB0_34
	b	.LBB0_27
.LBB0_27:
	ldr	r0, [sp, #28]
	adds	r0, r0, #1
	str	r0, [sp, #28]
	b	.LBB0_28
.LBB0_28:
	b	.LBB0_29
.LBB0_29:
	ldr	r0, [sp, #64]
	movs	r1, #7
	ands	r0, r1
	str	r0, [sp, #12]
	ldr	r0, [sp, #64]
	movs	r1, #3
	ands	r0, r1
	str	r0, [sp, #8]
	b	.LBB0_30
.LBB0_30:
	ldr	r0, [sp, #20]
	ldr	r1, [sp, #12]
	movs	r2, #0
	cmp	r0, r1
	str	r2, [sp]
	bne	.LBB0_32
	b	.LBB0_31
.LBB0_31:
	ldr	r0, [sp, #16]
	ldr	r1, [sp, #8]
	subs	r0, r0, r1
	rsbs	r1, r0, #0
	adcs	r0, r1
	str	r0, [sp]
	b	.LBB0_32
.LBB0_32:
	ldr	r0, [sp]
	lsls	r0, r0, #31
	cmp	r0, #0
	bne	.LBB0_29
	b	.LBB0_33
.LBB0_33:
	b	.LBB0_34
.LBB0_34:
	b	.LBB0_13
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cantunwind
	.fnend


	.ident	"clang version 8.0.1-9 (tags/RELEASE_801/final)"
	.section	".note.GNU-stack","",%progbits
	.addrsig
	.eabi_attribute	30, 6
