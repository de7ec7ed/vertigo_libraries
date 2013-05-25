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

#include <dbglib/exynos5250_uart.h>

result_t exynos5250_uart_init(exynos5250_uart_block_t *block, size_t options) {

	UNUSED_VARIABLE(block);

	UNUSED_VARIABLE(options);

	return SUCCESS;
}

result_t exynos5250_uart_fini(exynos5250_uart_block_t *block) {

	UNUSED_VARIABLE(block);


	block->ufcon.fields.rfifor = TRUE;
	block->ufcon.fields.tfifor = TRUE;

	return SUCCESS;
}

result_t exynos5250_uart_set_clock(exynos5250_uart_block_t *block) {

	UNUSED_VARIABLE(block);

	// TODO: lots of freq and clock stuff.

	return FAILURE;
}

result_t exynos5250_uart_write(exynos5250_uart_block_t *block, u8_t *buffer, size_t size) {

	size_t i;

	for(i = 0; i < size; i++) {
		if(exynos5250_uart_putc(block, buffer[i]) != SUCCESS) {
			return FAILURE;
		}
	}

	// wait for the fifo to clear
	// the OS does't like us using it and
	// returning with data still in the
	// fifo
	while(block->utrstat.fields.te == FALSE) {}

	return SUCCESS;
}

result_t exynos5250_uart_read( exynos5250_uart_block_t *block, u8_t *buffer, size_t size) {

	size_t i;

	for(i = 0; i < size; i++) {
		if(exynos5250_uart_getc(block, &(buffer[i])) != SUCCESS) {
			return FAILURE;
		}
	}

	return FAILURE;
}

result_t exynos5250_uart_putc(exynos5250_uart_block_t *block, u8_t c) {

	size_t i;

	for(i = 0; i < EXYNOS5250_UART_TX_TIMEOUT_PERIOD; i++) {
		if(block->utrstat.fields.tbe == TRUE) {
			block->utxh.u8 = c;
			return SUCCESS;
		}
	}

	return FAILURE;
}

result_t exynos5250_uart_getc(exynos5250_uart_block_t *block, u8_t *c) {

	size_t i;

	for(i = 0; i < EXYNOS5250_UART_RX_TIMEOUT_PERIOD; i++) {
		if(block->utrstat.fields.rbdr == TRUE) {
			*c = block->urxh.u8;
			return SUCCESS;
		}
	}

	return FAILURE;
}
