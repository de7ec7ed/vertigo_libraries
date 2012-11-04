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

extern result_t ser_write(u8_t *buffer, size_t size);
extern result_t ser_read(u8_t *buffer, size_t size);
extern result_t ser_print(char *string, int number);

extern void * ser_get_physical_address(void);
extern void * ser_get_virtual_address(void);
extern size_t ser_get_size(void);

#endif //__C__

#endif //__DBG_SER_H__
