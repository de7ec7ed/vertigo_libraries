#include <config.h>
#include <defines.h>
#include <armv7lib/cmsa/bpa.h>

FUNCTION(bpa_flush_mva_branch_predictor_array)
	mcr p15, 0, r0, c7, c5, 7
	mov pc, lr

FUNCTION(bpa_flush_entire_branch_predictor_array)
	mcr p15, 0, r0, c7, c1, 6
	mov pc, lr
