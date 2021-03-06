TARGET := fxplib

MKDIR := ../../make
OBJECTSDIR := ../../objects
INCLUDESDIR := ../../includes

include $(MKDIR)/Makefile.common

HDRFILES := $(INCLUDESDIR)/defines.h $(INCLUDESDIR)/types.h
HDRFILES += $(INCDIR)/gen.h $(INCDIR)/config.h

SRCFILES := gen.S gen.c
SRCFILES += div.S

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
	echo "assembling $<"
	@$(CC) $(CFLAGS) -c -D__ASSEMBLY__ -o $@ $<

$(OBJDIR)/%.c.o: $(SRCDIR)/%.c $(DEPS)
	echo "compiling $<"
	@$(CC) $(CFLAGS) -c -D__C__ -o $@ $<

$(TARGET): $(OBJS)
	echo "building $(TARGET)"
	@$(LD) -m armelf_linux_eabi -r -o $(OBJECTSDIR)/$(TARGET).o $(OBJS)
