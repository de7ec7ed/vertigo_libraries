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
#include <dbglib/s5l8930_uart.h>

result_t s5l8930_uart_init(s5l8930_uart_block_t *block, size_t options) {

	UNUSED_VARIABLE(block);

	UNUSED_VARIABLE(options);

	// TODO: Stuff to init the uart block
	// I think polling mode is all that is needed.
	// The PCLK, UBRDIV and UDIVSLOT are the things
	// that are stopping this right now. It is going
	// to require a lot more  reading before I can
	// do this from scratch.

	// FIXME: for now we will rely on the loader to
	// setup the serial port correctly for us

	return SUCCESS;
}

result_t s5l8930_uart_fini(s5l8930_uart_block_t *block) {

	UNUSED_VARIABLE(block);

	// TODO: I'm not sure if there will ever be anything
	// that needs to be done here. Maybe backup the old
	// s5l8930_uart_block during init and restore the state here.

	return SUCCESS;
}

result_t s5l8930_uart_write(s5l8930_uart_block_t *block, u8_t *buffer, size_t size) {

	size_t i;

	for(i = 0; i < size; i++) {
		if(s5l8930_uart_putc(block, buffer[i]) != SUCCESS) {
			return FAILURE;
		}
	}

	return SUCCESS;
}

result_t s5l8930_uart_putc( s5l8930_uart_block_t *block, u8_t c) {

	size_t i;

	for(i = 0; i < S5L8930_UART_TX_TIMEOUT_PERIOD; i++) {
		if(block->utrstat.fields.tbe == TRUE) {
			block->utxh.u8 = c;
			return SUCCESS;
		}
	}

	return FAILURE;
}
