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

/**
 * @file
 *
 * @brief API for exceptions on the ARMv7 architecture.
 *
 * @details Includes definitions for the all the different exceptions
 * possible on the ARMv7 architecture as well as base addresses for
 * there corresponding table.
 */

#ifndef __EXC_H__
#define __EXC_H__

#define EXC_RESET_INDEX                 0 ///< Index of the reset vector in the vector table.
#define EXC_UNDEFINED_INSTRUCTION_INDEX 1 ///< Index of the undefined instruction vector in the vector table.
#define EXC_SUPERVISOR_CALL_INDEX       2 ///< Index of the supervisor call vector in the vector table.
#define EXC_PREFETCH_ABORT_INDEX        3 ///< Index of the prefetch abort vector in the vector table.
#define EXC_DATA_ABORT_INDEX            4 ///< Index of the data abort vector in the vector table.
#define EXC_NOT_USED_INDEX              5 ///< Index of the reserved vector in the vector table.
#define EXC_INTERRUPT_INDEX             6 ///< Index of the interrupt vector in the vector table.
#define EXC_FAST_INTERRUPT_INDEX        7 ///< Index of the fast interrupt vector in the vector table.

#define EXC_NUMBER_OF_VECTORS           8 ///< Number of vectors in the vector table.

#define EXC_VECTOR_TABLE_LOW_ADDRESS  0x00000000 ///< Base address of the vector table if it is set low.
#define EXC_VECTOR_TABLE_HIGH_ADDRESS 0xFFFF0000 ///< Base address of the vector table if it is set high.

#endif //__EXC_H__
