/* See LICENSE file for copyright and license details.
 *
 * This is an example implementation of the "Compiler" and
 * "Platform" C Libraries.
 *
 * Made by Salonia Matteo <saloniamatteo@pm.me>
 * Part of SMCLib.
 *
 */

#include <stdio.h>
#include <lib/compiler.h>
#include <lib/platform.h>

#define _POSIX_C_SOURCE 200809L

#ifdef OS_WIN32
#define OS "Win32"
#elif defined OS_UNIX
#define OS "Unix"
#elif defined OS_UNK
#define OS "Unknown"
#endif

int
main(void)
{
	printf("This program was compiled on %s at %s.\n", __DATE__, __TIME__);
	printf("The compiler used is %s, and the platform is %s.\n", CC, ARCH);
	printf("Operating system is %s.\n", OS);

	return 0;
}
