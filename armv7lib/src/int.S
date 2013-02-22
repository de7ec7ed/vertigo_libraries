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
#include <armv7lib/int.h>

FUNCTION(int_disable_irq)
	mrs r0, cpsr
	orr r0,r0,#0x80
	msr cpsr, r0
	mov pc, lr

FUNCTION(int_enable_irq)
	mrs r0, cpsr
	bic r0,r0,#0x80
	msr cpsr, r0
	mov pc, lr

FUNCTION(int_disable_fiq)
	mrs r0, cpsr
	orr r0,r0,#0x40
	msr cpsr, r0
	mov pc, lr

FUNCTION(int_enable_fiq)
	mrs r0, cpsr
	bic r0,r0,#0x40
	msr cpsr, r0
	mov pc, lr
