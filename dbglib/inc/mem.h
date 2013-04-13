#ifndef __DBGLIB_MEM_H__
#define __DBGLIB_MEM_H__

#include <defines.h>
#include <types.h>

#define MEM_LOG_SIZE FOUR_KILOBYTES

#ifdef __C__

#ifdef __MEMORY_DEBUG__
#define MEMORY_LOG(a, b) \
	mem_print(a, b)
#else
#define MEMORY_LOG(a, b)
#endif //__MEMORY_DEBUG__


extern result_t mem_init(void);
extern result_t mem_fini(void);

extern result_t mem_clear(void);

extern result_t mem_putc(u8_t c);
extern result_t mem_write(u8_t *buffer, size_t cnt);
extern result_t mem_print(char *string, unsigned long number);

extern result_t mem_get_buffer_size(u32_t *size);
extern result_t mem_get_buffer(u8_t *buffer);

#endif //__C__

#endif /* __DBGLIB_MEM_H__ */

