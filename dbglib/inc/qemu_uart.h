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

#ifndef __DBG_QEMU_UART_H__
#define __DBG_QEMU_UART_H__

#include <config.h>
#include <defines.h>
#include <types.h>

#define QEMU_UART_ADDRESS 0xFF012000
#define QEMU_UART_SIZE    0x1000

#define QEMU_UART_CMD_INT_DISABLE  0x0
#define QEMU_UART_CMD_INT_ENABLE   0x1
#define QEMU_UART_CMD_WRITE_BUFFER 0x2
#define QEMU_UART_CMD_READ_BUFFER 0x3

#ifdef __C__

#ifdef __DBGLIB_QEMU__
#define SER_INIT(a, b) qemu_uart_init(a, b)
#define SER_PUTC(a, b) qemu_uart_putc(a, b)
#define SER_WRITE(a, b, c) qemu_uart_write(a, b, c)
#define SER_FINI(a) qemu_uart_fini(a)
typedef volatile struct qemu_uart_block ser_block_t;
#define SER_PHYSICAL_ADDRESS QEMU_UART_ADDRESS
#define SER_VIRTUAL_ADDRESS 0xFE012000
#define SER_SIZE QEMU_UART_SIZE
#endif //__DBGLIB_QEMU__


typedef union qemu_uart_generic_register qemu_uart_put_char_register_t;
typedef union qemu_uart_generic_register qemu_uart_bytes_ready_register_t;
typedef union qemu_uart_generic_register qemu_uart_cmd_register_t;
typedef union qemu_uart_generic_register qemu_uart_data_ptr_t;
typedef union qemu_uart_generic_register qemu_uart_data_len_t;

typedef volatile struct qemu_uart_block qemu_uart_block_t;

union qemu_uart_generic_register {
	u8_t  u8;
	u16_t u16;
	u32_t all;
};

struct qemu_uart_block {
	qemu_uart_put_char_register_t put_char;
	qemu_uart_bytes_ready_register_t bytes_ready;
	qemu_uart_cmd_register_t cmd;
	qemu_uart_data_ptr_t data_ptr;
	qemu_uart_data_len_t data_len;
} PACKED;

result_t qemu_uart_init(qemu_uart_block_t *block, size_t options);
result_t qemu_uart_fini(qemu_uart_block_t *block);

result_t qemu_uart_write(qemu_uart_block_t *block, u8_t *buffer, size_t size);
result_t qemu_uart_putc(qemu_uart_block_t *block, u8_t c);

#endif //__C__


#endif //__DBG_QEMU_UART_H__

