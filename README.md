## SMCLib

Salonia Matteo's C Library (or `SMCLib`) is a C Library written by Salonia Matteo.

I have included example implementations using each individual library.
To see a list of examples, open the `examples` folder.

All of the function headers (and examples) use `_POSIX_C_SOURCE` `200809L`.

The following libraries are included:
+ color.h: color a string (see `color.c` for an example implementation)
	- Contains one function, `color`.

+ compiler.h: define used compiler (see `compiler.c` for an example implementation)
	- defines "CC", which will contain the name of the compiler used (CLang, GCC, or MSVC)
+ platform.h: define target architecture (see `compiler.c` for an example implementation)
	- defines "ARCH", which will contain the name of the target architecture
