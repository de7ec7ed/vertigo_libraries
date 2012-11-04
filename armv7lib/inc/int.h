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
