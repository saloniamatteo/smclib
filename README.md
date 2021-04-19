## SMCLib

Salonia Matteo's C Library (or `SMCLib`) is a C Library written by Salonia Matteo.

I have included at least one example implementation for each individual library.
To see a list of examples, open the [`examples`](https://github.com/saloniamatteo/smclib/tree/master/examples) folder.

All of the function headers (and examples) use `_POSIX_C_SOURCE` `200809L`.

### Using a Library
Just `#include "smclib.h"` in your C source code, making sure you have a copy of `smclib.h` in your current directory,
as well as the other libraries. If you specifically need to include just one library, just `#include "color.h"`
(here `color.h` is being used as an example, you can choose any other library)

### Compiling Examples
For every Library, at least one Example file is included.

If you want to compile all of the Examples in the example folder, run:
```bash
cd smclib/examples
make
```

If you just want to compile a single Example, run:
```bash
cd smclib/examples
make [example]
```

Where `[example]` is the name of a library.
(See [this file](https://github.com/saloniamatteo/smclib/blob/master/examples/COMPILING.md) for more info)

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
