#include <config.h>
#include <defines.h>
#include <types.h>

#include <fxplib/gen.h>

void * gen_add_base(void *address) {
	return (void *)((u32_t)address + (u32_t)gen_get_base());
}

void * gen_subtract_base(void *address) {
	return (void *)((u32_t)address) - (u32_t)gen_get_base();
}

