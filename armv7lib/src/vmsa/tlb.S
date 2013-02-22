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

#include <config.h>
#include <defines.h>

FUNCTION(tlb_get_tlbtr)
	mrc p15, 0, r0, c0, c0, 3
	mov pc, lr

FUNCTION(tlb_invalidate_entire_tlb_inner_shareable)
	mcr p15, 0, r0, c8, c3, 0
	mov pc, lr

FUNCTION(tlb_invalidate_mva_tlb_inner_shareable)
	mcr p15, 0, r0, c8, c3, 1
	mov pc, lr

FUNCTION(tlb_invalidate_entire_unified_tlb)
	mcr p15, 0, r0, c8, c7, 0
	mov pc, lr

FUNCTION(tlb_invalidate_mva_unified_tlb)
	mcr p15, 0, r0, c8, c7, 1
	mov pc, lr
