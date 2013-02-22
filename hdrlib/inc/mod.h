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

#ifndef __HDRLIB_MOD_H__
#define __HDRLIB_MOD_H__

#include <hdrlib/gen.h>

#ifdef __C__

typedef struct mod_header mod_header_t;
typedef struct mod_import_header mod_import_header_t;
typedef struct mod_export_header mod_export_header_t;
typedef struct mod_storage_header mod_storage_header_t;

struct mod_import_header {
	size_t functions_size;
	gen_import_function_t *functions;
} PACKED;

struct mod_export_header {
	size_t functions_size;
	gen_export_function_t *functions;
} PACKED;

struct mod_storage_header {

};

struct mod_header {
	u32_t callsign; // signature
	mod_import_header_t *import;
	mod_export_header_t *export;
	mod_storage_header_t *storage;
	void *init; // mod_init
	void *fini; // mod_fini
	u8_t string[];
} PACKED;

extern void mod_init(void);
extern void mod_fini(void);

#endif //__C__

#ifdef __ASSEMBLY__

.macro MOD_MODULE_INFORMATION name

VARIABLE(init_asm_address) .word init_asm

VARIABLE(fini_asm_address) .word fini_asm

VARIABLE(string) .asciz "\name"

.endm

#endif //__ASSEMBLY__

#endif //__HDRLIB_MOD_H__
