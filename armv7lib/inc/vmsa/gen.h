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
 * @brief Basic API for the VMSA on the ARMv7 architecture.
 *
 * @details Includes defines, data structures, getters and setters for the more
 * generalized parts of the VMSA.
 */

#ifndef __VMSA_GEN_H__
#define __VMSA_GEN_H__

#include <types.h>
#include <armv7lib/vmsa/tt.h>

#define GEN_PAR_OUTER_WB_NO_WA 0x3     ///< Write-Back, no Write-Allocate
#define GEN_PAR_OUTER_WT_NO_WA 0x2     ///< Write-Through, no Write-Allocate
#define GEN_PAR_OUTER_WB_WA    0x1     ///< Write-Back, Write-Allocate
#define GEN_PAR_OUTER_NC       0x0     ///< Non-cacheable

#define GEN_PAR_INNER_WB_NO_WA 0x7     ///< Write-Back, no Write-Allocate
#define GEN_PAR_INNER_WT       0x6     ///< Write-Through
#define GEN_PAR_INNER_WB_WA    0x5     ///< Write-Back, Write-Allocate
#define GEN_PAR_INNER_D        0x3     ///< Device
#define GEN_PAR_INNER_SO       0x1     ///< Strongly-ordered
#define GEN_PAR_INNER_NC       0x0     ///< Non-cacheable

#define GEN_PRRR_SO          0x0       ///< Strongly Ordered
#define GEN_PRRR_D           0x1       ///< Device
#define GEN_PRRR_NM          0x2       ///< Normal Memory

#define GEN_NMRR_NC         0x0 ///< Non-cacheable
#define GEN_NMRR_WB_WA      0x1 ///< Write-Back, Write-Allocate
#define GEN_NMRR_WT_WA      0x2 ///< Write-Through, Write-Allocate
#define GEN_NMRR_WB_NO_WA   0x3 ///< Write-Baack, No Write-Allocate

#define GEN_NUMBER_PRRR_ENTRIES  8
#define GEN_NUMBER_NMRR_ENTRIES  8



#ifdef __C__

typedef union gen_multiprocessor_affinity_register gen_multiprocessor_affinity_register_t;
typedef union gen_physical_address_register gen_physical_address_register_t;
typedef union gen_system_control_register gen_system_control_register_t;
typedef union gen_context_id_register gen_context_id_register_t;
typedef union gen_primary_region_remap_register gen_primary_region_remap_register_t;
typedef union gen_normal_memory_remap_register gen_normal_memory_remap_register_t;

union gen_multiprocessor_affinity_register {
	struct {
		size_t al_0  :8;  ///< The most significant level field
		size_t al_1  :8;  ///< The intermediate affinity level field
		size_t al_2  :8;  ///< The least significant affinity level field
		size_t mt    :1;  ///< Multi-threading type approach
		size_t sbz_0 :5;  ///< Reserved. UNK.
		size_t u     :1;  ///< Indicates a Uniprocessor system
		size_t fmt   :1;  ///< Indicates that the processor implements the Multiprocessing Extensions register format
	} fields;
	size_t all;
};

union gen_physical_address_register {
	struct {
		size_t f          :1;  ///< F bit is 0 if the conversion completed successfully.
		size_t ss         :1;  ///< SuperSection. Used to indicate if the result is a Supersection.
		size_t outer      :2;  ///< Outer memory attributes from the translation table.
		size_t inner      :3;  ///< Inner memory attributes from the translation table.
		size_t sh         :1;  ///< Sharable attribute. Indicates whether the physical memory is sharable.
		size_t imp_def_0  :1;  ///< implementation defined.
		size_t ns         :1;  ///< Non-secure. The NS bit from the translation table entry.
		size_t nos        :1;  ///< Not Outer Sharable attribute. Indicates whether the physical memory is Outer Sharable.
		size_t sbz_0      :1;  ///< Reserved. UNK/SBZP.
		size_t pa         :20; ///< Physical Address. The physical address corresponding to the supplied virtual address.
	} fields;
	size_t all;
};

union gen_system_control_register {
	struct {
		u32_t m        :1; ///< MMU enable bit. This is a global enable bit for the MMU.
		u32_t a        :1; ///< Alignment bit. This is the enable bit for Alignment fault checking.
		u32_t c        :1; ///< Cache enable bit. This is a global enable bit for data and unified caches.
		u32_t unused_0 :4;
		u32_t b        :1; ///< In ARMv7 this bit is RAZ/SBZP, indicating use of the endianness model described in Endian support.
		u32_t unused_1 :2;
		u32_t sw       :1; ///< SWP/SWPB Enable bit. This bit enables the use of SWP and SWPB instructions.
		u32_t z        :1; ///< Branch prediction enable bit. This bit is used to enable branch prediction, also called program flow prediction.
		u32_t i        :1; ///< Instruction cache enable bit: This is a global enable bit for instruction caches.
		u32_t v        :1; ///< Vectors bit. This bit selects the base address of the exception vectors.
		u32_t rr       :1; ///< Round Robin bit. If the cache implementation supports the use of an alternative replacement strategy that has a more easily predictable worst-case performance, this bit selects it.
		u32_t unused_2 :2;
		u32_t ha       :1; ///< Hardware Access Flag Enable bit. If the implementation provides hardware management of the access flag this bit enables the access flag management.
		u32_t unused_3 :3;
		u32_t fi       :1; ///< Fast Interrupts configuration enable bit. This bit can be used to reduce interrupt latency in an implementation by disabling IMPLEMENTATION DEFINED performance features.
		u32_t u        :1; ///< In ARMv7 this bit is RAO/SBOP, indicating use of the alignment model described in Alignment support.
		u32_t unused_4 :1;
		u32_t ve       :1; ///< Interrupt Vectors Enable bit. This bit controls the vectors used for the FIQ and IRQ interrupts.
		u32_t ee       :1; ///< Exception Endianness bit. The value of this bit defines the value of the CPSR.E bit on entry to an exception vector, including reset. This value also indicates the endianness of the translation table data for translation table lookups.
		u32_t unused_5 :1;
		u32_t nmfi     :1; ///< Non-maskable Fast Interrupts enable.
		u32_t tre      :1; ///< TEX Remap Enable bit. This bit enables remapping of the TEX[2:1] bits for use as two translation table bits that can be managed by the operating system. Enabling this remapping also changes the scheme used to describe the memory region attributes in the VMSA.
		u32_t afe      :1; ///< Access Flag Enable bit. This bit enables use of the AP[0] bit in the translation table descriptors as an access flag. It also restricts access permissions in the translation table descriptors to the simplified model described in Simplified access permissions model.
		u32_t te       :1; ///< Thumb Exception enable. This bit controls whether exceptions are taken in ARM or Thumb state.
		u32_t unused_6 :1;
	} fields;
	u32_t all;
};

union gen_context_id_register {
	struct {
		u32_t asid      :8; ///< Address Space Identifier. This field is programmed with the value of the current ASID.
		u32_t procid    :24; ///< Process Identifier. This field must be programmed with a unique value that identifies the current process.
	} fields;
	u32_t all;
};

union gen_primary_region_remap_register {
	struct {
		u32_t tr0 :2;    ///< Primary TEX mapping for memory attributes n. n is the value of the TEX[0], C and B bits.
		u32_t tr1 :2;
		u32_t tr2 :2;
		u32_t tr3 :2;
		u32_t tr4 :2;
		u32_t tr5 :2;
		u32_t tr6 :2;
		u32_t tr7 :2;
		u32_t ds0 :1;   ///< Mapping of S = 0 attribute for Device memory.
		u32_t ds1 :1;
		u32_t ns0 :1;   ///< Mapping of S = 0 attribute for Normal memory
		u32_t ns1 :1;
		u32_t unused_0 :4;
		u32_t nos0 :1;
		u32_t nos1 :1;
		u32_t nos2 :1;
		u32_t nos3 :1;
		u32_t nos4 :1;
		u32_t nos5 :1;
		u32_t nos6 :1;
		u32_t nos7 :1;
	} fields;
	u32_t all;
};

union gen_normal_memory_remap_register {
	struct {
		u32_t ir0 :2;   ///< Inner Cacheable property mapping for memory attributes n, if the region is mapped as Normal Memory by the TRn entry in the PRRR.
		u32_t ir1 :2;
		u32_t ir2 :2;
		u32_t ir3 :2;
		u32_t ir4 :2;
		u32_t ir5 :2;
		u32_t ir6 :2;
		u32_t ir7 :2;
		u32_t or0 :2;   ///< Outer Cacheable property mapping for memory attributes n, if the region is mapped as Normal Memory by the TRn entry in the PRRR
		u32_t or1 :2;
		u32_t or2 :2;
		u32_t or3 :2;
		u32_t or4 :2;
		u32_t or5 :2;
		u32_t or6 :2;
		u32_t or7 :2;
	} fields;
	u32_t all;
};

/**
 * @name    gen_pa_to_va
 * @brief   Translates a physical address to a virtual address.
 *
 * @details Provides the ability to translate a physical address to a virtual address. The start and
 * end virtual addresses are used to bound the search space for the physical address trying to be
 * translated. This is useful for things such as MMIO address that almost always reside in the kernel
 * and the kernel is usually located above the 2GB or 3GB line in a virtual memory space.
 *
 * @param tt_physical_address_t pa
 * @param tt_virtual_address_t start
 * @param tt_virtual_address_t end
 * @param tt_virtual_address_t va
 *
 * @retval result_t
 *
 * Example Usage:
 * @code
 *    if(gen_pa_to_va(pa, start, end, &va) != SUCCESS) { return FAILURE; }
 * @endcode
 */
result_t gen_pa_to_va(tt_physical_address_t pa, tt_virtual_address_t start, tt_virtual_address_t end, tt_virtual_address_t *va);

/**
 * @name gen_va_to_pa
 * @brief Translates a virtual address to a physical address.
 *
 * @details Provides the ability to translate a virtual address to a physical address. This function
 * utilizes coprocessor 15 and its ability to walk the page tables or tlb to perform translations.
 *
 * @param tt_virtual_address_t va
 * @param tt_physical_address_t pa
 *
 * @retval result_t
 *
 * Example Usage:
 * @code
 *    if(gen_va_to_pa(va, &pa) != SUCCESS) { return FAILURE; }
 * @endcode
 */
result_t gen_va_to_pa(tt_virtual_address_t va, tt_physical_address_t *pa);

/**
 * @name gen_get_par
 * @brief Gets the physical address register.
 *
 * @details Provides the ability to get the physical address register from coprocessor 15. This
 * function is usually called after a call to either gen_privileged_read_translation,
 * gen_privileged_write_translation, gen_user_read_translation or gen_user_write_translation.
 *
 * @retval gen_physical_address_register_t
 *
 * Example Usage:
 * @code
 *    if(gen_get_par(pa, start, end, &va) != SUCCESS) { return FAILURE; }
 * @endcode
 */
gen_physical_address_register_t gen_get_par(void);

/**
 * @name gen_set_par
 * @brief Gets the physical address register.
 *
 * @details Provides the ability to set the physical address register from coprocessor 15.
 *
 * Example Usage:
 * @code
 *    gen_set_par(par);
 * @endcode
 */
void gen_set_par(gen_physical_address_register_t par);

/**
 * @name gen_privileged_read_translation
 * @brief Perform a privileged read translation
 *
 * @details Provides the ability to translate a virtual address to a physical address
 * if the entry is readable from privileged code, such as the kernel.
 *
 * Example Usage:
 * @code
 *    gen_privileged_read_translation(va);
 * @endcode
 */
void gen_privileged_read_translation(tt_virtual_address_t va);

/**
 * @name gen_privileged_write_translation
 * @brief Perform a privileged write translation
 *
 * @details Provides the ability to translate a virtual address to a physical address
 * if the entry is writable from privileged code, such as the kernel.
 *
 * Example Usage:
 * @code
 *    gen_privileged_write_translation(va);
 * @endcode
 */
void gen_privileged_write_translation(tt_virtual_address_t va);

/**
 * @name gen_user_read_translation
 * @brief Perform a user read translation
 *
 * @details Provides the ability to translate a virtual address to a physical address
 * if the entry is readable from user code.
 *
 * Example Usage:
 * @code
 *    gen_user_read_translation(va);
 * @endcode
 */
void gen_user_read_translation(tt_virtual_address_t va);

/**
 * @name gen_user_write_translation
 * @brief Perform a user write translation
 *
 * @details Provides the ability to translate a virtual address to a physical address
 * if the entry is writable from user code.
 *
 * Example Usage:
 * @code
 *    gen_user_write_translation(va);
 * @endcode
 */
void gen_user_write_translation(tt_virtual_address_t va);

/**
 * @name gen_get_sctlr
 * @brief Gets the system control register
 *
 * @details Provides the ability to get the system control register.
 *
 * @retval gen_system_control_register_t
 *
 * Example Usage:
 * @code
 *    sctlr = gen_get_sctlr();
 * @endcode
 */
gen_system_control_register_t gen_get_sctlr(void);

/**
 * @name gen_set_sctlr
 * @brief Sets the system control register
 *
 * @details Provides the ability to set the system control register.
 *
 * @param gen_system_control_register_t reg
 *
 * Example Usage:
 * @code
 *    gen_set_sctlr(sctlr);
 * @endcode
 */
void gen_set_sctlr(gen_system_control_register_t reg);

/**
 * @name gen_get_mpidr
 * @brief Gets the multiprocessor affinity register
 *
 * @details Provides the ability to get the multiprocessor affinity register.
 *
 * @retval gen_multiprocessor_affinity_register_t
 *
 * Example Usage:
 * @code
 *    mpidr = gen_get_mpidr();
 * @endcode
 */
gen_multiprocessor_affinity_register_t gen_get_mpidr(void);

void gen_data_memory_barrier(void);

void gen_data_synchronization_barrier(void);

void gen_instruction_synchronization_barrier(void);

gen_context_id_register_t gen_get_contextidr(void);

void gen_set_contextidr(gen_context_id_register_t contextidr);

gen_primary_region_remap_register_t gen_get_prrr(void);
void gen_set_prrr(gen_primary_region_remap_register_t prrr);

gen_normal_memory_remap_register_t gen_get_nmrr(void);
void gen_set_nmrr(gen_normal_memory_remap_register_t nmrr);


#endif //__C__

#ifdef __ASSEMBLY__

.extern gen_get_par
.extern gen_privileged_read_translation
.extern gen_privileged_write_translation
.extern gen_user_read_translation
.extern gen_user_write_translation
.extern gen_get_sctlr
.extern gen_set_sctlr
.extern gen_get_mpidr
.extern gen_data_memory_barrier
.extern gen_data_synchronization_barrier
.extern gen_instruction_synchronization_barrier
.extern gen_get_contextidr
.extern gen_set_contextidr
#endif //__ASSEMBLY__

#endif //__VMSA_GEN_H__
