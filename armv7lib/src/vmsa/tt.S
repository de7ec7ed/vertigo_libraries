#include <config.h>
#include <defines.h>
#include <armv7lib/vmsa/tt.h>

FUNCTION(tt_get_ttbr0)
	mrc p15, 0, r0, c2, c0, 0 // Translation Table Base Register 0
	mov pc, lr

FUNCTION(tt_get_ttbr1)
	mrc p15, 0, r0, c2, c0, 1 // Translation Table Base Register 1
	mov pc, lr

FUNCTION(tt_get_ttbcr)
	mrc p15, 0, r0, c2, c0, 2 // Translation Table Control Register
	mov pc, lr

FUNCTION(tt_set_ttbr0)
	mcr p15, 0, r0, c2, c0, 0 // Translation Table Base Register 0
	mov pc, lr

FUNCTION(tt_set_ttbr1)
	mcr p15, 0, r0, c2, c0, 1 // Translation Table Base Register 1
	mov pc, lr

FUNCTION(tt_set_ttbcr)
	mcr p15, 0, r0, c2, c0, 2 // Translation Table Control Register
	mov pc, lr
