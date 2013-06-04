/* This file is part of VERTIGO.
 *
 * (C) Copyright 2013, Siege Technologies <http://www.siegetechnologies.com>
 * (C) Copyright 2013, Kirk Swidowski <http://www.swidowski.com>
 *
 * VERTIGO is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * VERTIGO is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with VERTIGO. If not, see <http://www.gnu.org/licenses/>.
 *
 * Written by Kirk Swidowski <kirk@swidowski.com>
 */

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
	result_t result;

	address = (pa.all & ~(TT_SMALL_PAGE_SIZE - 1));
	start.all &= ~(TT_SMALL_PAGE_SIZE - 1);
	end.all &= ~(TT_SMALL_PAGE_SIZE - 1);

	for(*va = start; va->all < end.all; va->all += TT_SMALL_PAGE_SIZE) {

		result = gen_va_to_pa(*va, &tmp);

		if(result == SUCCESS && tmp.all == address) {
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
	par.all = FAILURE;
	gen_set_par(par);

	gen_privileged_read_translation(va);

	// wait for the translation to complete
	// using 0 is concerning because it could
	// be a legitimate translation
	do {
		par = gen_get_par();
	} while(par.all == FAILURE);

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
