#include <config.h>
#include <defines.h>

FUNCTION(tlb_get_tlbtr)
	mrc p15, 0, r0, c0, c0, 3
	mov pc, lr

FUNCTION(tlb_invalidate_entire_tlb_inner_shareable)
	mcr p15, 0, r0, c8, c3, 0
	mov pc, lr

FUNCTION(tlb_invalidate_mva_tlb_inner_shareable)
	mcr p15, 0, r0, c8, c3, 1
	mov pc, lr

FUNCTION(tlb_invalidate_entire_unified_tlb)
	mcr p15, 0, r0, c8, c7, 0
	mov pc, lr

FUNCTION(tlb_invalidate_mva_unified_tlb)
	mcr p15, 0, r0, c8, c7, 1
	mov pc, lr
