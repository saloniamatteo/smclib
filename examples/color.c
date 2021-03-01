/* See LICENSE file for copyright and license details.
 *
 * This is an example implementation of the "Color" C Library.
 * It uses the "color" function.
 *
 * Made by Salonia Matteo <saloniamatteo@pm.me>
 * Part of SMCLib.
 *
 */

#include <stdio.h>

#include "../color.h"

#define _POSIX_C_SOURCE 200809L

int
main(int argc, char **argv)
{
	printf("This is a basic C program to showcase the ");
	color("color.h library", 2, blueBg, bold);
	printf(" made by ");
	color("Matteo Salonia\n", 2, redBg, bold);

	printf("Compiled on ");
	color(__DATE__, 2, greenBg, bold);
	printf(" at ");
	color(__TIME__, 2, greenBg, bold);

	printf("\n\nThe following string will be bold...\n");
	color("This is now bold!\n\n", 1, bold);

	printf("Interesting...Now the following will have a red background, and bold text!\n");
	color("This is red!\n\n", 2, bold, redBg);

	printf("What about black text on white background?\n");
	color("Here it is!\n\n", 2, whiteBg, blackFg);

	printf("Even bright colors are supported, take a look!\n");
	color("Bright white foreground on green...\n", 2, greenBg, bWhiteFg);
	color("Regular white foreground on green...\n\n", 2, greenBg, whiteFg);

	color("So...how do I make this work?\n", 1, italic);
	printf("Using variadic functions, I can pass ");
	color("as ", 3, bold, redBg, italic);
	color("many ", 3, bold, greenBg, underline);
	color("colors", 3, bold, blueBg, fblink);
	printf(" as I want to the function!\n\n");

	printf("Examples:\n");

	color("color", 1, bold);
	printf("(\"Some string...\", 1, bold);\n");
	printf("The function above will simply make the string \"Some string...\" bold.\nOutput:\n");
	color("Some string...\n\n", 1, bold);

	color("color", 1, bold);
	printf("(\"My text!\", 3, bold, blueBg, whiteFg);\n");
	printf("The function above will color the string \"My text!\", making it bold, and \
giving it a White Foreground, and Blue Background.\nOutput:\n");
	color("My text!\n", 3, bold, blueBg, whiteFg);

	return 0;
}
