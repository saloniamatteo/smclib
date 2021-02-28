/* See LICENSE file for copyright and license details.
 *
 * This Library checks if GCC, MSVC, or CLang is being used to
 * compile the program, defining the "CC" variable at
 * pre-processing time
 *
 * Made by Salonia Matteo <saloniamatteo@pm.me>
 * Part of SMCLib.
 *
 */

#define _POSIX_C_SOURCE 200809L

#ifndef _COMPILER_H
#define _COMPILER_H

/* Check CLang */
#ifdef __clang__
#define CC "CLang"
	
/* Check GCC */
#elif defined __GNUC__
#define CC "GCC"
		
/* Check MSVC */
#elif defined _MSC_VER
#define CC "MSVC"

/* Handle unknown compilers */
#else
#define CC "Unknown Compiler"
#endif

#endif /* _COMPILER_H */
