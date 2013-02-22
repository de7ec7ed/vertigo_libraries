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

#ifndef __HDRLIB_GEN_H__
#define __HDRLIB_GEN_H__

#include <defines.h>
#include <types.h>

#define GEN_IMPORT_OPERATING_SYSTEM_IOS            1
#define GEN_IMPORT_OPERATING_SYSTEM_ANDROID        2
#define GEN_IMPORT_OPERATING_SYSTEM_WINDOWS_MOBILE 3
#define GEN_IMPORT_OPERATING_SYSTEM_SYMBIAN        4

#ifdef __C__

typedef struct gen_import_function gen_import_function_t;

typedef struct gen_export_function gen_export_function_t;

struct gen_import_function {
	u32_t size; // size of the entire entry
	u32_t address;
	u8_t string[];
} PACKED;

struct gen_export_function {
	u32_t size; // size of the entire entry
	u32_t address;
	u8_t string[];
} PACKED;

#endif //__C__

#ifdef __ASSEMBLY__

.macro GEN_IMPORT_FUNCTION name

1:
VARIABLE(size_\name) .word (2f - 1b)

VARIABLE(address_\name) .word 0

VARIABLE(string_\name) .asciz "\name"

FUNCTION(\name)
ldr pc, address_\name
2:

.endm

.macro GEN_EXPORT_FUNCTION name

1:
VARIABLE(size_\name) .word (2f - 1b)

VARIABLE(address_\name) .word \name

VARIABLE(string_\name) .asciz "\name"
2:

.endm

#endif //__ASSEMBLY__

#endif //__HDRLIB_GEN_H__
