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
static const float _smclib_ver = 1.5;

/* Function prototypes */

/* color.h */
extern char	*color(char *, int, ...);	// Color a string
extern int	_free_color(void);		// Free allocated memory

/* temp.h */
extern int	get_temp(void);			// Get CPU temperature (Celsius)
extern float	get_temp_k(void);		// Get CPU temperature (Kelvin)
extern float	get_temp_f(void);		// Get CPU temperature (Fahrenheit)

#endif /* __SMCLIB__ */
