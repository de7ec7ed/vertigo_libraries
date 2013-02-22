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

/**
 * @file
 *
 * @brief API for the translation tables in the VMSA of the ARMv7 architecture.
 *
 * @details Includes functions, data structures and unions.
 */

#ifndef __VMSA_TT_H__
#define __VMSA_TT_H__

#include <defines.h>
#include <types.h>

#define TT_NUMBER_LEVEL_1_ENTRIES   4096 ///< The number of entries in a level 1 table.
#define TT_NUMBER_LEVEL_2_ENTRIES   256  ///< The number of entries in a level 2 table.

#define TT_NUMBER_SUPERSECTION_ENTRIES 16 ///< The number of entries that must be duplicated in a level 1 table to create a supersection.
#define TT_NUMBER_LARGE_PAGE_ENTRIES   16 ///< The number of entries that must be duplicated in a level 2 table to create a large page.

#define TT_SUPERSECTION_SIZE (16 * ONE_MEGABYTE)   ///< The size of a supersection.
#define TT_SECTION_SIZE      ONE_MEGABYTE          ///< The size of a section.
#define TT_LARGE_PAGE_SIZE   (16 * FOUR_KILOBYTES) ///< The size of a large page.
#define TT_SMALL_PAGE_SIZE   FOUR_KILOBYTES        ///< The size of a small page.

#define TT_SUPERSECTION_AND_SECTION_TYPE_MASK    0x00040003 ///< A mask to isolate the type bits for a supersection and section entry.
#define TT_PAGE_TABLE_AND_NOT_PRESENT_TYPE_MASK  0x00000003 ///< A mask to isolate the type bits for a page table and not present entry.
#define TT_LARGE_PAGE_AND_NOT_PRESENT_TYPE_MASK  0x00000003 ///< A mask to isolate the type bits for a large page and not present entry.
#define TT_SMALL_PAGE_TYPE_MASK                  0x00000002 ///< A mask to isolate the type bits for a small page entry.

#define TT_SUPERSECTION_TYPE      0x00040002 ///< A supersection entry type.
#define TT_SECTION_TYPE           0x00000002 ///< A section entry type.
#define TT_PAGE_TABLE_TYPE        0x00000001 ///< A page table entry type.
#define TT_LARGE_PAGE_TYPE        0x00000001 ///< A large page entry type.
#define TT_SMALL_PAGE_TYPE        0x00000002 ///< A small page entry type.
#define TT_NOT_PRESENT_TYPE       0x00000000 ///< A not present entry type.

// AP 1 is FALSE for the following AP 0's
#define TT_AP_0_AP_1_F_S_NA_U_NA 0x0 ///< Access permissions 1 false, supervisor not accessible and user no access.
#define TT_AP_0_AP_1_F_S_RW_U_NA 0x1 ///< Access permissions 1 false, supervisor readable/writable and user no access.
#define TT_AP_0_AP_1_F_S_RW_U_RO 0x2 ///< Access permissions 1 false, supervisor readable/writable and user read only.
#define TT_AP_0_AP_1_F_S_RW_U_RW 0x3 ///< Access permissions 1 false, supervisor readable/writable and user readable/writable.

// AP 1 is TRUE for the following AP 0's
#define TT_AP_0_AP_1_T_S_RS_U_RS     0x0 ///< Access permissions 1 true, supervisor reserved and user reserved.
#define TT_AP_0_AP_1_T_S_RO_U_NA     0x1 ///< Access permissions 1 true, supervisor read only and user no access.
#define TT_AP_0_AP_1_T_S_RO_U_RO_DEP 0x2 ///< Access permissions 1 true, supervisor read only and user read only (deprecated).
#define TT_AP_0_AP_1_T_S_RO_U_RO     0x3 ///< Access permissions 1 true, supervisor read only and user read only.

#define TT_RGN_O_NC      0x0 ///< Translation table base register region normal memory, outer non-cacheable.
#define TT_RGN_O_WB_WAC  0x1 ///< Translation table base register region normal memory, outer write-back, write-allocate and cacheable
#define TT_RGN_O_WTC     0x2 ///< Translation table base register region normal memory, outer write-through, cacheable
#define TT_RGB_0_WB_NWAC 0x3 ///< Translation table base register region, normal memory, outer write-back, no write-allocate, cacheable.

#ifdef __C__

typedef union tt_translation_table_base_register tt_translation_table_base_register_t;
typedef union tt_translation_table_base_control_register tt_translation_table_base_control_register_t;

typedef union tt_first_level_descriptor tt_first_level_descriptor_t;
typedef union tt_page_table tt_page_table_t;
typedef union tt_section tt_section_t;
typedef union tt_supersection tt_supersection_t;

typedef union tt_second_level_descriptor tt_second_level_descriptor_t;
typedef union tt_large_page tt_large_page_t;
typedef union tt_small_page tt_small_page_t;

typedef union tt_virtual_address tt_virtual_address_t;
typedef union tt_supersection_virtual_address tt_supersection_virtual_address_t;
typedef union tt_section_virtual_address tt_section_virtual_address_t;
typedef union tt_page_table_virtual_address tt_page_table_virtual_address_t;
typedef union tt_large_page_virtual_address tt_large_page_virtual_address_t;
typedef union tt_small_page_virtual_address tt_small_page_virtual_address_t;

typedef union tt_physical_address tt_physical_address_t;
typedef union tt_supersection_physical_address tt_supersection_physical_address_t;
typedef union tt_section_physical_address tt_section_physical_address_t;
typedef union tt_large_page_physical_address tt_large_page_physical_address_t;
typedef union tt_small_page_physical_address tt_small_page_physical_address_t;

union tt_translation_table_base_register {
	struct {
		u32_t irgn_1     :1;  ///< Inner region bits. Indicates the Inner Cacheability attributes for the memory associated with the translation table walks.
		u32_t c          :1;  ///< Cacheable bit. Indicates whether the translation table walk is to Inner Cacheable memory.
		u32_t s          :1;  ///< Sharable bit. Indicates the shareable attribute for the memory assocated with the translation table walks.
		u32_t imp_def_0  :1;  ///< Implementation defined.
		u32_t rgn        :2;  ///< Region bits. Indicates the Outer Cacheability attributes for the memory associated with the translation table walks.
		u32_t nos        :1;  ///< Not Outer Shareable bit. Indicates the Outer Sharable attribute for the memory associated with a translation table walk that has the Shareable attribute, indicated by TTBR0.S = 1.
		u32_t irgn_0     :1;  ///< See the description of bit [0] when the Multiprocessing Extensions are implemented.
		u32_t pa         :24; ///< Translation table base X address.
	} fields;
	size_t all;
};

union tt_translation_table_base_control_register {
	struct {
		u32_t n     :3; ///< Indicate the width of the base address held in ttbr0.
		u32_t sbz_0 :1;
		u32_t pd_0  :1; ///< Translation table walk disable bit for ttbr0.
		u32_t pd_1  :1; ///< Translation table walk disable bit for ttbr1.
	} fields;
	u32_t all;
};

union tt_page_table {
	struct {
		u32_t type_0    :2;  ///< Type is 0x1 for a page table.
		u32_t sbz_0     :1;  ///< Should be zero.
		u32_t ns        :1;  ///< Non-secure bit.
		u32_t sbz_1     :1;  ///< Should be zero.
		u32_t domain    :4;  ///< Domain field.
		u32_t imp_def_0 :1;  ///< Implementation defined.
		u32_t pa        :22; ///< Page table base address [31:10].
	} fields;
	u32_t all;
};

union tt_section {
	struct {
		u32_t type_0    :2;  ///< Type is 0x2 for a section.
		u32_t b         :1;  ///< Bufferable.
		u32_t c         :1;  ///< Cacheable.
		u32_t xn        :1;  ///< Execute never.
		u32_t domain    :4;  ///< Domain field.
		u32_t imp_def_0 :1;  ///< Implementation defined.
		u32_t ap_0      :2;  ///< Access permissions bits 0.
		u32_t tex       :3;  ///< Memory region attribute bits.
		u32_t ap_1      :1;  ///< Access permissions bits 1.
		u32_t s         :1;  ///< Shareable bit.
		u32_t ng        :1;  ///< Not global.
		u32_t type_1    :1;  ///< Type is 0x0 for a section.
		u32_t ns        :1;  ///< Non-secure bit.
		u32_t pa        :12; ///< Section base address [31:20].
	} fields;
	u32_t all;
};

union tt_supersection {
	struct {
		u32_t type_0    :2;  ///< Type is 0x2 for a supersection.
		u32_t b         :1;  ///< Bufferable.
		u32_t c         :1;  ///< Cacheable.
		u32_t xn        :1;  ///< Execute never.
		u32_t pa_0      :4;  ///< Extended base address [39:36].
		u32_t imp_def_0 :1;  ///< Implementation defined.
		u32_t ap_0      :2;  ///< Access permissions bits 0.
		u32_t tex       :3;  ///< Memory region attribute bits.
		u32_t ap_1      :1;  ///< Access permissions bits 1.
		u32_t s         :1;  ///< Shareable bit.
		u32_t ng        :1;  ///< Not global.
		u32_t type_1    :1;  ///< Type is 0x1 for a supersection.
		u32_t ns        :1;  ///< Non-secure bit.
		u32_t pa_1      :4;  ///< Extended base address [32:35].
		u32_t pa_2      :8;  ///< Supersection base address [31:24].
	} fields;
	u32_t all;
};

union tt_first_level_descriptor {
	tt_supersection_t supersection;
	tt_section_t section;
	tt_page_table_t page_table;
	u32_t all;
};

union tt_large_page {
	struct {
		u32_t type     :2;  ///< Type is 0x1 for a large page.
		u32_t b        :1;  ///< Bufferable.
		u32_t c        :1;  ///< Cacheable.
		u32_t ap_0     :2;  ///< Access permissions bits 0.
		u32_t sbz_0    :3;  ///< Should be zero.
		u32_t ap_1     :1;  ///< Access permissions bits 1.
		u32_t s        :1;  ///< Shareable bit.
		u32_t ng       :1;  ///< Not global.
		u32_t tex      :3;  ///< Memory region attribute bits.
		u32_t xn       :1;  ///< Execute never.
		u32_t pa       :16; ///< large page base address [31:16].
	} fields;
	u32_t all;
};

union tt_small_page {
	struct {
		u32_t xn       :1;  ///< Execute never.
		u32_t type     :1;  ///< Type is 0x1 for a small page.
		u32_t b        :1;  ///< Bufferable.
		u32_t c        :1;  ///< Cacheable.
		u32_t ap_0     :2;  ///< Access permissions bits 0.
		u32_t tex      :3;  ///< Memory region attribute bits.
		u32_t ap_1     :1;  ///< Access permissions bits 1.
		u32_t s        :1;  ///< Shareable bit.
		u32_t ng       :1;  ///< Not global.
		u32_t pa       :20; ///< small page base address [31:12].
	} fields;
	u32_t all;
};

union tt_second_level_descriptor {
	tt_large_page_t large_page;
	tt_small_page_t small_page;
	u32_t all;
};

union tt_supersection_virtual_address {
	struct {
		u32_t offset        :24;
		u32_t unused_0      :8;
	} fields;
	u32_t all;
};

union tt_section_virtual_address {
	struct {
		u32_t offset        :20;
		u32_t unused_0      :12;
	} fields;
	u32_t all;
};

union tt_page_table_virtual_address {
	struct {
		u32_t unused_0       :12;
		u32_t l2_index       :8;
		u32_t l1_index       :12;
	} fields;
	u32_t all;
};

union tt_large_page_virtual_address {
	struct {
		u32_t offset     :16;
		u32_t unused_0   :16;
	} fields;
	u32_t all;
};

union tt_small_page_virtual_address {
	struct {
		u32_t offset     :12;
		u32_t unused_0   :20;
	} fields;
	u32_t all;
};

union tt_virtual_address {
	tt_supersection_virtual_address_t supersection;
	tt_section_virtual_address_t section;
	tt_page_table_virtual_address_t page_table;
	tt_large_page_virtual_address_t large_page;
	tt_small_page_virtual_address_t small_page;
	u32_t all;
};

union tt_supersection_physical_address {
	struct {
		u32_t offset :24;
		u32_t base   :8;
	} fields;
	u32_t all;
};

union tt_section_physical_address {
	struct {
		u32_t offset :20;
		u32_t base   :12;
	} fields;
	u32_t all;
};

union tt_large_page_physical_address {
	struct {
		u32_t offset :16;
		u32_t base   :16;
	} fields;
	u32_t all;
};

union tt_small_page_physical_address {
	struct {
		u32_t offset :12;
		u32_t base   :20;
	} fields;
	u32_t all;
};

union tt_physical_address {
	tt_supersection_physical_address_t supersection;
	tt_section_physical_address_t section;
	tt_large_page_physical_address_t large_page;
	tt_small_page_physical_address_t small_page;
	u32_t all;
};

/**
 * @name    tt_get_fld
 * @brief   Get a first level descriptor
 *
 * @details Provides the ability to get a first level descriptor from a first level table.
 *
 * @param tt_virtual_address_t va
 * @param tt_virtual_address_t l1
 * @param tt_first_level_descriptor_t *fld
 * @retval result_t
 *
 * Example Usage:
 * @code
 *    if(tt_get_fld(va, l1, &fld) != SUCCESS)
 * @endcode
 */
extern result_t tt_get_fld(tt_virtual_address_t va, tt_virtual_address_t l1, tt_first_level_descriptor_t *fld);

/**
 * @name    tt_set_fld
 * @brief   Set a first level descriptor
 *
 * @details Provides the ability to set a first level descriptor from a first level table.
 *
 * @param tt_virtual_address_t va
 * @param tt_virtual_address_t l1
 * @param tt_first_level_descriptor_t fld
 * @retval result_t
 *
 * Example Usage:
 * @code
 *    if(tt_get_fld(va, l1, fld) != SUCCESS)
 * @endcode
 */
extern result_t tt_set_fld(tt_virtual_address_t va, tt_virtual_address_t l1, tt_first_level_descriptor_t fld);

/**
 * @name    tt_set_sld
 * @brief   Get a second level descriptor
 *
 * @details Provides the ability to get a second level descriptor from a second level table.
 *
 * @param tt_virtual_address_t va
 * @param tt_virtual_address_t l1
 * @param tt_second_level_descriptor_t *sld
 * @retval result_t
 *
 * Example Usage:
 * @code
 *    if(tt_get_sld(va, l1, &sld) != SUCCESS)
 * @endcode
 */
extern result_t tt_get_sld(tt_virtual_address_t va, tt_virtual_address_t l2, tt_second_level_descriptor_t *sld);

/**
 * @name    tt_set_sld
 * @brief   Set a second level descriptor
 *
 * @details Provides the ability to set a second level descriptor from a second level table.
 *
 * @param tt_virtual_address_t va
 * @param tt_virtual_address_t l1
 * @param tt_second_level_descriptor_t sld
 * @retval result_t
 *
 * Example Usage:
 * @code
 *    if(tt_set_sld(va, l1, sld) != SUCCESS)
 * @endcode
 */
extern result_t tt_set_sld(tt_virtual_address_t va, tt_virtual_address_t l2, tt_second_level_descriptor_t sld);

/**
 * @name    tt_fld_to_pa
 * @brief   Convert a first level descriptor to a physical address.
 *
 * @details Provides the ability to convert a first level descriptor to a physical address. It will take into
 * account the different types of table entries.
 *
 * @param tt_first_level_descriptor_t fld
 * @param tt_physical_address_t *pa
 *
 * @retval result_t
 *
 * Example Usage:
 * @code
 *    if(tt_fld_to_pa(fld,&pa) != SUCCESS)
 * @endcode
 */
extern result_t tt_fld_to_pa(tt_first_level_descriptor_t fld, tt_physical_address_t *pa);

/**
 * @name    tt_sld_to_pa
 * @brief   Convert a second level descriptor to a physical address.
 *
 * @details Provides the ability to convert a second level descriptor to a physical address. It will take into
 * account the different types of table entries.
 *
 * @param tt_second_level_descriptor_t sld
 * @param tt_physical_address_t *pa
 *
 * @retval result_t
 *
 * Example Usage:
 * @code
 *    if(tt_sld_to_pa(fld,&pa) != SUCCESS)
 * @endcode
 */
extern result_t tt_sld_to_pa(tt_second_level_descriptor_t sld, tt_physical_address_t *pa);

/**
 * @name    tt_pa_to_fld
 * @brief   Convert a physical address to a first level descriptor.
 *
 * @details Provides the ability to convert a physical address to a first level descriptor. It will take into
 * account the different types of table entries.
 *
 * @param tt_physical_address_t pa
 * @param tt_first_level_descriptor_t *fld
 *
 * @retval result_t
 *
 * Example Usage:
 * @code
 *    if(tt_pa_to_fld(pa. &fld) != SUCCESS)
 * @endcode
 */
extern result_t tt_pa_to_fld(tt_physical_address_t pa, tt_first_level_descriptor_t *fld);

/**
 * @name    tt_pa_to_sld
 * @brief   Convert a physical address to a second level descriptor.
 *
 * @details Provides the ability to convert a physical address to a second level descriptor. It will take into
 * account the different types of table entries.
 *
 * @param tt_physical_address_t pa
 * @param tt_second_level_descriptor_t *sld
 *
 * @retval result_t
 *
 * Example Usage:
 * @code
 *    if(tt_pa_to_sld(pa. &sld) != SUCCESS)
 * @endcode
 */
extern result_t tt_pa_to_sld(tt_physical_address_t pa, tt_second_level_descriptor_t *sld);

/**
 * @name    tt_fld_is_supersection
 * @brief   Check to see if a first level descriptor is a supersection.
 *
 * @details Provides the ability to see if a first level descriptor is a supersection.
 *
 * @param tt_first_level_descriptor_t fld
 *
 * @retval bool_t
 *
 * Example Usage:
 * @code
 *    if(tt_fld_is_supersection(fld) == FALSE)
 * @endcode
 */
extern bool_t tt_fld_is_supersection(tt_first_level_descriptor_t fld);

/**
 * @name    tt_fld_is_section
 * @brief   Check to see if a first level descriptor is a section.
 *
 * @details Provides the ability to see if a first level descriptor is a section.
 *
 * @param tt_first_level_descriptor_t fld
 *
 * @retval bool_t
 *
 * Example Usage:
 * @code
 *    if(tt_fld_is_section(fld) == FALSE)
 * @endcode
 */
extern bool_t tt_fld_is_section(tt_first_level_descriptor_t fld);

/**
 * @name    tt_fld_is_page_table
 * @brief   Check to see if a first level descriptor is a page table.
 *
 * @details Provides the ability to see if a first level descriptor is a page table.
 *
 * @param tt_first_level_descriptor_t fld
 *
 * @retval bool_t
 *
 * Example Usage:
 * @code
 *    if(tt_fld_is_page_table(fld) == FALSE)
 * @endcode
 */
extern bool_t tt_fld_is_page_table(tt_first_level_descriptor_t fld);

/**
 * @name    tt_fld_is_not_present
 * @brief   Check to see if a first level descriptor is not present.
 *
 * @details Provides the ability to see if a first level descriptor is not present.
 *
 * @param tt_first_level_descriptor_t fld
 *
 * @retval bool_t
 *
 * Example Usage:
 * @code
 *    if(tt_fld_is_not_present(fld) == TRUE)
 * @endcode
 */
extern bool_t tt_fld_is_not_present(tt_first_level_descriptor_t fld);

/**
 * @name    tt_sld_is_large_page
 * @brief   Check to see if a second level descriptor is a large page.
 *
 * @details Provides the ability to see if a second level descriptor is a large page.
 *
 * @param tt_second_level_descriptor_t sld
 *
 * @retval bool_t
 *
 * Example Usage:
 * @code
 *    if(tt_sld_is_large_page(sld) == FALSE)
 * @endcode
 */
extern bool_t tt_sld_is_large_page(tt_second_level_descriptor_t sld);

/**
 * @name    tt_sld_is_small_page
 * @brief   Check to see if a second level descriptor is a small page.
 *
 * @details Provides the ability to see if a second level descriptor is a small page.
 *
 * @param tt_second_level_descriptor_t sld
 *
 * @retval bool_t
 *
 * Example Usage:
 * @code
 *    if(tt_sld_is_small_page(sld) == FALSE)
 * @endcode
 */
extern bool_t tt_sld_is_small_page(tt_second_level_descriptor_t sld);

/**
 * @name    tt_sld_is_not_present
 * @brief   Check to see if a second level descriptor is not present.
 *
 * @details Provides the ability to see if a second level descriptor is not present.
 *
 * @param tt_second_level_descriptor_t sld
 *
 * @retval bool_t
 *
 * Example Usage:
 * @code
 *    if(tt_sld_is_not_present(sld) == FALSE)
 * @endcode
 */
extern bool_t tt_sld_is_not_present(tt_second_level_descriptor_t sld);

/**
 * @name    tt_select_ttbr
 * @brief   Select the correct ttbr based on the va and ttbcr.
 *
 * @details Provides the ability to select the correct translation table base register
 * based on the virtual address and the translation table base control register.
 *
 * @param tt_virtual_address_t va
 * @param tt_translation_table_base_register_t ttbr0
 * @param tt_translation_table_base_register_t ttbr1
 * @param tt_translation_table_base_control_register_t ttbcr
 * @param tt_translation_table_base_register_t *ttbr
 *
 * @retval result_t
 *
 * Example Usage:
 * @code
 *    if(tt_select_ttbr(va, ttbr0, ttbr1, ttbcr, &ttbr) != SUCCESS)
 * @endcode
 */
extern result_t tt_select_ttbr(tt_virtual_address_t va, tt_translation_table_base_register_t ttbr0, tt_translation_table_base_register_t ttbr1, tt_translation_table_base_control_register_t ttbcr, tt_translation_table_base_register_t *ttbr);

/**
 * @name    tt_ttbr_to_pa
 * @brief   Convert a translation table base register to a physical address.
 *
 * @details Provides the ability to convert a translation table base register to a physical address.
 *
 * @param tt_translation_table_base_register_t ttbr
 * @param tt_physical_address_t *pa
 *
 * @retval result_t
 *
 * Example Usage:
 * @code
 *    if(tt_ttbr_to_pa(ttbr, &pa) != SUCCESS)
 * @endcode
 */
extern result_t tt_ttbr_to_pa(tt_translation_table_base_register_t ttbr, tt_physical_address_t *pa);

/**
 * @name    tt_pa_to_ttbr
 * @brief   Convert a physical address to a translation table base register.
 *
 * @details Provides the ability to convert a physical address to a translation table base register.
 *
 * @param tt_physical_address_t pa
 * @param tt_translation_table_base_register_t *ttbr
 *
 * @retval result_t
 *
 * Example Usage:
 * @code
 *    if(tt_pa_to_ttbr(pa, &ttbr) != SUCCESS)
 * @endcode
 */
extern result_t tt_pa_to_ttbr(tt_physical_address_t pa, tt_translation_table_base_register_t *ttbr);

/**
 * @name    tt_get_ttbr0
 * @brief   Get the translation table base 0 register.
 *
 * @details Provides the ability to get the translation table base 0 register.
 *
 * @retval tt_translation_table_base_register_t
 *
 * Example Usage:
 * @code
 *    ttbr0 = tt_get_ttbr0();
 * @endcode
 */
extern tt_translation_table_base_register_t tt_get_ttbr0(void);

/**
 * @name    tt_get_ttbr1
 * @brief   Get the translation table base 1 register.
 *
 * @details Provides the ability to get the translation table base 1 register.
 *
 * @retval tt_translation_table_base_register_t
 *
 * Example Usage:
 * @code
 *    ttbr1 = tt_get_ttbr1();
 * @endcode
 */
extern tt_translation_table_base_register_t tt_get_ttbr1(void);

/**
 * @name    tt_get_ttbcr
 * @brief   Get the translation table base control register.
 *
 * @details Provides the ability to get the translation table base control register.
 *
 * @retval tt_translation_table_base_control_register_t
 *
 * Example Usage:
 * @code
 *    ttbcr = tt_get_ttbcr();
 * @endcode
 */
extern tt_translation_table_base_control_register_t tt_get_ttbcr(void);

/**
 * @name    tt_set_ttbr0
 * @brief   Set the translation table base 0 register.
 *
 * @details Provides the ability to set the translation table base 0 register.
 *
 * @param tt_translation_table_base_register_t ttbr
 *
 * Example Usage:
 * @code
 *    tt_set_ttbr0(ttbr0);
 * @endcode
 */
extern void tt_set_ttbr0(tt_translation_table_base_register_t ttbr);

/**
 * @name    tt_set_ttbr1
 * @brief   Set the translation table base 1 register.
 *
 * @details Provides the ability to set the translation table base 1 register.
 *
 * @param tt_translation_table_base_register_t ttbr
 *
 * Example Usage:
 * @code
 *    tt_set_ttbr1(ttbr1);
 * @endcode
 */
extern void tt_set_ttbr1(tt_translation_table_base_register_t ttbr);

/**
 * @name    tt_set_ttbcr
 * @brief   Set the translation table base control register.
 *
 * @details Provides the ability to set the translation table base control register.
 *
 * @param tt_translation_table_base_control_register_t ttbcr
 *
 * Example Usage:
 * @code
 *    tt_set_ttbcr(ttbcr);
 * @endcode
 */
extern void tt_set_ttbcr(tt_translation_table_base_control_register_t ttbcr);

#endif //__C__

#ifdef __ASSEMBLY__

.extern tt_get_ttbr0
.extern tt_get_ttbr1
.extern tt_get_ttbcr
.extern tt_set_ttbr0
.extern tt_set_ttbr1
.extern tt_set_ttbcr

.extern tt_double_switch

#endif //__ASSEMBLY__

#endif //__VMSA_TT_H__
