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

#ifndef __FXPLIB_GEN_H__
#define __FXPLIB_GEN_H__

#ifdef __C__

#define GEN_REFERENCE_GLOBAL(a) \
	*((void **)gen_add_base(&a))

extern void * gen_get_base();
extern void * gen_add_base(void *address);
extern void * gen_subtract_base(void *address);

#endif //__C__

#ifdef __ASSEMBLY__

.extern gen_get_base

#endif //__ASSEMBLY__

#endif //__FXPLIB_GEN_H__
