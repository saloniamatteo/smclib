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
	if (get_temp() == -1) {
		fprintf(stderr, "Could not read CPU temperature!\n");
		return -1;
	}

	printf("The current CPU temperature is:\n"
		"Celsius:	%d°C\n"
		"Kelvin:\t	%f°K\n"
		"Fahrenheit:	%f°F\n",
		get_temp(), get_temp_k(), get_temp_f());

	return 0;
}
