/* This file is part of VERTIGO.
 *
 * (C) Copyright 2013, Siege Technologies <siegetechnologies.com>
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

#include <defines.h>

#include <armv7lib/vmsa/flt.h>

FUNCTION(flt_get_dfsr)
	mrc p15, 0, r0, c5, c0, 0
	mov pc, lr

FUNCTION(flt_set_dfsr)
	mcr p15, 0, r0, c5, c0, 0
	mov pc, lr

FUNCTION(flt_get_ifsr)
	mrc p15, 0, r0, c5, c0, 1
	mov pc, lr

FUNCTION(flt_set_ifsr)
	mcr p15, 0, r0, c5, c0, 1
	mov pc, lr

FUNCTION(flt_get_dfar)
	mrc p15, 0, r0, c6, c0, 0
	mov pc, lr

FUNCTION(flt_set_dfar)
	mcr p15, 0, r0, c6, c0, 0

FUNCTION(flt_get_ifar)
	mrc p15, 0, r0, c6, c0, 2
	mov pc, lr

FUNCTION(flt_set_ifar)
	mcr p15, 0, r0, c6, c0, 2
	mov pc, lr
