# CC: can be gcc, clang, or a compiler of your choice
CC = gcc
# OPTS: can be -O0, -O1, -O2, -O3, -Os, -Ofast
OPTS = -Ofast
# ARCH & TUNE: modify to compile exclusively for a CPU 
ARCH = native
TUNE = native
# CFLAGS: additional compiler flags
CFLAGS = -Wall -D_POSIX_C_SOURCE=200809L
# LINKER: choose a linker to use; can be bfd, gold, lld
# comment to use the default linker, uncomment to use a custom linker
#LINKER = -fuse-ld=gold
# CSTD: which C revision to use
CSTD = c99

all: color color-new compiler platform

# color
color: color.o
	$(CC) color.o -o color $(CFLAGS) $(OPTS) $(LINKER) -march=$(ARCH) -mtune=$(TUNE) -std=$(CSTD)

color.o: color.c ../color.h
	$(CC) -c color.c $(CFLAGS) $(OPTS) $(LINKER) -march=$(ARCH) -mtune=$(TUNE) -std=$(CSTD)

# color-new
color-new: color-new.o
	$(CC) color-new.o -o color-new $(CFLAGS) $(OPTS) $(LINKER) -march=$(ARCH) -mtune=$(TUNE) -std=$(CSTD)

color-new.o: color-new.c ../color-new.h
	$(CC) -c color-new.c $(CFLAGS) $(OPTS) $(LINKER) -march=$(ARCH) -mtune=$(TUNE) -std=$(CSTD)

# compiler & platform
platform: compiler

compiler: compiler.o
	$(CC) compiler.o -o compiler $(CFLAGS) $(OPTS) $(LINKER) -march=$(ARCH) -mtune=$(TUNE) -std=$(CSTD)

compiler.o: compiler.c ../compiler.h ../platform.h
	$(CC) -c compiler.c $(CFLAGS) $(OPTS) $(LINKER) -march=$(ARCH) -mtune=$(TUNE) -std=$(CSTD)

clean:
	rm -f *.o color color-new compiler

.PHONY: all clean color color-new compiler platform
