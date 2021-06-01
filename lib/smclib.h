/* See LICENSE file for copyright and license details.
 *
 * This is the Meta-Library for SMCLib, which you can use
 * to include all of the Libraries in this repository.
 *
 * Made by Salonia Matteo <saloniamatteo@pm.me>
 * Part of SMCLib.
 *
 */

#ifndef __SMCLIB__
#define __SMCLIB__

#include "color.h"
#include "compiler.h"
#include "platform.h"

/* SMCLib version */
static const float _smclib_ver = 1.6;

/* Function prototypes */

/* color.h */
extern char	*color(char *, int, ...);	// Color a string
extern int	_free_color(void);		// Free allocated memory

/* cputemp.h */
extern int	get_temp(void);			// Get CPU temperature (Celsius)
extern float	get_temp_k(void);		// Get CPU temperature (Kelvin)
extern float	get_temp_f(void);		// Get CPU temperature (Fahrenheit)

/* temp.h */
float celsius_to(float, int);			// Celsius to Kelvin/Fahrenheit
float kelvin_to(float, int);			// Kelvin to Celsius/Fahrenheit
float fahrenheit_to(float, int);		// Fahrenheit to Celsius/Kelvin
float temp_conv(float, int);			// Generalized temperature conversion

#endif /* __SMCLIB__ */
