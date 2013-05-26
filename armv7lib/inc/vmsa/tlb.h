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
 * @brief API for the TLB in the VMSA of the ARMv7 architecture.
 *
 * @details Includes functions to flush the TLB in its entirety or selectively.
 */

#ifndef __VMSA_TLB_H__
#define __VMSA_TLB_H__

#ifdef __C__

typedef union tlb_type_register tlb_type_register_t;

union tlb_type_register {
	struct {
		u32_t nu :1; ///< Not Unified TLB. Indicates whether the implementation has a unified TLB
		u32_t imp_def_0 :31;
	} fields;
	u32_t all;
};

/**
 * @name    tlb_get_tlbtr
 * @brief   Get the TLB type register.
 *
 * @details Provides the ability to get the TLB type register and determine if the SoC has a seperate or
 * unified TLB.
 *
 * @retval tlb_type_register_t
 *
 * Example Usage:
 * @code
 *    tlbtr = tlb_get_tlbtr();
 * @endcode
 */
extern tlb_type_register_t tlb_get_tlbtr(void);

extern void tlb_invalidate_entire_tlb_inner_shareable(void);

extern void tlb_invalidate_mva_tlb_inner_shareable(void *va);
/**
 * @name    tlb_invalidate_entire_unified_tlb
 * @brief   Invalidate the entire unified TLB.
 *
 * @details Provides the ability to invalidate the TLB this will include
 * both the instruction and data TLBs if implemented.
 *
 * Example Usage:
 * @code
 *    tlb_invalidate_entire_unified_tlb();
 * @endcode
 */
extern void tlb_invalidate_entire_unified_tlb(void);

/**
 * @name    tlb_invalidate_mva_unified_tlb
 * @brief   Invalidate a MVA in the unified TLB.
 *
 * @details Provides the ability to invalidate a modified virtual
 * address in the TLB. On a system with seperate instruction and
 * data TLBs this function will invalidate data TLB.
 *
 * Example Usage:
 * @code
 *    tlb_invalidate_mva_unified_tlb();
 * @endcode
 */
extern void tlb_invalidate_mva_unified_tlb(void *va);

extern void tlb_invalidate_entire_instruction_tlb(void);

extern void tlb_invalidate_entire_data_tlb(void);

extern void tlb_invalidate_mva_data_tlb(void *va);

extern void tlb_invalidate_mva_instruction_tlb(void *va);

extern void tlb_invalidate_tlb_region(void *va, size_t size);

extern void tlb_invalidate_entire_tlb(void);

#endif //__C__

#ifdef __ASSEMBLY__

.extern tlb_get_tlbtr
.extern tlb_invalidate_entire_tlb_inner_shareable
.extern tlb_invalidate_mva_tlb_inner_shareable
.extern tlb_invalidate_entire_unified_tlb
.extern tlb_invalidate_mva_unified_tlb
.extern tlb_invalidate_entire_instruction_tlb
.extern tlb_invalidate_entire_data_tlb
.extern tlb_invalidate_mva_data_tlb
.extern tlb_invalidate_mva_instruction_tlb

#endif //__ASSEMBLY__

#endif //__VMSA_TLB_H__
