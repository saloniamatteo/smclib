## SMCLib

Salonia Matteo's C Library (or `SMCLib`) is a C Library written by Salonia Matteo.

I have included at least one example implementation for each individual library.

Libraries are located under `lib/`, and examples are located under `src/`.

All of the function headers (and examples) use `_POSIX_C_SOURCE` `200809L`.

### Installation
SMCLib uses GNU AutoTools, to increase portability. To install libraries
under `/usr/local/include`, run the following commands:

```bash
./configure
make
# run the following command as root,
# or by prepending doas/sudo
make install
```

This will compile both libraries, and examples.

NOTE: SMCLib will be installed as a shared (and static) library, under /usr/local/lib,
with the name `libsmc`.

### Using Libraries
Just `#include <smclib.h>` in your C source code, making sure you installed libraries.
It's also possible to only include a library: for example, include only the
"color.h" library:

```c
#include <stdio.h>
#include <color.h>

int
main(void)
{
	/* some code... */
	return 0;
}
```

### Included Libraries
+ `smclib.h`: The SMCLib Meta-Library.
	- Defines variable (float) `_smclib_ver`, which contains this Library's version;
	Also contains function prototypes.

+ `color.h`: Color a string.
	- Contains two functions, `color`, and `_free_color`, which frees allocated memory.

+ `compiler.h`: Define Compiler used.
	- Defines `CC`, which will contain the name of the compiler used (`CLang`, `GCC`, or `MSVC`).

+ `platform.h`: Define Target Architecture
	- Defines `ARCH`, which will contain the name of the target architecture.

### Custom Makefile rules
In addition to the regular `make` and `make install` command, you can run the following:

+ `make cleandir`: Clean the current directory
(used after updating configure.ac, Makefile.am, etc.)
+ `make headers`: Print the available headers.
+ `make info`: Print information regarding this project.
+ `make version`: Print the current SMCLib version.
