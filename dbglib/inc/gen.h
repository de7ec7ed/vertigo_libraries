#ifndef __DBGLIB_GEN_H__
#define __DBGLIB_GEN_H__

#include <dbglib/ser.h>

#define DBG_LEVEL_0 0 // dbg off
#define DBG_LEVEL_1 1 // dbg low
#define DBG_LEVEL_2 2 // dbg medium
#define DBG_LEVEL_3 3 // dbg high

#ifdef __C__

// clear previous declarations
#undef DBG_LOG_FUNCTION
#undef DBG_LOG_STATEMENT

#define DBG_DEFINE_VARIABLE(a, b) \
	u32_t a = b

#define DBG_GET_VARIABLE(a) \
	*(u32_t *)gen_add_base(&a)

#define DBG_SET_VARIABLE(a, b) \
		*(u32_t *)gen_add_base(&a) = b;

#define DBG_LOG_FUNCTION(c, d) \
	if((*(u32_t *)gen_add_base(&c)) >= d) { SERIAL_LOG((char *)gen_add_base((char *)__FUNCTION__), __LINE__); }

#define DBG_LOG_STATEMENT(a, b, c, d) \
	if((*(u32_t *)gen_add_base(&c)) >= d) { SERIAL_LOG(gen_add_base(a), (u32_t)b); }

#endif //__C__

#endif //__DBGLIB_GEN_H__
