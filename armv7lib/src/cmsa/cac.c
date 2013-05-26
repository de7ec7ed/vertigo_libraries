#include <config.h>
#include <defines.h>
#include <types.h>

#include <armv7lib/cpuid.h>
#include <armv7lib/cmsa/bpa.h>
#include <armv7lib/vmsa/gen.h>
#include <armv7lib/vmsa/tt.h>

#include <armv7lib/cmsa/cac.h>

void cac_clean_cache_region(void *va, size_t size) {

	cac_clean_data_cache_region(va, size);

	return;
}

void cac_invalidate_cache_region(void *va, size_t size) {

	cac_invalidate_instruction_cache_region(va, size);
	cac_invalidate_data_cache_region(va, size);

	return;
}

void cac_invalidate_instruction_cache_region(void *va, size_t size) {

	cpuid_cache_type_register_t ctr;
	size_t line;
	void *tmp;

	gen_data_synchronization_barrier();

	ctr = cpuid_get_ctr();

	line = (0x1 << (size_t)(ctr.fields.iminline)) * sizeof(size_t);

	for(tmp = (void *)((size_t)va & ~(line - 1)); (size_t)tmp < ((size_t)va + size); tmp = (void *)((size_t)tmp + line)) {
		cac_invalidate_mva_to_pou_instruction_cache(tmp);
		bpa_flush_mva_branch_predictor_array(tmp);
	}

	gen_data_synchronization_barrier();
	gen_instruction_synchronization_barrier();

	return;
}

void cac_invalidate_data_cache_region(void *va, size_t size) {

	cpuid_cache_type_register_t ctr;
	size_t line;
	void *tmp;

	gen_data_synchronization_barrier();

	ctr = cpuid_get_ctr();

	line = (0x1 << (size_t)(ctr.fields.dminline)) * sizeof(size_t);

	for(tmp = (void *)((size_t)va & ~(line - 1)); (size_t)tmp < ((size_t)va + size); tmp = (void *)((size_t)tmp + line)) {
		cac_invalidate_mva_to_poc_data_cache(tmp);
	}

	gen_data_synchronization_barrier();
	gen_instruction_synchronization_barrier();

	return;
}

void cac_clean_data_cache_region(void *va, size_t size) {

	cpuid_cache_type_register_t ctr;
	size_t line;
	void *tmp;

	gen_data_synchronization_barrier();

	ctr = cpuid_get_ctr();

	line = (0x1 << (size_t)(ctr.fields.dminline)) * sizeof(size_t);

	for(tmp = (void *)((size_t)va & ~(line - 1)); (size_t)tmp < ((size_t)va + size); tmp = (void *)((size_t)tmp + line)) {
		cac_clean_mva_to_poc_data_cache(tmp);
	}

	gen_data_synchronization_barrier();
	gen_instruction_synchronization_barrier();

	return;
}

void cac_flush_entire_cache(void) {

	cac_flush_entire_data_cache();
	cac_flush_entire_instruction_cache();
	bpa_flush_entire_branch_predictor_array();

	gen_data_synchronization_barrier();
	gen_instruction_synchronization_barrier();

	return;
}

void cac_flush_cache_region(void *va, size_t size) {

	cac_clean_data_cache_region(va, size);
	cac_invalidate_data_cache_region(va, size);
	cac_invalidate_instruction_cache_region(va, size);

	gen_data_synchronization_barrier();
	gen_instruction_synchronization_barrier();

	return;
}
