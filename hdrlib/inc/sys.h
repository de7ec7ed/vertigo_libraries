#ifndef __HDRLIB_SYS_H__
#define __HDRLIB_SYS_H__

#include <defines.h>
#include <types.h>

#include <hdrlib/gen.h>

#ifdef __C__

typedef struct sys_header sys_header_t;
typedef struct sys_import_header sys_import_header_t;
typedef struct sys_export_header sys_export_header_t;
typedef struct sys_storage_header sys_storage_header_t;

struct sys_import_header {
	u32_t virtual_address; // virtual base address of the flat binary
	u32_t physical_address; // physical base address of the flat binary
	u32_t size; // size of the flat binary
	u32_t operating_system; // operating system the flat binary was loaded into
} PACKED;

struct sys_export_header {
	u32_t functions_size;
	gen_export_function_t *functions;
} PACKED;

struct sys_storage_header {

} PACKED;

struct sys_header {
	u32_t reserved_0; // jump instruction
	u32_t callsign; // signature
	sys_import_header_t *import;
	sys_export_header_t *export;
	sys_storage_header_t *storage;
} PACKED;


#endif //__C__

#endif //__HDRLIB_SYS_H__
