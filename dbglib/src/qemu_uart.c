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
#include <types.h>

#include <dbglib/qemu_uart.h>

result_t qemu_uart_init(qemu_uart_block_t *block, size_t options) {

	UNUSED_VARIABLE(block);

	UNUSED_VARIABLE(options);

	return SUCCESS;
}

result_t qemu_uart_fini(qemu_uart_block_t *block) {

	UNUSED_VARIABLE(block);

	return SUCCESS;
}

result_t qemu_uart_write(qemu_uart_block_t *block, u8_t *buffer, size_t size) {

	size_t i;

	for(i = 0; i < size; i++) {
		if(qemu_uart_putc(block, buffer[i]) != SUCCESS) {
			return FAILURE;
		}
	}

	return SUCCESS;
}

result_t qemu_uart_putc(qemu_uart_block_t *block, u8_t c) {

	block->put_char.u8 = c;

	return SUCCESS;
}
