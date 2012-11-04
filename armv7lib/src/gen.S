#include <config.h>
#include <defines.h>
#include <armv7lib/gen.h>

FUNCTION(gen_get_sp)
	mov r0, sp
	mov pc, lr

FUNCTION(gen_set_sp)
	mov sp, r0
	mov pc, lr

FUNCTION(gen_get_cpsr)
	mrs r0, cpsr
	mov pc, lr

FUNCTION(gen_set_cpsr)
	msr cpsr, r0
	mov pc, lr

FUNCTION(gen_get_spsr)
	mrs r0, spsr
	mov pc, lr

FUNCTION(gen_set_spsr)
	msr spsr, r0
	mov pc, lr
