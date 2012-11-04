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
