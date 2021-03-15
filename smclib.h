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
#define __SMCLIB__ 1

#include "color.h"
#include "compiler.h"
#include "platform.h"

/* SMCLib version */
static const float _smclib_ver = 1.3;

/* Function declarations */

/* color.h */
char *color(char *string, int colorCount, ...);

#endif /* __SMCLIB__ */
