/* See LICENSE file for copyright and license details.
 *
 * This Library checks the platform used to compile the program,
 * defining the "ARCH" variable at pre-processing time,
 * as well as ARCH_x86 = x86, if ARCH is x86 or x86_64,
 * and ARCH_ARM = ARM, if ARCH is under the ARM family.
 *
 * Additionally, 3 more variables are defined, with the
 * following conditions:
 * 	- OS_WIN32: OS is Windows
 * 	- OS_UNIX: OS is Unix/Unix-like
 * 	- OS_UNK: OS is Unknown
 *
 * Made by Salonia Matteo <saloniamatteo@pm.me>
 * Part of SMCLib.
 *
 */

/*
 * Available Architectures under MSVC:
 * 	- Alpha
 * 	- ARM
 * 	- ARMv7
 * 	- PowerPC
 * 	- x86
 * 	- x86_64
 */

/*
 * Available Architectures under GCC, CLang, etc.:
 * 	- Alpha
 * 	- ARM
 * 	- ARM64
 * 	- ARMv2
 * 	- ARMv3
 * 	- ARMv4T
 * 	- ARMv5
 * 	- ARMv5T
 * 	- ARMv6
 * 	- ARMv6T2
 * 	- ARMv7
 * 	- ARMv7s
 * 	- HP/PA RISC
 * 	- MIPS
 * 	- Motorola 68K
 * 	- PowerPC
 * 	- SPARCv8 (SuperSPARC)
 * 	- SPARCv9 (UltraSPARC)
 * 	- SuperH
 * 	- x86
 * 	- x86_64
 */

#ifndef _SMCLIB_PLATFORM_H
#define _SMCLIB_PLATFORM_H

#define _POSIX_C_SOURCE 200809L

/* Firstly, check if using Windows, or UNIX */
#if defined(_WIN32) || defined(WIN32) || defined(__CYGWIN__) || defined(__MINGW32__) || defined(__BORLANDC__)
#define OS_WIN32 WIN32
#elif defined(__unix__)
#define OS_UNIX UNIX
#else
#define OS_UNK UNKNOWN
#endif

/* Macros used by MSVC */
/* Check Alpha */
#ifdef _M_ALPHA
#define ARCH "Alpha"

/* Check ARM */
#elif defined _M_ARM
#define ARCH "ARM"
#define ARCH_ARM ARM

/* Check ARMv7 */
#elif defined _M_ARM_ARMV7VE
#define ARCH "ARMv7"
#define ARCH_ARM ARM

/* Check PowerPC */
#elif defined _M_PPC
#define ARCH "PowerPC"

/* Check x86 */
#elif defined _M_X86
#define ARCH "x86"
#define ARCH_x86 x86

/* Check x86_64 */
#elif defined _M_AMD64
#define ARCH "x86_64"
#define ARCH_x86 x86
#endif

/* Macros used by GCC, CLang, etc. */
/* Check Alpha */
#ifdef __alpha__
#define ARCH "Alpha"

/*-- BEGIN ARM --*/
/* Check ARM */
#elif defined __arm__
#define ARCH "ARM"
#define ARCH_ARM ARM

/* Check ARM64 */
#elif defined __ARM_ARCH_ISA_A64
#define ARCH "ARM64"
#define ARCH_ARM ARM

/* Check ARMv2 */
#elif defined __ARM_ARCH_2__
#define ARCH "ARMv2"
#define ARCH_ARM ARM

/* Check ARMv3 */
#elif defined __ARM_ARCH_3__
#define ARCH "ARMv3"
#define ARCH_ARM ARM

/* Check ARMv4 */
#elif defined __ARM_ARCH_4T__
#define ARCH "ARMv4T"
#define ARCH_ARM ARM

/* Check ARMv5 */
#elif defined __ARM_ARCH_5__
#define ARCH "ARMv5"
#define ARCH_ARM ARM

/* Check ARMv6 */
#elif defined __ARM_ARCH_6__
#define ARCH "ARMv6"
#define ARCH_ARM ARM

/* Check ARMv6T */
#elif defined __ARM_ARCH_6T2__
#define ARCH "ARMv6T2"
#define ARCH_ARM ARM

/* Check ARMv7 */
#elif defined __ARM_ARCH_7A__
#define ARCH "ARMv7"
#define ARCH_ARM ARM

/* Check ARMv7s */
#elif defined __ARM_ARCH_7S__
#define ARCH "ARMv7s"
#define ARCH_ARM ARM
/*-- END ARM --*/

/* Check HP/PA RISC */
#elif defined __hppa__
#define ARCH "HP/PA RISC"

/* Check MIPS */
#elif defined __mips__
#define ARCH "MIPS"

/* Check Motorola 68k */
#elif defined __m68k__
#define ARCH "Motorola 68k"

/* Check PowerPC */
#elif defined __ppc__
#define ARCH "PowerPC"

/* Check SPARCv8 (SuperSPARC) */
#elif defined __sparc_v8__
#define ARCH "SPARCv8 (SuperSPARC)"

/* Check SPARCv9 (UltraSPARC) */
#elif defined __sparc_v9__
#define ARCH "SPARCv9 (UltraSPARC)"

/* Check SuperH */
#elif defined __sh__
#define ARCH "SuperH"

/* Check x86 */
#elif defined __ILP32__
#define ARCH "x86"
#define ARCH_x86 x86

/* Check x86_64 */
#elif defined __x86_64
#define ARCH "x86_64"
#define ARCH_x86 x86
#endif

#endif /* _SMCLIB_PLATFORM_H */
