/* See LICENSE file for copyright and license details.
 *
 * This header, temp.h, provides functions
 * to convert between:
 * Celsius -> Fahrenheit, Kelvin
 * Kelvin -> Celsius, Fahrenheit
 * Fahrenheit -> Celsius, Kelvin
 *
 * Made by Salonia Matteo <saloniamatteo@pm.me>
 * Part of SMCLib.
 *
 */

#ifndef _SMCLIB_TEMP_H
#define _SMCLIB_TEMP_H

#define _POSIX_C_SOURCE 200809L

enum {
	CELSIUS_TO_KELVIN,
	CELSIUS_TO_FAHRENHEIT,
	KELVIN_TO_CELSIUS,
	KELVIN_TO_FAHRENHEIT,
	FAHRENHEIT_TO_CELSIUS,
	FAHRENHEIT_TO_KELVIN
} temps;

#include <stdio.h>

/* Function prototypes */
float celsius_to(float, int);		// Celsius to Kelvin/Fahrenheit
float kelvin_to(float, int);		// Kelvin to Celsius/Fahrenheit
float fahrenheit_to(float, int);	// Fahrenheit to Celsius/Kelvin
float temp_conv(float, int);		// Generalized temperature conversion

/* Celsius to Kelvin/Fahrenheit */
float
celsius_to(float c, int mode)
{
	if (mode == CELSIUS_TO_KELVIN)
		return c + 273.15;
	else if (mode == CELSIUS_TO_FAHRENHEIT)
		return (c * 1.8) + 32;
	else
		return -1;
}

/* Kelvin to Celsius/Fahrenheit */
float
kelvin_to(float k, int mode)
{
	if (mode == KELVIN_TO_CELSIUS)
		return k - 273.15;
	else if (mode == KELVIN_TO_FAHRENHEIT)
		return (k * 1.8) - 459.67;
	else
		return -1;
}

/* Fahrenheit to Celsius/Kelvin */
float
fahrenheit_to(float f, int mode)
{
	if (mode == FAHRENHEIT_TO_CELSIUS)
		return (f - 32) * 0.56;
	else if (mode == FAHRENHEIT_TO_KELVIN)
		return (f + 459.67) * 0.56;
	else
		return -1;
}

/* Generalized temperature conversion */
float
temp_conv(float m, int mode)
{
	switch (mode) {
	/* Celsius */
	case CELSIUS_TO_KELVIN:
	case CELSIUS_TO_FAHRENHEIT:
		return celsius_to(m, mode);
		break;

	/* Kelvin */
	case KELVIN_TO_CELSIUS:
	case KELVIN_TO_FAHRENHEIT:
		return kelvin_to(m, mode);
		break;

	/* Fahrenheit */
	case FAHRENHEIT_TO_CELSIUS:
	case FAHRENHEIT_TO_KELVIN:
		return fahrenheit_to(m, mode);
		break;

	/* Unknown */
	default:
		return -1;
		break;
	}
}

#endif	/* _SMCLIB_TEMP_H */
