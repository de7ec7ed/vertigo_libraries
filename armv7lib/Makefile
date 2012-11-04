TARGET := armv7lib

MKDIR := ../../make
OBJECTSDIR := ../../objects
INCLUDESDIR := ../../includes

include $(MKDIR)/Makefile.common

HDRFILES := $(INCLUDESDIR)/defines.h $(INCLUDESDIR)/types.h
HDRFILES += $(INCDIR)/vmsa/gen.h $(INCDIR)/vmsa/mac.h $(INCDIR)/vmsa/tlb.h $(INCDIR)/vmsa/tt.h $(INCDIR)/vmsa/flt.h
HDRFILES += $(INCDIR)/cmsa/cac.h $(INCDIR)/cmsa/bpa.h $(INCDIR)/config.h
HDRFILES += $(INCDIR)/cpuid.h $(INCDIR)/exc.h
HDRFILES += $(INCDIR)/gen.h

SRCFILES := vmsa/gen.S vmsa/gen.c
SRCFILES += vmsa/tt.c vmsa/tt.S
SRCFILES += vmsa/tlb.S
SRCFILES += vmsa/flt.S

SRCFILES += cmsa/cac.S
SRCFILES += cmsa/bpa.S

SRCFILES += cpuid.S cpuid.c
SRCFILES += exc.S
SRCFILES += int.S

SRCFILES += gen.S

include $(MKDIR)/Makefile_arm_lib.common

.PHONY : all
.PHONY : build
.PHONY : includes
.PHONY : clean

all:
	@$(MAKE) clean
	@$(MAKE) includes
	@$(MAKE) build

build:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)/cmsa
	@mkdir -p $(OBJDIR)/vmsa
	@$(MAKE) -s $(TARGET)

includes:
	@echo "including $(TARGET)"
	@mkdir -p $(INCLUDESDIR)/$(TARGET)
	@cp -R $(INCDIR)/* $(INCLUDESDIR)/$(TARGET)/

clean:
	@echo "cleaning $(TARGET)"
	@rm -rf $(INCLUDESDIR)/$(TARGET)
	@rm -f $(OBJECTSDIR)/$(TARGET).o
	@rm -rf $(OBJDIR)
	@rm -rf *~
	@rm -rf $(INCDIR)/*~
	@rm -rf $(SRCDIR)/*~

$(OBJDIR)/%.S.o: $(SRCDIR)/%.S $(DEPS)
	@echo "assembling $<"
	@$(CC) $(AFLAGS) -c -D__ASSEMBLY__ -o $@ $<

$(OBJDIR)/%.c.o: $(SRCDIR)/%.c $(DEPS)
	@echo "compiling $<"
	@$(CC) $(CFLAGS) -c -D__C__ -o $@ $<

$(TARGET): $(OBJS)
	@echo "building $(TARGET)"
	@$(LD) -m armelf_linux_eabi -r -o $(OBJECTSDIR)/$(TARGET).o $(OBJS)
