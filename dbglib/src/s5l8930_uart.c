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

result_t s5l8930_uart_set_clock(s5l8930_uart_block_t *block) {

	UNUSED_VARIABLE(block);

	// TODO: lots of freq and clock stuff.

	return FAILURE;
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

result_t s5l8930_uart_read( s5l8930_uart_block_t *block, u8_t *buffer, size_t size) {

	size_t i;

	for(i = 0; i < size; i++) {
		if(s5l8930_uart_getc(block, &(buffer[i])) != SUCCESS) {
			return FAILURE;
		}
	}

	return FAILURE;
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

result_t s5l8930_uart_getc(s5l8930_uart_block_t *block, u8_t *c) {

	size_t i;

	for(i = 0; i < S5L8930_UART_RX_TIMEOUT_PERIOD; i++) {
		if(block->utrstat.fields.rbdr == TRUE) {
			*c = block->urxh.u8;
			return SUCCESS;
		}
	}

	return FAILURE;
}
