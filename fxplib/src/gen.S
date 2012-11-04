#include <config.h>
#include <defines.h>

FUNCTION(gen_get_base)
	mov r1, lr
	bl 1f
	1:
	ldr r0, =1b
	sub r0, lr, r0
	mov pc, r1
