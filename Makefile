MKDIR := ../make

include $(MKDIR)/Makefile_arm_lib.common

.PHONY : all
.PHONY : build
.PHONY : includes
.PHONY : clean

all:
	@$(MAKE) -s clean
	@$(MAKE) -s includes
	@$(MAKE) -s build
	
build:
	@$(MAKE) -s check
	@echo "building libraries"
	@$(MAKE) -s --directory stdlib build
	#@$(MAKE) -s --directory hdrlib build
	@$(MAKE) -s --directory fxplib build
	@$(MAKE) -s --directory dbglib build
	@$(MAKE) -s --directory armv7lib build

check:
	@echo "checking toolchain"
	@if test "$(PREFIX)" = "" ; then echo "A toolchain has not been specified. Define PREFIX, for example \"make PREFIX=arm-linux-gnueabi-\""; exit 2; fi
	@if ! [ -x "`which $(LD) 2>/dev/null`" ]; then echo LD = "$(LD) not found"; exit 2; fi
	@if ! [ -x "`which $(CC) 2>/dev/null`" ]; then echo "CC = $(CC) not found"; exit 2; fi
	@if ! [ -x "`which $(AR) 2>/dev/null`" ]; then echo "AR = $(AR) not found"; exit 2; fi
	@if ! [ -x "`which $(NM) 2>/dev/null`" ]; then echo "NM = $(NM) not found"; exit 2; fi
	@if ! [ -x "`which $(OBJDUMP) 2>/dev/null`" ]; then echo "OBJDUMP = $(OBJDUMP) not found"; exit 2; fi
	@if ! [ -x "`which $(OBJCOPY) 2>/dev/null`" ]; then echo "OBJCOPY = $(OBJCOPY) not found"; exit 2; fi

includes:
	@echo "including libraries"
	@$(MAKE) -s --directory stdlib includes
	@$(MAKE) -s --directory hdrlib includes
	@$(MAKE) -s --directory fxplib includes
	@$(MAKE) -s --directory dbglib includes
	@$(MAKE) -s --directory armv7lib includes

clean:
	@echo "cleaning libraries"
	@$(MAKE) -s --directory stdlib clean
	@$(MAKE) -s --directory hdrlib clean
	@$(MAKE) -s --directory fxplib clean
	@$(MAKE) -s --directory dbglib clean
	@$(MAKE) -s --directory armv7lib clean