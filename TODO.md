## SMCLib: To-do List

Salonia Matteo's C Library (or `SMCLib`) is a C Library written by Salonia Matteo.

+ TODO:
	- ~`color.h`: need to figure out how to make the function return a string, without needing to allocate memory~
	- initial implementation with `color-new.h`: need to fix issue where multiple strings are used in a single `printf`; Example:
	
	```c
	#include <stdio.h>
		
	#include "color-new.h"
		
	int
	main(int argc, char **argv)
	{
		printf("These strings will be colored: %s %s\n",
		color("Hello, ", 2, bold, redBg),
		color("World!", 2, bold, blueBg));
		return 0;
	}
	```
	This will output the following:
	`These strings will be colored: Hello,  Hello,`
