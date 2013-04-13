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

#ifndef __DBG_SER_H__
#define __DBG_SER_H__

#include <types.h>

#include <dbglib/s5l8930_uart.h>
#include <dbglib/msm8960_uartdm.h>

#ifdef __SERIAL_DEBUG__
#define SERIAL_LOG(a, b) \
	ser_print(a, b)
#else
#define SERIAL_LOG
#endif //__SERIAL_DEBUG__

#ifdef __C__

extern result_t ser_init(void *va);
extern result_t ser_fini(void);

extern result_t ser_putc(u8_t c);
extern result_t ser_write(u8_t *buffer, size_t size);
extern result_t ser_getc(u8_t *c);
extern result_t ser_read(u8_t *buffer, size_t size);
extern result_t ser_print(char *string, int number);

extern void * ser_get_physical_address(void);
extern void * ser_get_virtual_address(void);
extern size_t ser_get_size(void);

#endif //__C__

#endif //__DBG_SER_H__
