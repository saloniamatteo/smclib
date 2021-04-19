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
 * 	1	colorCount is <= 0
 * 	2	malloc_size is <= 0
 * 	3	Pointer is null
 *
 */

#ifndef _SMCLIB_COLOR_H
#define _SMCLIB_COLOR_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
};

/* This global variable holds the colored string */
static char *coloredStr = NULL;

/* Function prototypes */
static int _free_color(void);
static char *color(char *, int, ...);

/* Free previously allocated memory */
static int
_free_color(void)
{
	coloredStr = (char *) realloc(coloredStr, 1);
	memset(coloredStr, 0, 1);
	free(coloredStr);

	coloredStr = NULL;

	if (coloredStr != NULL)
		return 1;
	else
		return 0;
}

/* This function colors a text string using ASCII escape sequences; it returns a colored string */
static char *
color(char *string, int colorCount, ...)
{
	/* Make sure color count is not less than 1 */
	if (colorCount <= 0) {
		fprintf(stderr, "Error: please select at least 1 color!\n");
		exit(1);
	}

	/* Create necessary variables */
	char tmp[300];

	/* Clear temporary variable */
	memset(&tmp, 0, sizeof(tmp));

	/* This variable will contain how much memory to allocate */
	size_t malloc_size = sizeof(char *) + strlen(string) + colorCount + 1;

	/* Variadic argument list */
	va_list argl;

	/* Check if size to allocate isn't smaller than the string + colorCount */
	if (malloc_size <= (strlen(string) + colorCount)) {
		fprintf(stderr, "Size to allocate is too small! Size: %ld\n", malloc_size);
		exit(2);
	}

	/* Dynamically allocate variable */
	coloredStr = (char*) calloc(1, malloc_size);

	/* Check if pointer is null */
	if (coloredStr == NULL) {
		fprintf(stderr, "Error: unable to allocate enough memory!\n");
		exit(3);
	}

	/* Initialize variadic argument list */
	va_start(argl, colorCount);

	/* Prepend "\e[" to coloredStr */
	sprintf(tmp, "\e[");
	strcpy(coloredStr, tmp);

	/* Append every color to coloredStr, prepending "\e[";
	The colored string will look like this:
	\e[COLOR1;COLOR2..mSTRING\e[RESETm" */
	for (int i = 0; i < colorCount; i++) {
		sprintf(tmp, "%d", va_arg(argl, int));
		/* Append ";" to concatenate colors */
		if (i < (colorCount - 1))
			strcat(tmp, ";");
		/* Append "m" to signal the end of the ASCII color sequence */
		else
			strcat(tmp, "m");
		strcat(coloredStr, tmp);
	}

	/* Append "m" to signal the end of the ASCII color sequence */
	strcat(tmp, "m");

	/* We don't need the variadic arguments list anymore */
	va_end(argl);

	/* Put the wanted string in tmp, resetting the color, copying it in coloredStr
	string will look like this: \e[COLOR1;COLOR2m..STRING\e[RESETm */
	sprintf(tmp, "%s\e[%dm", string, reset);
	strcat(coloredStr, tmp);

	/* Clear temporary variable */
	memset(&tmp, 0, sizeof(tmp));

	/* Return the colored string */
	return coloredStr;
}

#endif /* _SMCLIB_COLOR_H */

