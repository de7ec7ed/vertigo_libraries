#include <config.h>
#include <defines.h>
#include <types.h>
#include <armv7lib/vmsa/gen.h>
#include <armv7lib/vmsa/tt.h>

// This function should not be used for quick translations as it
// requires a exhaustive search of the page tables with the
// cp15_va_to_pa function
result_t gen_pa_to_va(tt_physical_address_t pa, tt_virtual_address_t start, tt_virtual_address_t end, tt_virtual_address_t *va) {

	tt_physical_address_t tmp;
	u32_t address;

	*va = start;

	address = (pa.all & ~(TT_SMALL_PAGE_SIZE - 1));
	start.all &= ~(TT_SMALL_PAGE_SIZE - 1);
	end.all &= ~(TT_SMALL_PAGE_SIZE - 1);

	for(*va = start; va->all < end.all; va->all += TT_SMALL_PAGE_SIZE) {

		gen_va_to_pa(*va, &tmp);

		if(tmp.all == address) {
			va->all |= (pa.all & (TT_SMALL_PAGE_SIZE - 1));
			return SUCCESS;
		}
	}

	va->all = (u32_t)NULL;

	return FAILURE;
}

result_t gen_va_to_pa(tt_virtual_address_t va, tt_physical_address_t *pa) {

	gen_physical_address_register_t par;

	// clear the par so a stale result is not returned
	par.all = 0;
	gen_set_par(par);

	gen_privileged_read_translation(va);

	// wait for the translation to complete
	// using 0 is concerning because it could
	// be a legitimate translation
	do {
		par = gen_get_par();
	} while(par.all == 0);

	if(par.fields.f == TRUE) {
		pa->all = (u32_t)NULL;
		return FAILURE;
	}
	else if(par.fields.ss == TRUE) {
		// TODO: add logic to construct the pa
		// on systems which support physical memory
		// above the 32-bit address space.
		pa->all = (((u32_t)(par.fields.pa)) << FOUR_KILOBYTE_BIT_SHIFT);
		pa->all &= ~SIXTEEN_MEGABYTE_MASK;
		pa->all |= (va.all & SIXTEEN_MEGABYTE_MASK);
	}
	else {
		pa->all = (((u32_t)(par.fields.pa)) << FOUR_KILOBYTE_BIT_SHIFT);
		pa->all |= (va.all & FOUR_KILOBYTE_MASK);
	}

	return SUCCESS;
}
