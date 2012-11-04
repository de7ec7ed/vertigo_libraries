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
tlb_type_register_t tlb_get_tlbtr(void);

void tlb_invalidate_entire_tlb_inner_shareable(void);

void tlb_invalidate_mva_tlb_inner_shareable(void);
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
void tlb_invalidate_entire_unified_tlb(void);

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
void tlb_invalidate_mva_unified_tlb(tt_virtual_address_t va);

#endif //__C__

#ifdef __ASSEMBLY__

.extern tlb_get_tlbtr
.extern tlb_invalidate_entire_tlb_inner_shareable
.extern tlb_invalidate_mva_tlb_inner_shareable
.extern tlb_invalidate_entire_unified_tlb
.extern tlb_invalidate_mva_unified_tlb

#endif //__ASSEMBLY__

#endif //__VMSA_TLB_H__
