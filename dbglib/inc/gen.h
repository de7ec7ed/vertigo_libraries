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

#ifndef __DBGLIB_GEN_H__
#define __DBGLIB_GEN_H__

#include <dbglib/mem.h>
#include <dbglib/ser.h>

#define DBG_LEVEL_0 0 // dbg off
#define DBG_LEVEL_1 1 // dbg low
#define DBG_LEVEL_2 2 // dbg medium
#define DBG_LEVEL_3 3 // dbg high

#ifdef __C__

// clear previous declarations
#undef DBG_LOG_FUNCTION
#undef DBG_LOG_STATEMENT

#define DBG_DEFINE_VARIABLE(a, b) \
	u32_t a = b

#define DBG_GET_VARIABLE(a, b) \
	b = *(u32_t *)gen_add_base(&a);

#define DBG_SET_VARIABLE(a, b) \
		*(u32_t *)gen_add_base(&a) = b;

#define DBG_LOG_FUNCTION(c, d) \
	if((*(u32_t *)gen_add_base(&c)) >= d) { MEMORY_LOG((char *)gen_add_base((char *)__FUNCTION__), (unsigned long)__LINE__); SERIAL_LOG((char *)gen_add_base((char *)__FUNCTION__), __LINE__); }

#define DBG_LOG_STATEMENT(a, b, c, d) \
	if((*(u32_t *)gen_add_base(&c)) >= d) { MEMORY_LOG(gen_add_base(a), (u32_t)b); SERIAL_LOG(gen_add_base(a), (u32_t)b); }

#endif //__C__

#endif //__DBGLIB_GEN_H__
