/* See LICENSE file for copyright and license details.
 *
 * This Library defines only one function, "color":
 * this function will color a given string, depending
 * on how many colors were passed to the function.
 * See examples/color.c for more info.
 *
 * Made by Salonia Matteo <saloniamatteo@pm.me>
 * Part of SMCLib.
 *
 * Exit values:
 * 	1	malloc_size is <= 0
 * 	2	Pointers are null
 * 	3	colorCount is <= 0
 *
 */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

#ifndef _COLOR_H
#define _COLOR_H

/* This enum contains escape sequence values */
enum fontEffects {
	/* Generic font effects */
	/* NWS = Not Widely Supported */
	reset = 0,	/* Set to normal colors */
	bold = 1,	/* Make text bold */
	faint = 2,	/* Slightly decrease text brightness */
	italic = 3,	/* Make text italic */
	underline = 4,	/* Underline the text */
	sblink = 5,	/* Slow blink */
	fblink = 6,	/* Fast blink */
	rvideo = 7,	/* Reverse video, swap fg and bg colors */
	crossed = 9,	/* Crossed out, marked for deletion */
	framed = 51,	/* (NWS) Enclose text in a frame */
	circled = 52,	/* (NWS) Enclose text in a circle */
	overlined = 53,	/* (NWS) Overline text */

	/* Foregrounds */
	/* NOTE: those starting with "b" are bright colors */
	blackFg = 30,
	redFg = 31, 
	greenFg = 32, 
	yellowFg = 33, 
	blueFg = 34, 
	magentaFg = 35, 
	cyanFg = 36, 
	bBlackFg = 90, 
	bRedFg = 91, 
	bGreenFg = 92, 
	bYellowFg = 93, 
	bBlueFg = 94, 
	bMagentaFg = 95, 
	bCyanFg = 96, 
	bWhiteFg = 97, 

	/* Backgrounds */
	/* NOTE: those starting with "b" are bright colors */
	whiteFg = 37, 
	blackBg = 40, 
	redBg = 41, 
	greenBg = 42, 
	yellowBg = 43, 
	blueBg = 44, 
	magentaBg = 45, 
	cyanBg = 46, 
	whiteBg = 47, 
	bBlackBg = 100, 
	bRedBg = 101, 
	bGreenBg = 102, 
	bYellowBg = 103, 
	bBlueBg = 104, 
	bMagentaBg = 105, 
	bCyanBg = 106, 
	bWhiteBg = 107
} fontEffects;

/* This variable will hold the colored string */
char coloredStr[300];

/* This function colors a text string using ASCII escape sequences; it returns a colored string */
static char
*color(char *string, int colorCount, ...)
{
	/* Empty the variable that will contain the colored string */
	for (int i = 0; i <= sizeof(coloredStr); i++)
		coloredStr[i] = ' ';

	/* Null-terminate the variable that will contain the colored string */
	((char *)coloredStr)[sizeof(coloredStr)] = '\0';

	/* Assign size to allocate to variable */
	size_t malloc_size = sizeof(char *) * (strlen(string) + colorCount);

	/* Check if size to allocate isn't less than 1 */
	if (malloc_size <= 0) {
		fprintf(stderr, "Size to allocate is too small! Size: %ld\n", malloc_size);
		exit(1);
	}

	/* Create temporary variable */
	char *tmp = NULL;

	/* Dynamically allocate variable */
	tmp = (char*) calloc(1, malloc_size);

	/* Check if pointer is null */
	if (tmp == NULL) {
		fprintf(stderr, "Error: unable to allocate enough memory!\n");
		exit(2);
	}

	/* Make sure variables are 0-ed */
	memset(tmp, 0, malloc_size);
	memset(coloredStr, 0, sizeof(coloredStr));

	/* Make sure memory is nul terminated */
	((char *)tmp)[sizeof(*tmp)] = '\0';

	/* Create variadic argument list */
	va_list argl;

	/* Make sure color count is not less than 1 */
	if (colorCount <= 0) {
		fprintf(stderr, "Error: please select at least 1 color!\n");
		exit(3);
	}

	/* Initialize variadic argument list */
	va_start(argl, colorCount);

	/* Append every given color to tmp, prepending the ASCII escape sequence "\e[COLORm" */
	for (int i = 0; i < colorCount; i++) {
		sprintf(tmp, "\e[%dm", va_arg(argl, int));
		strcat(coloredStr, tmp);
	}

	/* We don't need the variadic arguments list anymore */
	va_end(argl);

	/* Put the wanted string in tmp, resetting the color, copying it in coloredStr */
	sprintf(tmp, "%s\e[%dm", string, reset);
	strcat(coloredStr, tmp);

	/* Make sure memory is empty before freeing it */
	memset(tmp, 0, malloc_size);

	/* Free allocated memory */
	free(tmp);

	/* Return the colored string */
	return coloredStr;
}

#endif /* _COLOR_H */
