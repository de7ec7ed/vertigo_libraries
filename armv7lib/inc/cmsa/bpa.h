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
 * @brief API for the Branch Predictor Array in the CMSA of the ARMv7 architecture.
 *
 * @details Includes maintenance functions for the branch predictor array.
 */

#ifndef __CMSA_BP_H__
#define __CMSA_BP_H__

#include <armv7lib/vmsa/tt.h>

#ifdef __C__

/**
 * @name bpa_flush_mva_branch_predictor_array
 * @brief Flush a mva from the branch predictor array.
 *
 * @details Provides the ability to flush a modified virtual address from the entire branch preditor array.
 *
 * @retval tt_virtual_address_t va
 *
 * Example Usage:
 * @code
 *    bpa_flush_mva_branch_predictor_array(va);
 * @endcode
 */
void bpa_flush_mva_branch_predictor_array(tt_virtual_address_t va);

/**
 * @name bpa_flush_entire_branch_predictor_array
 * @brief Flush the entire branch predictor array.
 *
 * @details Provides the ability to flush the entire branch predictor array.
 *
 * Example Usage:
 * @code
 *    bpa_flush_entire_branch_predictor_array();
 * @endcode
 */
void bpa_flush_entire_branch_predictor_array(void);

#endif //__C__

#ifdef __ASSEMBLY__

.extern bp_flush_mva_branch_predictor_array
.extern bp_flush_entire_branch_predictor_array

#endif //__ASSEMBLY__

#endif //__CMSA_BP_H__
