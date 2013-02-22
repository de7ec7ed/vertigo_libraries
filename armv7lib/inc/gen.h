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
 * @brief Basic API for the ARMv7 architecture.
 *
 * @details Includes getters and setters for general purpose
 * registers, the program status registers as well as layouts and
 * descriptions for their fields.
 */

#ifndef __ARMLIB_GEN_H__
#define __ARMLIB_GEN_H__

#define GEN_PSR_MODE_MASK 0x1F	///< Bit mask for mode bits in CPSR.
#define GEN_PSR_USR_MODE  0x10  ///< User mode.
#define GEN_PSR_FIQ_MODE  0x11  ///< Fast Interrupt Request mode.
#define GEN_PSR_IRQ_MODE  0x12  ///< Interrupt Request mode.
#define GEN_PSR_SVC_MODE  0x13  ///< Supervisor mode.
#define GEN_PSR_ABT_MODE  0x17  ///< Abort mode.
#define GEN_PSR_UND_MODE  0x1B  ///< Undefined Instruction mode.
#define GEN_PSR_SYS_MODE  0x1F  ///< System mode.

#ifdef __C__

typedef struct gen_general_purpose_registers gen_general_purpose_registers_t;

typedef union gen_program_status_register gen_program_status_register_t;

/**
 * Contains the set of general purpose registers. The structure is laid out
 * so that a push {lr}, push {sp}, push {r0 - r12} in assembly will correctly
 * load the structure. After the structure is loaded sp can be used as a pointer
 * to it.
 */
struct gen_general_purpose_registers {
	size_t r0;
	size_t r1;
	size_t r2;
	size_t r3;
	size_t r4;
	size_t r5;
	size_t r6;
	size_t r7;
	size_t r8;
	size_t r9;
	size_t r10;
	size_t r11;
	size_t r12;
	size_t sp;
	size_t lr;
} PACKED;

union gen_program_status_register {
	struct {
		u32_t m        :5; ///< Mode field. This field determines the current mode of the processor.
		u32_t t        :1; ///< Thumb execution state bit. This bit and the J execution state bit, bit [24], determine the instruction set state of the processor, ARM, Thumb, Jazelle, or ThumbEE.
		u32_t f        :1; ///< Fast interrupt disable bit. Used to mask FIQ interrupts.
		u32_t i        :1; ///< Interrupt disable bit. Used to mask IRQ interrupts.
		u32_t a        :1; ///< Asynchronous abort disable bit. Used to mask asynchronous aborts.
		u32_t e        :1; ///< Endianness execution state bit. Controls the load and store endianness for data accesses.
		u32_t it_0     :6; ///< If-Then execution state bits for the Thumb IT (If-Then) instruction.
		u32_t ge       :4; ///< Greater than or Equal flags, for SIMD instructions.
		u32_t unused_0 :4;
		u32_t j        :1; ///< Jazelle bit.
		u32_t it_1     :2; ///< If-Then execution state bits for the Thumb IT (If-Then) instruction.
		u32_t q        :1; ///< Cumulative saturation flag. This flag can be read or written in any mode, and is described in The Application Program Status Register
		u32_t v        :1; ///< Overflow condition code flag.
		u32_t c        :1; ///< Carry condition code flag.
		u32_t z        :1; ///< Zero condition code flag.
		u32_t n        :1; ///< Negative condition code flag.
	} fields;
	u32_t all;
};

/**
 * @name    gen_get_sp
 * @brief   Get the stack pointer.
 *
 * @details Provides the ability to get the stack pointer of the current mode.
 *
 * @retval void *sp
 *
 * Example Usage:
 * @code
 *    sp = gen_get_sp();
 * @endcode
 */
extern void * gen_get_sp(void);

/**
 * @name    gen_set_sp
 * @brief   Set the stack pointer.
 *
 * @details Provides the ability to set the stack pointer of the current mode.
 *
 * Example Usage:
 * @code
 *    gen_set_sp(value);
 * @endcode
 */
extern void gen_set_sp(void *value);

/**
 * @name    gen_get_cpsr
 * @brief   Get the current program status register.
 *
 * @details Provides the ability to get the current program status register.
 *
 * Example Usage:
 * @code
 *    cpsr = gen_get_cpsr();
 * @endcode
 */

extern gen_program_status_register_t gen_get_cpsr(void);

/**
 * @name    gen_set_cpsr
 * @brief   Set the current program status register.
 *
 * @details Provides the ability to set the current program status register.
 *
 * Example Usage:
 * @code
 *    gen_set_cpsr(value);
 * @endcode
 */
extern void gen_set_cpsr(gen_program_status_register_t value);

/**
 * @name    gen_get_spsr
 * @brief   Get the saved program status register.
 *
 * @details Provides the ability to get the saved program status register.
 *
 * Example Usage:
 * @code
 *    spsr = gen_get_spsr();
 * @endcode
 */
extern gen_program_status_register_t gen_get_spsr(void);

/**
 * @name    gen_set_spsr
 * @brief   Set the saved program status register.
 *
 * @details Provides the ability to set the saved program status register.
 *
 * Example Usage:
 * @code
 *    gen_set_spsr(value);
 * @endcode
 */
extern void gen_set_spsr(gen_program_status_register_t value);

#endif //__C__

#ifdef __ASSEMBLY__

.extern gen_get_sp
.extern gen_set_sp
.extern gen_get_cpsr
.extern gen_set_cpsr
.extern gen_get_spsr
.extern gen_set_spsr

#endif //__ASSEMBLY__

#endif //__ARMLIB_GEN_H__
