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
#include <armv7lib/cmsa/cac.h>

FUNCTION(cac_get_csselr)
	mrc p15, 2, r0, c0, c0, 0
	mov pc, lr

FUNCTION(cac_set_csselr)
	mcr p15, 2, r0, c0, c0, 0
	mov pc, lr

FUNCTION(cac_get_clidr)
	mrc p15, 1, r0, c0, c0, 1
	mov pc, lr

FUNCTION(cac_get_ccsidr)
	mrc p15, 1, r0, c0, c0, 0
	mov pc, lr

FUNCTION(cac_invalidate_mva_to_pou_instruction_cache)
	mcr p15, 0, r0, c7, c5, 1
	mov pc, lr

FUNCTION(cac_clean_mva_to_poc_data_cache)
	mcr p15, 0, r0, c7, c10, 1
	mov pc, lr

FUNCTION(cac_clean_mva_to_pou_data_cache)
	mcr p15, 0, r0, c7, c11, 1
	mov pc, lr

FUNCTION(cac_invalidate_mva_to_poc_data_cache)
	mcr p15, 0, r0, c7, c6, 1
	mov pc, lr

FUNCTION(cac_flush_mva_to_poc_data_cache)
	mcr p15, 0, r0, c7, c14, 1
	mov pc, lr

FUNCTION(cac_flush_entire_instruction_cache)
	mcr p15, 0, r0, c7, c5, 0
	mov pc, lr

// TODO: Turn into C code
FUNCTION(cac_flush_entire_data_cache)
	push {r0 - r12}
	dmb                                // ensure ordering with previous memory accesses
	mrc	p15, 1, r0, c0, c0, 1          // read clidr
	ands r3, r0, #0x7000000            // extract loc from clidr
	mov	r3, r3, lsr #23                // left align loc bit field
	beq	finished                       // if loc is 0, then no need to clean
	mov	r10, #0                        // start clean at cache level 0
	loop1:
	add	r2, r10, r10, lsr #1           // work out 3x current cache level
	mov	r1, r0, lsr r2                 // extract cache type bits from clidr
	and	r1, r1, #7                     // mask of the bits for current cache only
	cmp	r1, #2                         // see what cache we have at this level
	blt	skip                           // skip if no cache, or just i-cache
	mcr	p15, 2, r10, c0, c0, 0         // select current cache level in cssr
	isb                                // isb to sych the new cssr&csidr
	mrc	p15, 1, r1, c0, c0, 0          // read the new csidr
	and	r2, r1, #7                     // extract the length of the cache lines
	add	r2, r2, #4                     // add 4 (line length offset)
	ldr	r4, =0x3FF
	ands	r4, r4, r1, lsr #3         // find maximum number on the way size
	clz	r5, r4                         // find bit position of way size increment
	ldr	r7, =0x7FFF
	ands r7, r7, r1, lsr #13           // extract max number of the index size
	loop2:
	mov	r9, r4                         // create working copy of max way size
	loop3:
	orr	r11, r10, r9, lsl r5           // factor way and cache number into r11
	orr	r11, r11, r7, lsl r2           // factor index number into r11
	mcr	p15, 0, r11, c7, c14, 2        // clean & invalidate by set/way
	subs r9, r9, #1                    // decrement the way
	bge	loop3
	subs r7, r7, #1                    // decrement the index
	bge	loop2
	skip:
	add	r10, r10, #2                   // increment cache number
	cmp	r3, r10
	bgt	loop1
	finished:
	mov	r10, #0                        // switch back to cache level 0
	mcr	p15, 2, r10, c0, c0, 0         // select current cache level in cssr
	dsb
	isb
	pop {r0 - r12}
	mov	pc, lr
