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

#include <config.h>
#include <defines.h>
#include <armv7lib/vmsa/tt.h>

FUNCTION(tt_get_ttbr0)
	mrc p15, 0, r0, c2, c0, 0 // Translation Table Base Register 0
	mov pc, lr

FUNCTION(tt_get_ttbr1)
	mrc p15, 0, r0, c2, c0, 1 // Translation Table Base Register 1
	mov pc, lr

FUNCTION(tt_get_ttbcr)
	mrc p15, 0, r0, c2, c0, 2 // Translation Table Control Register
	mov pc, lr

FUNCTION(tt_set_ttbr0)
	mcr p15, 0, r0, c2, c0, 0 // Translation Table Base Register 0
	mov pc, lr

FUNCTION(tt_set_ttbr1)
	mcr p15, 0, r0, c2, c0, 1 // Translation Table Base Register 1
	mov pc, lr

FUNCTION(tt_set_ttbcr)
	mcr p15, 0, r0, c2, c0, 2 // Translation Table Control Register
	mov pc, lr
