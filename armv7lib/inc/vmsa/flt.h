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
 * @brief API for faults in the VMSA on the ARMv7 architecture.
 *
 * @details Includes data structures,getters and setters faults in the VMSA.
 */

#ifndef __FLT_H__
#define __FLT_H__

#include <armv7lib/vmsa/tt.h>

#ifdef __C__

typedef union flt_instruction_fault_status_register flt_instruction_fault_status_register_t;
typedef union flt_data_fault_status_register flt_data_fault_status_register_t;

union flt_instruction_fault_status_register {
	struct {
		u32_t fs_0     :4; ///< Fault status bits [3, 0].
		u32_t unused_0 :6;
		u32_t fs_1     :1; ///< Fault status bits [4].
		u32_t unused_1 :1;
		u32_t ext      :1; ///< External abort type.
		u32_t unused_2 :19;
	} fields;
	size_t all;
};

union flt_data_fault_status_register {
	struct {
		u32_t fs_0     :4; ///< Fault status bits [3, 0].
		u32_t domain   :4; ///< The domain of the fault address.
		u32_t unused_1 :2;
		u32_t fs_1     :1; ///< Fault status bits [4].
		u32_t wnr      :1; ///< Write not Read bit. Indicates whether the abort was caused by a write or a read access.
		u32_t ext      :1; ///< External abort type.
		u32_t unused_2 :19;
	} fields;
	u32_t all;
};

/**
 * @name    flt_get_dfsr
 * @brief   Get the data fault status register.
 *
 * @details Provides the ability to get the data fault status register.
 *
 * @retval flt_data_fault_status_register_t dfsr
 *
 * Example Usage:
 * @code
 *    dfsr = flt_get_dfsr();
 * @endcode
 */
flt_data_fault_status_register_t flt_get_dfsr(void);

/**
 * @name    flt_set_dfsr
 * @brief   set the data fault status register.
 *
 * @details Provides the ability to set the data fault status register.
 *
 * @param flt_data_fault_status_register_t dfsr
 *
 * Example Usage:
 * @code
 *    flt_set_dfsr(dfsr);
 * @endcode
 */
void flt_set_dfsr(flt_data_fault_status_register_t dfsr);

/**
 * @name    flt_get_ifsr
 * @brief   Get the instruction fault status register.
 *
 * @details Provides the ability to get the instruction fault status register.
 *
 * @retval flt_instruction_fault_status_register_t ifsr
 *
 * Example Usage:
 * @code
 *    ifsr = flt_get_ifsr();
 * @endcode
 */
flt_instruction_fault_status_register_t flt_get_ifsr(void);

/**
 * @name    flt_set_ifsr
 * @brief   set the instructin fault status register.
 *
 * @details Provides the ability to set the instruction fault status register.
 *
 ** @param flt_instruction_fault_status_register_t ifsr
 *
 * Example Usage:
 * @code
 *    flt_set_ifsr(ifsr);
 * @endcode
 */
void flt_set_ifsr(flt_instruction_fault_status_register_t ifsr);

/**
 * @name    flt_get_dfar
 * @brief   get the data fault address register.
 *
 * @details Provides the ability to get the data fault address register.
 *
 * @retval tt_virtual_address_t va
 *
 * Example Usage:
 * @code
 *    va = flt_get_dfar();
 * @endcode
 */
tt_virtual_address_t flt_get_dfar(void);

/**
 * @name    flt_set_dfar
 * @brief   set the data fault address register.
 *
 * @details Provides the ability to set the data fault address register.
 *
 * @param tt_virtual_address_t va
 *
 * Example Usage:
 * @code
 *    flt_set_dfar(va);
 * @endcode
 */
void flt_set_dfar(tt_virtual_address_t va);

/**
 * @name    flt_get_ifar
 * @brief   get the instruction fault address register.
 *
 * @details Provides the ability to get the instruction fault address register.
 *
 * @retval tt_virtual_address_t va
 *
 * Example Usage:
 * @code
 *    va = flt_get_ifar();
 * @endcode
 */
tt_virtual_address_t flt_get_ifar(void);

/**
 * @name    flt_set_ifar
 * @brief   set the instruction fault address register.
 *
 * @details Provides the ability to set the instruction fault address register.
 *
 * @param tt_virtual_address_t va
 *
 * Example Usage:
 * @code
 *    flt_set_ifar(va);
 * @endcode
 */
void flt_set_ifar(tt_virtual_address_t va);

#endif //__C__

#ifdef __ASSEMBLY__

.extern flt_get_dfsr
.extern flt_set_dfsr
.extern flt_get_ifsr
.extern flt_set_ifsr
.extern flt_get_dfar
.extern flt_set_dfar
.extern flt_get_ifar
.extern flt_set_ifar

#endif //__ASSEMBLY__

#endif //__FLT_H__
