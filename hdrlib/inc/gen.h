#ifndef __HDRLIB_GEN_H__
#define __HDRLIB_GEN_H__

#include <defines.h>
#include <types.h>

#define GEN_IMPORT_OPERATING_SYSTEM_IOS            1
#define GEN_IMPORT_OPERATING_SYSTEM_ANDROID        2
#define GEN_IMPORT_OPERATING_SYSTEM_WINDOWS_MOBILE 3
#define GEN_IMPORT_OPERATING_SYSTEM_SYMBIAN        4

#ifdef __C__

typedef struct gen_import_function gen_import_function_t;

typedef struct gen_export_function gen_export_function_t;

struct gen_import_function {
	u32_t size; // size of the entire entry
	u32_t address;
	u8_t string[];
} PACKED;

struct gen_export_function {
	u32_t size; // size of the entire entry
	u32_t address;
	u8_t string[];
} PACKED;

#endif //__C__

#ifdef __ASSEMBLY__

.macro GEN_IMPORT_FUNCTION name

1:
VARIABLE(size_\name) .word (2f - 1b)

VARIABLE(address_\name) .word 0

VARIABLE(string_\name) .asciz "\name"

FUNCTION(\name)
ldr pc, address_\name
2:

.endm

.macro GEN_EXPORT_FUNCTION name

1:
VARIABLE(size_\name) .word (2f - 1b)

VARIABLE(address_\name) .word \name

VARIABLE(string_\name) .asciz "\name"
2:

.endm

#endif //__ASSEMBLY__

#endif //__HDRLIB_GEN_H__
