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
 * @brief API for cpu identification on the ARMv7 architecture.
 *
 * @details Includes layouts, getters and setters for
 * architectural registers that aid in the identification of the
 * cpu.
 */

#ifndef __CPUID_H__
#define __CPUID_H__

#include <types.h>

#ifdef __C__

typedef union cpuid_main_id_register cpuid_main_id_register_t;

/**
 * Describes the layout of the main id register.
 */
union cpuid_main_id_register {
	struct {
		u32_t revision             :4;  ///< An IMPLEMENTATION DEFINED revision number for the device.
		u32_t primary_part_number  :12; ///< An IMPLEMENTATION DEFINED primary part number for the device.
		u32_t architecture         :4;  ///< Table B3-21 shows the permitted values for this field
		u32_t variant              :4;  ///< An IMPLEMENTATION DEFINED variant number. Typically, this field is used to distinguish between different product variants, or major revisions of a product.
		u32_t implementer          :8;  ///< The Implementor Code
	} fields;
	u32_t all;
};

extern cpuid_main_id_register_t cpuid_get_midr(void);

#endif //__C__

#ifdef __ASSEMBLY__
.extern cpuid_get_midr
#endif //__ASSEMBLY__

#endif //__CPUID_H__
