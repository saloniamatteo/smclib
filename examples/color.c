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
	printf("This is a basic C program to showcase the %s ",
		color("color.h library", 2, blueBg, bold));
	printf("made by %s\n",
		color("Matteo Salonia", 2, redBg, bold));

	printf("Compiled on %s ",
		color(__DATE__, 2, greenBg, bold));
	printf("at %s\n\n",
		color(__TIME__, 2, greenBg, bold));

	printf("The following string will be bold...\n%s\n\n",
		color("This is now bold!", 1, bold));

	printf("Interesting...Now the following will have a red background, and bold text!\n%s\n\n",
		color("This is red!", 2, bold, redBg));

	char *myString = color("Hello, World!", 4, rvideo, bold, bBlueFg, whiteBg);

	printf("The color function is not just limited to just printf! You can also use it with variables: %s\n\n", myString);

	printf("What about black text on white background? %s\n\n",
		color("Here it is!", 2, whiteBg, blackFg));

	printf("Even bright colors are supported, take a look!\n");
	printf("%s\n", color("Bright white foreground on green...", 2, greenBg, bWhiteFg));
	printf("%s\n\n", color("Regular white foreground on green...", 2, greenBg, whiteFg));

	printf("%s\n", color("So...how do I make this work?\n", 1, italic));
	printf("Using variadic arguments, I can pass %s",
		color("as ", 3, bold, redBg, italic));
	printf("%s", color("many ", 3, bold, greenBg, underline));
	printf("%s as I want to the function!\n\n",
		color("colors", 3, bold, blueBg, fblink));

	printf("Examples:\n");

	printf("%s(\"Some string...\", 1, bold);\n",
		color("color", 1, bold));
	printf("The function above will simply make the string \"Some string...\" bold.\nOutput: %s\n\n",
		color("Some string...", 1, bold));

	printf("%s(\"My text!\", 3, bold, blueBg, whiteFg);\n",
		color("color", 1, bold));
	printf("The function above will color the string \"My text!\", making it bold, and \
giving it a White Foreground, and Blue Background.\nOutput:\n%s\n",
	color("My text!", 3, bold, blueBg, whiteFg));

	return 0;
}
