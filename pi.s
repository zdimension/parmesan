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
	.file	"pi.c"
	.globl	run
	.p2align	1
	.type	run,%function
	.code	16
	.thumb_func
run:
	.fnstart
	.pad	#116
	sub	sp, #116
	@APP
	sub	sp, #508
	@NO_APP
	@APP
	sub	sp, #452
	@NO_APP
	movs	r0, #100
	str	r0, [sp, #48]
	movs	r0, #1
	lsls	r0, r0, #15
	str	r0, [sp, #44]
	ldr	r0, [sp, #44]
	str	r0, [sp, #40]
	ldr	r0, [sp, #40]
	muls	r0, r0, r0
	str	r0, [sp, #40]
	movs	r0, #0
	str	r0, [sp, #36]
	ldr	r1, [sp, #44]
	subs	r1, r1, #1
	str	r1, [sp, #32]
	str	r0, [sp, #28]
	b	.LBB0_1
.LBB0_1:
	ldr	r0, [sp, #28]
	cmp	r0, #99
	bhi	.LBB0_8
	b	.LBB0_2
.LBB0_2:
	b	.LBB0_3
.LBB0_3:
	movs	r0, #46
	str	r0, [sp, #52]
	b	.LBB0_4
.LBB0_4:
	ldr	r0, [sp, #92]
	ldr	r1, [sp, #32]
	ands	r0, r1
	str	r0, [sp, #24]
	ldr	r0, [sp, #92]
	ldr	r1, [sp, #32]
	ands	r0, r1
	str	r0, [sp, #20]
	ldr	r0, [sp, #24]
	muls	r0, r0, r0
	ldr	r1, [sp, #20]
	muls	r1, r1, r1
	adds	r0, r0, r1
	ldr	r1, [sp, #40]
	cmp	r0, r1
	bhs	.LBB0_6
	b	.LBB0_5
.LBB0_5:
	ldr	r0, [sp, #36]
	adds	r0, r0, #1
	str	r0, [sp, #36]
	b	.LBB0_6
.LBB0_6:
	b	.LBB0_7
.LBB0_7:
	ldr	r0, [sp, #28]
	adds	r0, r0, #1
	str	r0, [sp, #28]
	b	.LBB0_1
.LBB0_8:
	b	.LBB0_9
.LBB0_9:
	ldr	r0, [sp, #36]
	movs	r1, #125
	lsls	r1, r1, #5
	muls	r1, r0, r1
	movs	r0, #100
	@APP
	movs	r2, r1
	movs	r3, r0
	@NO_APP
	ldr	r0, [sp, #100]
	str	r0, [sp, #16]
	b	.LBB0_10
.LBB0_10:
	ldr	r0, [sp, #16]
	str	r0, [sp, #56]
	b	.LBB0_11
.LBB0_11:
	ldr	r0, [sp, #96]
	str	r0, [sp, #12]
	ldr	r0, [sp, #12]
	cmp	r0, #0
	bne	.LBB0_15
	b	.LBB0_12
.LBB0_12:
	b	.LBB0_13
.LBB0_13:
	movs	r0, #48
	str	r0, [sp, #52]
	b	.LBB0_14
.LBB0_14:
	b	.LBB0_27
.LBB0_15:
	movs	r0, #0
	str	r0, [sp, #8]
	str	r0, [sp, #4]
	b	.LBB0_16
.LBB0_16:
	ldr	r0, [sp, #4]
	cmp	r0, #7
	bgt	.LBB0_26
	b	.LBB0_17
.LBB0_17:
	ldr	r0, [sp, #12]
	movs	r1, #15
	ands	r0, r1
	str	r0, [sp]
	ldr	r0, [sp, #12]
	asrs	r0, r0, #4
	str	r0, [sp, #12]
	ldr	r0, [sp, #8]
	cmp	r0, #0
	bne	.LBB0_22
	b	.LBB0_18
.LBB0_18:
	ldr	r0, [sp]
	cmp	r0, #0
	beq	.LBB0_20
	b	.LBB0_19
.LBB0_19:
	movs	r0, #1
	str	r0, [sp, #8]
	b	.LBB0_21
.LBB0_20:
	b	.LBB0_25
.LBB0_21:
	b	.LBB0_22
.LBB0_22:
	b	.LBB0_23
.LBB0_23:
	ldr	r0, [sp]
	adds	r0, #48
	str	r0, [sp, #52]
	b	.LBB0_24
.LBB0_24:
	b	.LBB0_25
.LBB0_25:
	ldr	r0, [sp, #4]
	adds	r0, r0, #1
	str	r0, [sp, #4]
	b	.LBB0_16
.LBB0_26:
	b	.LBB0_27
.LBB0_27:
	b	.LBB0_28
.LBB0_28:
	b	.LBB0_28
.Lfunc_end0:
	.size	run, .Lfunc_end0-run
	.cantunwind
	.fnend


	.ident	"clang version 8.0.0-3~ubuntu18.04.2 (tags/RELEASE_800/final)"
	.section	".note.GNU-stack","",%progbits
	.addrsig
	.eabi_attribute	30, 6
