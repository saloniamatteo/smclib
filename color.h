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

/* This function will color a text string using ASCII escape sequences */
static int
color(char *string, int colorCount, ...)
{
	/* Create variadic argument list */
	va_list argl;

	/* Make sure color count is not less than 1 */
	if (colorCount <= 0)
		return 1;

	/* Initialize variadic argument list */
	va_start(argl, colorCount);

	/* Print every given color, prepending the ASCII escape sequence "\e[COLORm" */
	for (int i = 1; i <= colorCount; i++)
		printf("\e[%dm", va_arg(argl, int));

	/* We don't need the variadic arguments list anymore */
	va_end(argl);

	/* Print the wanted string, then reset the color */
	printf("%s\e[%dm", string, reset);

	return 0;
}

#endif /* _COLOR_H */