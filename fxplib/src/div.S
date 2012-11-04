#include <defines.h>

FUNCTION(__div0)
	mov pc, lr

// these functions were pulled out of
// libgcc.a because the lib in the package
// manager hides them for some reason.
// to extract use the commands below.
// ar -t libgcc.a
// ar -xv libgcc.a _udivsi3.o
FUNCTION(__aeabi_uidiv)
	subs r2, r1, #1
	bxeq lr
	bcc 1f
	cmp r0, r1
	bls 2f
	tst r1, r2
	beq 3f
	clz r3, r1
	clz r2, r0
	sub r2, r3, r2
	mov r3, #1
	lsl r1, r1, r2
	lsl r3, r3, r2
	mov r2, #0
	4:
	cmp r0, r1
	subcs r0, r0, r1
	orrcs r2, r2, r3
	cmp r0, r1, lsr #1
	subcs r0, r0, r1, lsr #1
	orrcs r2, r2, r3, lsr #1
	cmp r0, r1, lsr #2
	subcs r0, r0, r1, lsr #2
	orrcs r2, r2, r3, lsr #2
	cmp r0, r1, lsr #3
	subcs r0, r0, r1, lsr #3
	orrcs r2, r2, r3, lsr #3
	cmp r0, #0
	.word 0x11b03223 // lsrsne  r3, r3, #4
	lsrne r1, r1, #4
	bne 4b
	mov r0, r2
	bx lr
	2:
	moveq r0, #1
	movne r0, #0
	bx lr
	3:
	clz r2, r1
	rsb r2, r2, #31
	lsr r0, r0, r2
	bx lr
	1:
	str lr, [sp, #-8]!
	bl __div0
	mov r0, #0
	ldr pc, [sp], #8

FUNCTION(__aeabi_uidivmod)
	push {r0, r1, lr}
	bl __aeabi_uidiv
	pop {r1, r2, lr}
	mul r3, r2, r0
	sub r1, r1, r3
	bx lr

