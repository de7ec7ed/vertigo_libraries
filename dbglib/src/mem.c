#include <config.h>

#include <defines.h>
#include <types.h>

#include <dbglib/mem.h>
#include <fxplib/gen.h>
#include <stdlib/string.h>

u8_t mem_buffer[MEM_LOG_SIZE] = {0};
u32_t mem_buffer_index = 0;

result_t mem_init(void) {

	return mem_clear();
}

result_t mem_fini(void) {

	return mem_clear();
}

result_t mem_clear(void) {

	u8_t *buffer;
	u32_t *index;

	buffer = gen_add_base(&mem_buffer);
	index = gen_add_base(&mem_buffer_index);

	memset(buffer, 0, MEM_LOG_SIZE);

	*index = 0;

	return SUCCESS;
}

result_t mem_write(u8_t *buffer, size_t size) {

	u32_t *index;

	index = gen_add_base(&mem_buffer_index);

	if(buffer == NULL) {
		return FAILURE;
	}

	if(size > (MEM_LOG_SIZE - (*index))) {
		mem_clear();
	}

	while(*buffer && size--) {
		if(mem_putc(*buffer++) == FAILURE) {
			return FAILURE;
		}
	}

	return SUCCESS;
}

result_t mem_putc(u8_t c) {

	u8_t *buffer;
	u32_t *index;

	buffer = gen_add_base(&mem_buffer);
	index = gen_add_base(&mem_buffer_index);


	if(sizeof(u8_t) > (MEM_LOG_SIZE - (*index))) {
		mem_clear();
	}

	if((*index) < MEM_LOG_SIZE) {
		buffer[*index] = c;
		(*index)++;
	}
	else {
		return FAILURE;
	}

	return SUCCESS;
}

result_t mem_print(char *string, unsigned long number) {

	size_t length;
	char *format = " : 0x";
	u8_t number_string[8];
	u32_t *index;

	index = gen_add_base(&mem_buffer_index);

	if(string == NULL) {
		return FAILURE;
	}

	length = strlen(string);


	if((length + sizeof(number_string) + 2) > (MEM_LOG_SIZE - (*index))) {
		mem_clear();
	}

	if(mem_write((u8_t *)string, length) != SUCCESS) {
		return FAILURE;
	}

	if(mem_write(gen_add_base(format), 5) != SUCCESS) {
		return FAILURE;
	}

	ltoa(number, (char *)number_string, 16);

	if(mem_write(number_string, strlen((char *)number_string)) != SUCCESS) {
		return FAILURE;
	}

	if(mem_write(gen_add_base("\r\n"), 2) != SUCCESS) {
		return FAILURE;
	}

	return SUCCESS;
}

result_t mem_get_buffer_size(u32_t *size) {

	if(size == NULL) {
		return FAILURE;
	}

	*size = *(u32_t *)gen_add_base(&mem_buffer_index);

	return SUCCESS;
}


result_t mem_get_buffer(u8_t *buffer) {

	u8_t *tmp;
	u32_t *index;

	tmp = gen_add_base(&mem_buffer);
	index = gen_add_base(&mem_buffer_index);

	if(buffer == NULL) {
		return FAILURE;
	}

	memcpy(buffer, tmp, (*index));

	return SUCCESS;
}
