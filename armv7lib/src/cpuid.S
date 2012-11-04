#include <config.h>
#include <defines.h>
#include <armv7lib/cpuid.h>

FUNCTION(cpuid_get_midr)
	mrc p15, 0, r0, c0, c0, 0
	mov pc, lr
