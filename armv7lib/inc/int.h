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

/**
 * @file
 *
 * @brief API for interrupts on the ARMv7 architecture.
 *
 * @details Includes getters and setters for IRQs and FIQs.
 */

#ifndef __INT_H__
#define __INT_H__

#ifdef __C__

/**
 * @name    int_disable_irq
 * @brief   Disables IRQs.
 *
 * @details Provides the ability to disable IRQs.
 *
 * Example Usage:
 * @code
 *    int_disable_irq();
 * @endcode
 */
void int_disable_irq(void);

/**
 * @name    int_enable_irq
 * @brief   Enables IRQs.
 *
 * @details Provides the ability to Enable IRQs.
 *
 * Example Usage:
 * @code
 *    int_enable_irq();
 * @endcode
 */
void int_enable_irq(void);

/**
 * @name    int_disable_fiq
 * @brief   Disables FIQs.
 *
 * @details Provides the ability to disable FIQs.
 *
 * Example Usage:
 * @code
 *    int_disable_fiq();
 * @endcode
 */
void int_disable_fiq(void);

/**
 * @name    int_enable_FIQ
 * @brief   Enables FIQs.
 *
 * @details Provides the ability to Enable FIQs.
 *
 * Example Usage:
 * @code
 *    int_enable_fiq();
 * @endcode
 */
void int_enable_fiq(void);

#endif //__C__

#ifdef __ASSEMBLY__

.extern int_disable_irq
.extern int_enable_irq
.extern int_disable_fiq
.extern int_enable_fiq

#endif //__ASSEMBLY__

#endif //__INT_H__
