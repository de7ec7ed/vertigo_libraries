/* This file is part of VERTIGO.
 *
 * (C) Copyright 2013, Siege Technologies <http://www.siegetechnologies.com>
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
 * @brief API for the Cache in the CMSA of the ARMv7 architecture.
 *
 * @details Includes maintenance functions for the cache.
 */

#include <types.h>
#include <armv7lib/vmsa/tt.h>

#ifndef __CMSA_CAC_H__
#define __CMSA_CAC_H__

#ifdef __C__

typedef union cac_cache_size_id_register cac_cache_size_id_register_t;
typedef union cac_cache_level_id_register cac_cache_level_id_register_t;
typedef union cac_cache_size_selection_register cac_cache_size_selection_register_t;

union cac_cache_size_selection_register {
	struct {
		u32_t ind    :1; ///< Instruction not Data bit.
		u32_t level  :3; ///< Cache level of required cache. Permitted values are from 0b000, indicating Level 1 cache, to 0b110 indicating Level 7 cache.
		u32_t unused :28;
	} fields;
	u32_t all;
};

union cac_cache_size_id_register {
	struct {
		u32_t line_size  :3;  ///< (Log2(Number of words in cache line)) - 2
		u32_t associvity :10; ///< (Associativity of cache) - 1, therefore a value of 0 indicates an associativity of 1. The associativity does not have to be a power of 2.
		u32_t num_sets   :15; ///< (Number of sets in cache) - 1, therefore a value of 0 indicates 1 set in the cache. The number of sets does not have to be a power of 2.
		u32_t wa         :1;  ///< Indicates whether the cache level supports Write-Allocation.
		u32_t ra         :1;  ///< Indicates whether the cache level supports Read-Allocation.
		u32_t wb         :1;  ///< Indicates whether the cache level supports Write-Back.
		u32_t wt         :1;  ///< Indicates whether the cache level supports Write-Through.
	} fields;
	u32_t all;
};

union cac_cache_level_id_register {
	struct {
		u32_t ctype1   :3; ///< Cache Type 1 field. Indicate the type of cache implemented at each level, from Level 1 up to a maximum of seven levels of cache hierarchy.
		u32_t ctype2   :3; ///< Cache Type 2 field.
		u32_t ctype3   :3; ///< Cache Type 3 field.
		u32_t ctype4   :3; ///< Cache Type 4 field.
		u32_t ctype5   :3; ///< Cache Type 5 field.
		u32_t ctype6   :3; ///< Cache Type 6 field.
		u32_t ctype7   :3; ///< Cache Type 7 field.
		u32_t louis    :3; ///< Level of Unification Inner Shareable for the cache hierarchy.
		u32_t loc      :3; ///< Level of Coherency for the cache hierarchy.
		u32_t louu     :3; ///< Level of Unification Uniprocessor for the cache hierarchy.
		u32_t unused_0 :2;
	} fields;
	u32_t all;
};

/**
 * @name cac_get_clidr
 * @brief Get the CLIDR
 *
 * @details Provides the ability to get the cache size selection register.
 *
 * @retval cac_cache_size_selection_register_t
 *
 * Example Usage:
 * @code
 *    csselr = cac_get_csselr();
 * @endcode
 */
extern cac_cache_size_selection_register_t cac_get_csselr(void);

/**
 * @name cac_set_csselr
 * @brief Set the CSSELR
 *
 * @details Provides the ability to set the cache size selection register.
 *
 * param cac_cache_size_selection_register_t csselr
 *
 * Example Usage:
 * @code
 *    cac_set_csselr(csselr);
 * @endcode
 */
extern void cac_set_csselr(cac_cache_size_selection_register_t csselr);

/**
 * @name cac_get_clidr
 * @brief Get the CLIDR
 *
 * @details Provides the ability to get the cache level id register.
 *
 * @retval cac_cache_level_id_register_t
 *
 * Example Usage:
 * @code
 *    clidr = cac_get_clidr();
 * @endcode
 */
extern cac_cache_level_id_register_t cac_get_clidr(void);

/**
 * @name cac_get_ccsidr
 * @brief Get the CCSIDR
 *
 * @details Provides the ability to get the cache size id register.
 *
 * @retval cac_cache_size_id_register_t
 *
 * Example Usage:
 * @code
 *    ccsidr = cac_get_ccsidr();
 * @endcode
 */
extern cac_cache_size_id_register_t cac_get_ccsidr(void);

/**
 * @name cac_invalidate_mva_to_pou_instruction_cache
 * @brief Invalidate the instruction cache by MVA to PoU.
 *
 * @details Provides the ability to invalidate the instruction cache by a modified virtual address to the
 * point of unification.
 *
 * @param tt_virtual_address_t va
 *
 * Example Usage:
 * @code
 *    cac_invalidate_mva_to_pou_instruction_cache(va);
 * @endcode
 */
extern void cac_invalidate_mva_to_pou_instruction_cache(tt_virtual_address_t va);

/**
 * @name cac_flush_entire_instruction_cache
 * @brief Flush the entire instruction cache
 *
 * @details Provides the ability to flush the entire instruction cache. This
 * function is only available if the implementations has a seperate instruction
 * and data cache.
 *
 * Example Usage:
 * @code
 *    cac_flush_entire_instruction_cache();
 * @endcode
 */
extern void cac_flush_entire_instruction_cache(void);

/**
 * @name cac_clean_mva_to_poc_data_cache
 * @brief Clean the data cache by MVA to PoC.
 *
 * @details Provides the ability to clean the instruction cache by a modified virtual address to the
 * point of coherency.
 *
 * @param tt_virtual_address_t va
 *
 * Example Usage:
 * @code
 *    cac_clean_mva_to_poc_data_cache(va);
 * @endcode
 */
extern void cac_clean_mva_to_poc_data_cache(tt_virtual_address_t va);

/**
 * @name cac_flush_mva_to_poc_data_cache
 * @brief Flush the data cache by MVA to PoC.
 *
 * @details Provides the ability to flush the instruction cache by a modified virtual address to the
 * point of coherency.
 *
 * @param tt_virtual_address_t va
 *
 * Example Usage:
 * @code
 *    cac_flush_mva_to_poc_data_cache(va);
 * @endcode
 */
extern void cac_flush_mva_to_poc_data_cache(tt_virtual_address_t va);

/**
 * @name cac_flush_entire_data_cache
 * @brief Flush the entire data cache
 *
 * @details Provides the ability to flush the entire data cache. This function
 * will either flush the entire data cache or the entire unified cache if the
 * implementation does not have a separate instruction cache.
 *
 * Example Usage:
 * @code
 *    bpa_flush_entire_branch_predictor_array();
 * @endcode
 */
extern void cac_flush_entire_data_cache(void);

#endif //__C__

#ifdef __ASSEMBLY__

.extern cac_get_csselr
.extern cac_set_csselr
.extern cac_get_clidr
.extern cac_get_ccsidr
.extern cac_invalidate_mva_to_pou_instruction_cache
.extern cac_flush_entire_instruction_cache
.extern cac_clean_mva_to_poc_data_cache
.extern cac_flush_mva_to_poc_data_cache
.extern cac_flush_entire_data_cache

#endif //__ASSEMBLY__

#endif //__CMSA_CAC_H__
