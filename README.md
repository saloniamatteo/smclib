## SMCLib

Salonia Matteo's C Library (or `SMCLib`) is a C Library written by Salonia Matteo.

I have included example implementations using each individual library.
To see a list of examples, open the `examples` folder.

All of the function headers (and examples) use `_POSIX_C_SOURCE` `200809L`.

### Using a Library
Simply `#include "library.h"` in your C source code, making sure you have a copy of `library.h` in your current directory.
(NOTE: Obviously, `library.h` refers to a Library in this repository)

### Compiling Examples
For every Library, at least one example file is included.

If you want to compile all of the examples in the example folder, run:
```bash
cd smclib/examples
make
```

If you just want to compile a single example, run:
```bash
cd smclib/examples
make [example]
```

Where `[example]` is the name of a library. (See below)

### Included Libraries
+ color.h: color a string (see `color.c` for an example implementation)
	- Contains one function, `color`.

+ compiler.h: define used compiler (see `compiler.c` for an example implementation)
	- defines "CC", which will contain the name of the compiler used (CLang, GCC, or MSVC)
+ platform.h: define target architecture (see `compiler.c` for an example implementation)
	- defines "ARCH", which will contain the name of the target architecture
