#include <config.h>
#include <defines.h>
#include <types.h>

#include <armv7lib/vmsa/gen.h>
#include <armv7lib/vmsa/tt.h>

#include <armv7lib/vmsa/tlb.h>

void tlb_invalidate_tlb_region(tt_virtual_address_t va, size_t size) {

	tt_virtual_address_t tmp;

	va.all &= ~(TT_SMALL_PAGE_SIZE);

	for(tmp.all = va.all; tmp.all < (va.all + size); tmp.all += TT_SMALL_PAGE_SIZE) {
		tlb_invalidate_mva_unified_tlb(tmp);
		tlb_invalidate_mva_data_tlb(tmp);
		tlb_invalidate_mva_instruction_tlb(tmp);
	}

	gen_data_synchronization_barrier();
	gen_instruction_synchronization_barrier();

	return;
}

void tlb_invalidate_entire_tlb(void) {

	tlb_invalidate_entire_unified_tlb();
	tlb_invalidate_entire_data_tlb();
	tlb_invalidate_entire_instruction_tlb();

	gen_data_synchronization_barrier();
	gen_instruction_synchronization_barrier();

	return;
}
