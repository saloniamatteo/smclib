# Written by Salonia Matteo on 01/06/2021

# Which compiler to use
CC = gcc

# LINKER: choose a linker to use; can be bfd, gold, lld
# comment to use the default linker, uncomment to use a custom linker
#LINKER = -fuse-ld=gold

# CSTD: which C revision to use
CSTD = -std=c99

# Optimizations. Can be -O0, -O1, -O2, -O3, -Os, -Ofast
OPTS = -Ofast

# CFLAGS: additional compiler flags
AM_CFLAGS = -Wall $(CSTD) $(LINKER) $(OPTS) $(CPUOPTS)

# Flags for aclocal
ACLOCAL_AMFLAGS = -I m4

# Available headers
include_HEADERS = lib/color.h
include_HEADERS += lib/compiler.h
include_HEADERS += lib/platform.h
include_HEADERS += lib/temp.h
include_HEADERS += lib/smclib.h		# Always leave this below

# SMCLib library (installed as libsmc)
lib_LTLIBRARIES = libsmc.la
libsmc_la_SOURCES = ${include_HEADERS}

# Build examples after building libraries
bin_PROGRAMS = examples/smclib examples/color examples/compiler examples/cputemp examples/temp

# SMCLib main file
examples_smclib_LDADD = libsmc.la
examples_smclib_SOURCES = src/smclib.c

# Color
examples_color_LDADD = libsmc.la
examples_color_SOURCES = src/color.c

# Compiler & Platform
examples_compiler_LDADD = libsmc.la
examples_compiler_SOURCES = src/compiler.c

# CPU Temp
examples_cputemp_LDADD = libsmc.la
examples_cputemp_SOURCES = src/cputemp.c

# Temp
examples_temp_LDADD = libsmc.la
examples_temp_SOURCES = src/temp.c

# Clean the project directory
cleandir:
	make mostlyclean
	make clean
	make distclean
	rm -rf autom4te.cache aclocal.m4 *.tar.gz examples

headers:
	@echo "Headers are installed under /usr/local/include."
	@echo "Available headers: ${include_HEADERS}"

info:
	@echo "${PACKAGE_STRING} made by ${AUTHOR}."
	@echo "Report any bugs to ${PACKAGE_BUGREPORT}."
	@echo "Homepage: ${PACKAGE_URL}"
	@echo "Support this project: ${PACKAGE_DONATE}"

version:
	@echo ${VERSION}
