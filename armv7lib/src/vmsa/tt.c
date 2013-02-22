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

#include <armv7lib/config.h>
#include <defines.h>
#include <types.h>
#include <armv7lib/vmsa/tt.h>
#include <armv7lib/vmsa/gen.h>
#include <stdlib/check.h>
#include <stdlib/string.h>

result_t tt_get_fld(tt_virtual_address_t va, tt_virtual_address_t l1, tt_first_level_descriptor_t *fld) {

	tt_first_level_descriptor_t *table;

	CHECK_NOT_NULL(l1.all, "l1 is null", NULL, NULL, NULL)
		return FAILURE;
	CHECK_END

	CHECK_NOT_NULL(fld, "fld is null", NULL, NULL, NULL)
		return FAILURE;
	CHECK_END

	table = (tt_first_level_descriptor_t *)l1.all;

	memcpy(fld, &(table[va.page_table.fields.l1_index]), sizeof(tt_first_level_descriptor_t));

	return SUCCESS;
}

result_t tt_set_fld(tt_virtual_address_t va, tt_virtual_address_t l1, tt_first_level_descriptor_t fld) {

	tt_first_level_descriptor_t *table;

	CHECK_NOT_NULL(l1.all, "l1 is null", NULL, NULL, NULL)
		return FAILURE;
	CHECK_END

	table = (tt_first_level_descriptor_t *)l1.all;

	memcpy(&(table[va.page_table.fields.l1_index]), &fld, sizeof(tt_first_level_descriptor_t));

	return SUCCESS;
}

result_t tt_get_sld(tt_virtual_address_t va, tt_virtual_address_t l2, tt_second_level_descriptor_t *sld) {

	tt_second_level_descriptor_t *table;

	CHECK_NOT_NULL(l2.all, "l2 is null", NULL, NULL, NULL)
		return FAILURE;
	CHECK_END

	CHECK_NOT_NULL(sld, "sld is null", NULL, NULL, NULL)
		return FAILURE;
	CHECK_END

	table = (tt_second_level_descriptor_t *)l2.all;

	memcpy(sld, &(table[va.page_table.fields.l2_index]), sizeof(tt_second_level_descriptor_t));

	return SUCCESS;
}

result_t tt_set_sld(tt_virtual_address_t va, tt_virtual_address_t l2, tt_second_level_descriptor_t sld) {

	tt_second_level_descriptor_t *table;

	CHECK_NOT_NULL(l2.all, "l2 is null", NULL, NULL, NULL)
		return FAILURE;
	CHECK_END

	table = (tt_second_level_descriptor_t *)l2.all;

	memcpy(&(table[va.page_table.fields.l2_index]), &sld, sizeof(tt_second_level_descriptor_t));

	return SUCCESS;
}

result_t tt_fld_to_pa(tt_first_level_descriptor_t fld, tt_physical_address_t *pa) {

	CHECK_FALSE(tt_fld_is_not_present(fld), "fld is not present", NULL, NULL, NULL)
		return FAILURE;
	CHECK_END

	if(tt_fld_is_supersection(fld) == TRUE) {
		pa->all = ((size_t)fld.supersection.fields.pa_2) << SIXTEEN_MEGABYTE_BIT_SHIFT;
	}
	else if(tt_fld_is_section(fld) == TRUE) {
		pa->all = ((size_t)fld.section.fields.pa) << ONE_MEGABYTE_BIT_SHIFT;
	}
	else if(tt_fld_is_page_table(fld) == TRUE) {
		pa->all = ((size_t)fld.page_table.fields.pa) << ONE_KILOBYTE_BIT_SHIFT;
	}
	else {
		pa->all = (u32_t)NULL;
		return FAILURE;
	}

	return SUCCESS;
}

result_t tt_sld_to_pa(tt_second_level_descriptor_t sld, tt_physical_address_t *pa) {

	CHECK_FALSE(tt_sld_is_not_present(sld), "sld is not present", NULL, NULL, NULL)
		return FAILURE;
	CHECK_END

	if(tt_sld_is_large_page(sld) == TRUE) {
		pa->all = ((size_t)sld.large_page.fields.pa) << SIXTY_FOUR_KILOBYTE_BIT_SHIFT;
	}
	else if(tt_sld_is_small_page(sld) == TRUE) {
		pa->all = ((size_t)sld.small_page.fields.pa) << FOUR_KILOBYTE_BIT_SHIFT;
	}
	else {
		pa->all = (u32_t)NULL;
		return FAILURE;
	}

	return SUCCESS;
}

result_t tt_pa_to_fld(tt_physical_address_t pa, tt_first_level_descriptor_t *fld) {

	CHECK_FALSE(tt_fld_is_not_present(*fld), "fld is not present", NULL, NULL, NULL)
		return FAILURE;
	CHECK_END

	if(tt_fld_is_supersection(*fld) == TRUE) {
		// TODO: something with pa_0 and systems that support pa's larger than 32 bits
		fld->supersection.fields.pa_1 = (pa.all >> SIXTEEN_MEGABYTE_BIT_SHIFT);
	}
	else if(tt_fld_is_section(*fld) == TRUE) {
		fld->section.fields.pa = (pa.all >> ONE_MEGABYTE_BIT_SHIFT);
	}
	else if(tt_fld_is_page_table(*fld) == TRUE) {
		fld->page_table.fields.pa = (pa.all >> ONE_KILOBYTE_BIT_SHIFT);
	}
	else {
		return FAILURE;
	}

	return SUCCESS;
}

result_t tt_pa_to_sld(tt_physical_address_t pa, tt_second_level_descriptor_t *sld) {

	CHECK_FALSE(tt_sld_is_not_present(*sld), "sld is not present", NULL, NULL, NULL)
		return FAILURE;
	CHECK_END

	if(tt_sld_is_large_page(*sld) == TRUE) {
		sld->large_page.fields.pa = (pa.all >> SIXTY_FOUR_KILOBYTE_BIT_SHIFT);
	}
	else if(tt_sld_is_small_page(*sld) == TRUE) {
		sld->small_page.fields.pa = (pa.all >> FOUR_KILOBYTE_BIT_SHIFT);
	}
	else {
		return FAILURE;
	}

	return SUCCESS;
}

bool_t tt_fld_is_supersection(tt_first_level_descriptor_t fld) {

	if((fld.all & TT_SUPERSECTION_AND_SECTION_TYPE_MASK) == TT_SUPERSECTION_TYPE) {
		return TRUE;
	}

	return FALSE;
}

bool_t tt_fld_is_section(tt_first_level_descriptor_t fld) {

	if((fld.all & TT_SUPERSECTION_AND_SECTION_TYPE_MASK) == TT_SECTION_TYPE) {
		return TRUE;
	}

	return FALSE;
}

bool_t tt_fld_is_page_table(tt_first_level_descriptor_t fld) {

	if((fld.all & TT_PAGE_TABLE_AND_NOT_PRESENT_TYPE_MASK) == TT_PAGE_TABLE_TYPE) {
		return TRUE;
	}

	return FALSE;
}

bool_t tt_fld_is_not_present(tt_first_level_descriptor_t fld) {

	if((fld.all & TT_PAGE_TABLE_AND_NOT_PRESENT_TYPE_MASK) == TT_NOT_PRESENT_TYPE) {
		return TRUE;
	}

	return FALSE;
}

bool_t tt_sld_is_large_page(tt_second_level_descriptor_t sld) {

	if((sld.all & TT_LARGE_PAGE_AND_NOT_PRESENT_TYPE_MASK) == TT_LARGE_PAGE_TYPE) {
		return TRUE;
	}

	return FALSE;
}

bool_t tt_sld_is_small_page(tt_second_level_descriptor_t sld) {

	if((sld.all & TT_SMALL_PAGE_TYPE_MASK) == TT_SMALL_PAGE_TYPE) {
		return TRUE;
	}

	return FALSE;
}

bool_t tt_sld_is_not_present(tt_second_level_descriptor_t sld) {

	if((sld.all & TT_LARGE_PAGE_AND_NOT_PRESENT_TYPE_MASK) == TT_NOT_PRESENT_TYPE) {
		return TRUE;
	}

	return FALSE;
}

result_t tt_select_ttbr(tt_virtual_address_t va, tt_translation_table_base_register_t ttbr0, tt_translation_table_base_register_t ttbr1, tt_translation_table_base_control_register_t ttbcr, tt_translation_table_base_register_t *ttbr) {

	CHECK_NOT_NULL(ttbr, "ttbr is null", NULL, NULL, NULL)
		return FAILURE;
	CHECK_END

	if(ttbcr.fields.n == 0) {
		ttbr->all = ttbr0.all;
	}
	else if(va.all & (~0 << (BITS_PER_LONG - ttbcr.fields.n))) {
		ttbr->all = ttbr1.all;
	}
	else {
		ttbr->all = ttbr0.all;
	}

	return SUCCESS;
}

result_t tt_ttbr_to_pa(tt_translation_table_base_register_t ttbr, tt_physical_address_t *pa) {

	CHECK_NOT_NULL(pa, "pa is null", NULL, NULL, NULL)
		return FAILURE;
	CHECK_END

	pa->all = (((size_t)ttbr.fields.pa) << 8);

	return SUCCESS;
}

result_t tt_pa_to_ttbr(tt_physical_address_t pa, tt_translation_table_base_register_t *ttbr) {

	CHECK_NOT_NULL(ttbr, "ttbr is null", NULL, NULL, NULL)
		return FAILURE;
	CHECK_END

	ttbr->fields.pa = (pa.all >> 8);

	return SUCCESS;
}
