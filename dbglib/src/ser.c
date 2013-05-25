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

#include <stdlib/string.h>

#include <fxplib/gen.h>

#include <dbglib/s5l8930_uart.h>
#include <dbglib/msm8960_uartdm.h>
#include <dbglib/exynos5250_uart.h>

ser_block_t *ser_block = NULL;

result_t ser_init(void *va) {

	ser_block_t **sb;

	if(va == NULL) {
		return FAILURE;
	}

	sb = gen_add_base(&ser_block);

	if(*sb != NULL) {
		return FAILURE;
	}

	*sb = (ser_block_t *)va;

	if(SER_INIT(*sb, 0) != SUCCESS) {
		return FAILURE;
	}

	return SUCCESS;
}

result_t ser_fini(void) {

	ser_block_t **sb;

	sb = gen_add_base(&ser_block);

	if(*sb == NULL) {
		return FAILURE;
	}

	if(SER_FINI(*sb) != SUCCESS) {
		return FAILURE;
	}

	*sb = NULL;

	return SUCCESS;
}

result_t ser_putc(u8_t c) {

	ser_block_t **sb;

	sb = gen_add_base(&ser_block);

	if(*sb == NULL) {
		return FAILURE;
	}

	return SER_PUTC(*sb, c);
}

result_t ser_write(u8_t *buffer, size_t size) {

	ser_block_t **sb;

	sb = gen_add_base(&ser_block);

	if(*sb == NULL) {
		return FAILURE;
	}

	if(buffer == NULL) {
		return FAILURE;
	}

	return SER_WRITE(*sb, buffer, size);
}

result_t ser_getc(u8_t *c) {

	ser_block_t **sb;

	sb = gen_add_base(&ser_block);

	if(*sb == NULL) {
		return FAILURE;
	}

	if(c == NULL) {
		return FAILURE;
	}

	return SER_GETC(*sb, c);
}

result_t ser_read(u8_t *buffer, size_t size) {

	ser_block_t **sb;

	sb = gen_add_base(&ser_block);

	if(*sb == NULL) {
		return FAILURE;
	}

	if(buffer == NULL) {
		return FAILURE;
	}

	return SER_READ(*sb, buffer, size);
}

result_t ser_print(char *string, int number) {

	size_t length;
	char *format = " : 0x";
	u8_t number_string[8];

	length = strlen(string);

	if(ser_write((u8_t *)string, length) != SUCCESS) {
		return FAILURE;
	}

	if(ser_write(gen_add_base(format), 5) != SUCCESS) {
		return FAILURE;
	}

	itoa(number, (char *)number_string, 16);

	if(ser_write(number_string, strlen((char *)number_string)) != SUCCESS) {
		return FAILURE;
	}

	if(ser_write(gen_add_base("\r\n"), 2) != SUCCESS) {
		return FAILURE;
	}

	return SUCCESS;
}

void * ser_get_physical_address(void) {
	return (void *)SER_PHYSICAL_ADDRESS;
}

void * ser_get_virtual_address(void) {
	return (void *)SER_VIRTUAL_ADDRESS;
}

size_t ser_get_size(void) {
	return SER_SIZE;
}
