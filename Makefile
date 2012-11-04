.PHONY : all
.PHONY : build
.PHONY : includes
.PHONY : clean

all:
	@$(MAKE) -s clean
	@$(MAKE) -s includes
	@$(MAKE) -s build
	
build:
	@echo "building libraries"
	@$(MAKE) -s --directory stdlib build
	#@$(MAKE) -s --directory hdrlib build
	@$(MAKE) -s --directory fxplib build
	@$(MAKE) -s --directory dbglib build
	@$(MAKE) -s --directory armv7lib build

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