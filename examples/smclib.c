/* See LICENSE file for copyright and license details.
 *
 * This is an example implementation using the SMCLib Meta-Library.
 * It uses the "color" function to color a string, as given
 * by the user; it also prints the used Compiler, and the
 * Target Architecture.
 *
 * Made by Salonia Matteo <saloniamatteo@pm.me>
 * Part of SMCLib.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../smclib.h"

int
main(int argc, char **argv)
{
	/* This variable will hold SMCLib's version */
	char smclib_ver[sizeof(_smclib_ver)];

	/* Copy only the first decimal place in smclib_ver */
	sprintf(smclib_ver, "%.1f", _smclib_ver);

	/* Print SMCLib's version, applying a cyan color to the foreground, making it bold */
	printf("Using SMCLib version %s\n\n", color(smclib_ver, 2, cyanFg, bold));

	/* Print Compiler and Target Architecture, using CC and ARCH */
	printf("Compiler used to compile this program: %s\n", color(CC, 2, redBg, bold));
	printf("Target Architecture: %s\n\n", color(ARCH, 2, greenBg, bold));

	/* Create variable that will hold the user's string */
	char string[100];

	/* Get string from user */
	printf("Enter a string to color: ");
	fgets(string, sizeof(string), stdin);

	/* Check if string is not empty */
	if (string[0] == ' ' && string[1] == ' ') {
		fprintf(stderr, "Enter a valid string!");
		exit(1);
	}

	/* Apply color to string */
	strcpy(string, color(string, 2, blueBg, bold));

	/* Print string */
	printf("Colored string: %s", string);

	return 0;
}
