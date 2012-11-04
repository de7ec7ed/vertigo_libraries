#include <config.h>
#include <defines.h>
#include <types.h>

#include <dbglib/msm8960_uartdm.h>

result_t msm8960_uartdm_init(msm8960_uartdm_block_t *block, size_t options) {

	VARIABLE_NOT_USED(block);

	VARIABLE_NOT_USED(options);

	while(block->sr.fields.txemt == FALSE) {}

	block->cr.fields.command_channel = MSM8960_UARTDM_CR_RESET_TRANSMITTER;

	return SUCCESS;
}

result_t msm8960_uartdm_fini(msm8960_uartdm_block_t *block) {

	VARIABLE_NOT_USED(block);

	while(block->sr.fields.txemt == FALSE) {}

	block->cr.fields.command_channel = MSM8960_UARTDM_CR_RESET_TRANSMITTER;

	return SUCCESS;
}

result_t msm8960_uartdm_set_clock(msm8960_uartdm_block_t *block) {

	VARIABLE_NOT_USED(block);

	// TODO: lots of freq and clock stuff.

	return FAILURE;
}

result_t msm8960_uartdm_write(msm8960_uartdm_block_t *block, u8_t *buffer, size_t size) {

	size_t i;

	for(i = 0; i < size; i++) {
		if(msm8960_uartdm_putc(block, buffer[i]) != SUCCESS) {
			return FAILURE;
		}
	}

	// wait for the fifo to clear
	// the OS does't like us using it and
	// returning with data still in the
	// fifo

	while(block->sr.fields.txemt == FALSE) {}

	return SUCCESS;
}

result_t msm8960_uartdm_read( msm8960_uartdm_block_t *block, u8_t *buffer, size_t size) {

	size_t i;

	for(i = 0; i < size; i++) {
		if(msm8960_uartdm_getc(block, &(buffer[i])) != SUCCESS) {
			return FAILURE;
		}
	}

	return FAILURE;
}

result_t msm8960_uartdm_putc(msm8960_uartdm_block_t *block, u8_t c) {

	size_t i;

	for(i = 0; i < MSM8960_UARTDM_TX_TIMEOUT_PERIOD; i++) {
		if(block->sr.fields.txrdy == TRUE) {
			block->dmtx.all = 0x1;
			block->tf.all = c;
			return SUCCESS;
		}
	}

	return FAILURE;
}

result_t msm8960_uartdm_getc(msm8960_uartdm_block_t *block, u8_t *c) {

	size_t i;

	for(i = 0; i < MSM8960_UARTDM_RX_TIMEOUT_PERIOD; i++) {
		if(block->sr.fields.rxrdy == TRUE) {
			*c = block->rf.all;
			return SUCCESS;
		}
	}

	return FAILURE;
}
