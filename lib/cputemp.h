/* See LICENSE file for copyright and license details.
 *
 * This header, cputemp.h, provides the function get_temp,
 * to get the current CPU temperature, as well as
 * get_temp_k (Kelvin), and get_temp_f (Fahrenheit).
 *
 * Made by Salonia Matteo <saloniamatteo@pm.me>
 * Part of SMCLib.
 *
 */

#ifndef _SMCLIB_CPUTEMP_H
#define _SMCLIB_CPUTEMP_H

#define _POSIX_C_SOURCE 200809L
#define CPUTEMP_RD_PATH "/sys/class/thermal/thermal_zone0/temp"

#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
int	get_temp(void);		// Celsius
float	get_temp_k(void);	// Kelvin
float	get_temp_f(void);	// Fahrenheit

/* Return current CPU temperature as integer,
 * return -1 on error */
int
get_temp(void)
{
	FILE *fd;
	char temp_str[6], ch;
	int temp = 0, i = 0;

	fd = fopen(CPUTEMP_RD_PATH, "r");

	/* Cannot read temperature */
	if (fd == NULL)
		return -1;

	/* Read temperature */
	ch = fgetc(fd);

	while (ch != EOF) {
		temp_str[i] = ch;
		i++;
		ch = fgetc(fd);
	}

	temp_str[i - 1] = '\0';

	/* Convert string to integer */
	temp = atoi(temp_str) / 1000;

	/* Close file descriptor */
	fclose(fd);

	return temp;
}

/* Return temperature in Kelvin */
float
get_temp_k(void)
{
	int temp = get_temp();

	/* Check if temperature is not valid */
	if (temp == -1)
		return -1;

	/* Convert Celsius to Kelvin */
	return temp + 273.15;
}

/* Return temperature in Fahrenheit */
float
get_temp_f(void)
{
	int temp = get_temp();

	/* Check if temperature is not valid */
	if (temp == -1)
		return -1;

	/* Convert Celsius to Fahrenheit */
	return (temp * 1.8) + 32;
}

#endif	/* _SMCLIB_CPUTEMP_H */
