/* See LICENSE file for copyright and license details.
 *
 * This is an example implementation of the "Temp" C lib.
 *
 * Made by Salonia Matteo <saloniamatteo@pm.me>
 * Part of SMCLib.
 *
 */

#include <stdio.h>
#include <lib/temp.h>

#define _POSIX_C_SOURCE 200809L

int
main(void)
{
	/* 50°C */
	float temp = 50;

	printf("%f°C to:\n"
		"Kelvin:\t	%f°K\n"
		"Fahrenheit:	%f°F\n\n",
		temp, temp_conv(temp, CELSIUS_TO_KELVIN), temp_conv(temp, CELSIUS_TO_FAHRENHEIT));

	/* 100°F */
	temp = 100;

	printf("%f°F to:\n"
		"Celsius:	%f°C\n"
		"Kelvin:\t	%f°K\n\n",
		temp, temp_conv(temp, FAHRENHEIT_TO_CELSIUS), temp_conv(temp, FAHRENHEIT_TO_KELVIN));

	/* 300°K */
	temp = 300;

	printf("%f°K to:\n"
		"Celsius:	%f°C\n"
		"Fahrenheit:	%f°F\n",
		temp, temp_conv(temp, KELVIN_TO_CELSIUS), temp_conv(temp, KELVIN_TO_FAHRENHEIT));

	return 0;
}
