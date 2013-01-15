#ifndef __HDRLIB_KRN_H__
#define __HDRLIB_KRN_H__

#include <defines.h>
#include <types.h>

#include <hdrlib/gen.h>

#ifdef __C__

typedef struct krn_header krn_header_t;
typedef struct krn_import_header krn_import_header_t;
typedef struct krn_export_header krn_export_header_t;
typedef struct krn_storage_header krn_storage_header_t;

struct krn_import_header {
	u32_t virtual_address; // virtual base address of the flat binary
	u32_t physical_address; // physical base address of the flat binary
	u32_t size; // size of the flat binary
	u32_t operating_system; // operating system the flat binary was loaded into
} PACKED;

struct krn_export_header {
	u32_t functions_size;
	gen_export_function_t *functions;
} PACKED;

struct krn_storage_header {

} PACKED;

struct krn_header {
	u32_t reserved_0; // jump instruction
	u32_t callsign; // signature
	krn_import_header_t *import;
	krn_export_header_t *export;
	krn_storage_header_t *storage;
} PACKED;


#endif //__C__

#endif //__HDRLIB_KRN_H__
