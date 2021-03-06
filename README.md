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
	- Declares and Assigns float `_smclib_ver`, which contains this Library's version;
	Also contains function prototypes.

+ `color.h`: Color a string.
	- Contains two functions, `color`, and `_free_color`, which frees allocated memory.

+ `compiler.h`: Define Compiler used.
	- Defines `CC`, which will contain the name of the compiler used (`CLang`, `GCC`, or `MSVC`).

+ `platform.h`: Define Target Architecture.
	- Defines `ARCH`, which will contain the name of the target architecture,
	as well as `OS`, which contains the name of the Operating System (`WIN32`, `UNIX`, `UNKNOWN`).

+ `cputemp.h`: Get current CPU temperature.
	- Defines `CPUTEMP_RD_PATH`, which is the location used to read the CPU
	temperature; has 3 functions: `get_temp()` (get temp in Celsius),
	`get_temp_k()` (get temp in Kelvin), `get_temp_f()` (get temp in Fahrenheit).

+ `temp.h`: Convert temperatures.
	- Has 4 functions: `celsius_to()` (convert from Celsius to Kelvin/Fahrenheit),
	`kelvin_to()` (convert from Kelvin to Celsius/Fahrenheit),
	`fahrenheit_to()` (convert from Fahrenheit to Celsius/Kelvin),
	`temp_conv()` (meta-function for conversions).

### Custom Makefile rules
In addition to the regular `make` and `make install` command, you can run the following:

+ `make cleandir`: Clean the current directory
(used after updating configure.ac, Makefile.am, etc.)
+ `make headers`: Print the available headers.
+ `make info`: Print information regarding this project.
+ `make version`: Print the current SMCLib version.
