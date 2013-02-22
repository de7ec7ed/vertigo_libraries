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

#ifndef __HDRLIB_KRN_H__
#define __HDRLIB_KRN_H__

#include <defines.h>
#include <types.h>

#include <hdrlib/gen.h>

#ifdef __C__

typedef struct krn_header krn_header_t;
typedef struct krn_import_header krn_import_header_t;
typedef struct krn_export_header krn_export_header_t;
typedef struct krn_storage_header krn_storage_header_t;

struct krn_import_header {
	u32_t virtual_address; // virtual base address of the flat binary
	u32_t physical_address; // physical base address of the flat binary
	u32_t size; // size of the flat binary
	u32_t operating_system; // operating system the flat binary was loaded into
} PACKED;

struct krn_export_header {
	u32_t functions_size;
	gen_export_function_t *functions;
} PACKED;

struct krn_storage_header {

} PACKED;

struct krn_header {
	u32_t reserved_0; // jump instruction
	u32_t callsign; // signature
	krn_import_header_t *import;
	krn_export_header_t *export;
	krn_storage_header_t *storage;
} PACKED;


#endif //__C__

#endif //__HDRLIB_KRN_H__
