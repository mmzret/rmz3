AGB_LIBS_DIR := ./src/libs/

clean-libs: 
	rm -f $(AGB_LIBS_DIR)agb_sram.s
	rm -f $(AGB_LIBS_DIR)m4a.s
	rm -f $(AGB_LIBS_DIR)m4a_tables.s
	rm -f $(AGB_LIBS_DIR)*.o
