TARGET := hdrlib

MKDIR := ../../make
INCLUDESDIR := ../../includes

include $(MKDIR)/Makefile.common

HDRFILES := $(INCLUDESDIR)/defines.h $(INCLUDESDIR)/types.h
HDRFILES += $(INCDIR)/gen.h $(INCDIR)/sys.h $(INCDIR)/mod.h

include $(MKDIR)/Makefile_arm_fb.common

.PHONY : all
.PHONY : includes
.PHONY : clean

all:
	@$(MAKE) clean
	@$(MAKE) includes
	
includes:
	@echo "including $(TARGET)"
	@mkdir -p $(INCLUDESDIR)/$(TARGET)
	@cp -R $(INCDIR)/* $(INCLUDESDIR)/$(TARGET)/

clean:
	@echo "cleaning $(TARGET)"
	@rm -rf $(INCLUDESDIR)/$(TARGET)
	@rm -rf *~
	@rm -rf $(INCDIR)/*~
