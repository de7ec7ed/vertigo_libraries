#include <config.h>
#include <defines.h>
#include <armv7lib/int.h>

FUNCTION(int_disable_irq)
	mrs r0, cpsr
	orr r0,r0,#0x80
	msr cpsr, r0
	mov pc, lr

FUNCTION(int_enable_irq)
	mrs r0, cpsr
	bic r0,r0,#0x80
	msr cpsr, r0
	mov pc, lr

FUNCTION(int_disable_fiq)
	mrs r0, cpsr
	orr r0,r0,#0x40
	msr cpsr, r0
	mov pc, lr

FUNCTION(int_enable_fiq)
	mrs r0, cpsr
	bic r0,r0,#0x40
	msr cpsr, r0
	mov pc, lr
