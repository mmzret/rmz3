include src/analysis/analysis.mk
include src/libs/libs.mk
include src/data/data.mk

clean-src: clean-analysis clean-libs clean-srcdata
	rm -f src/*.o
	rm -f src/*.s
