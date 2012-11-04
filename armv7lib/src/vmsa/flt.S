#include <defines.h>

#include <armv7lib/vmsa/flt.h>

FUNCTION(flt_get_dfsr)
	mrc p15, 0, r0, c5, c0, 0
	mov pc, lr

FUNCTION(flt_set_dfsr)
	mcr p15, 0, r0, c5, c0, 0
	mov pc, lr

FUNCTION(flt_get_ifsr)
	mrc p15, 0, r0, c5, c0, 1
	mov pc, lr

FUNCTION(flt_set_ifsr)
	mcr p15, 0, r0, c5, c0, 1
	mov pc, lr

FUNCTION(flt_get_dfar)
	mrc p15, 0, r0, c6, c0, 0
	mov pc, lr

FUNCTION(flt_set_dfar)
	mcr p15, 0, r0, c6, c0, 0

FUNCTION(flt_get_ifar)
	mrc p15, 0, r0, c6, c0, 2
	mov pc, lr

FUNCTION(flt_set_ifar)
	mcr p15, 0, r0, c6, c0, 2
	mov pc, lr
