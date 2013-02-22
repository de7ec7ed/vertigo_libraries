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

FUNCTION(gen_get_par)
	mrc p15, 0, r0, c7, c4, 0 // Physical Address Register (Translation result)
	mov pc, lr

FUNCTION(gen_set_par)
	mcr p15, 0, r0, c7, c4, 0 // Physical Address Register (Translation result)
	mov pc, lr

FUNCTION(gen_privileged_read_translation)
	mcr p15, 0, r0, c7, c8, 0 // Privileged Read VA to PA translation
	mov pc, lr

FUNCTION(gen_privileged_write_translation)
	mcr p15, 0, r0, c7, c8, 1 // Privileged Write VA to PA translation
	mov pc, lr

FUNCTION(gen_user_read_translation)
	mcr p15, 0, r0, c7, c8, 2 // User Read VA to PA translation
	mov pc, lr

FUNCTION(gen_user_write_translation)
	mcr p15, 0, r0, c7, c8, 3 // User Write VA to PA translation
	mov pc, lr

FUNCTION(gen_get_sctlr)
	mrc p15, 0, r0, c1, c0, 0 // Read CP15 System Control Register
	mov pc, lr

FUNCTION(gen_set_sctlr)
	mcr p15, 0, r0, c1, c0, 0 // Write CP15 System Control Register
	mov pc, lr

FUNCTION(gen_get_mpidr)
	mrc p15, 0, r0, c0, c0, 5 // Read CP15 Multiprocessor Affinity Register
	mov pc, lr

FUNCTION(gen_data_memory_barrier)
	dmb
	mov pc, lr

FUNCTION(gen_data_synchronization_barrier)
	dsb
	mov pc, lr

FUNCTION(gen_instruction_synchronization_barrier)
	isb
	mov pc, lr
