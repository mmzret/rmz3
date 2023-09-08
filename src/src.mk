clean-src: clean-analysis clean-libs
	@rm -f src/*.[o.s]
	@rm -f src/data/*.[o.s]
	@rm -f src/weapon/*.[o.s]

clean-analysis:
	@rm -f ./src/analysis/diskAnalysisScript.s
	@rm -f ./src/analysis/*.o

clean-libs: 
	@rm -f src/libs/agb_sram.s
	@rm -f src/libs/m4a.s
	@rm -f src/libs/m4a_tables.s
	@rm -f src/libs/*.o
