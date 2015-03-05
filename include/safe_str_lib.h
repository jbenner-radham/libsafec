/*------------------------------------------------------------------
 * safe_str_lib.h -- Safe C Library String APIs
 *
 * October 2008, Bo Berry
 * Modified 2015, James Benner <james.benner@gmail.com>
 *------------------------------------------------------------------*/

#ifndef __SAFE_STR_LIB_H__
#define __SAFE_STR_LIB_H__

#include "safe_lib.h"

/* The makeup of a password */
#define SAFE_STR_MIN_LOWERCASE     ( 2 )
#define SAFE_STR_MIN_UPPERCASE     ( 2 )
#define SAFE_STR_MIN_NUMBERS       ( 1 )
#define SAFE_STR_MIN_SPECIALS      ( 1 )

#define SAFE_STR_PASSWORD_MIN_LENGTH   ( 6 )
#define SAFE_STR_PASSWORD_MAX_LENGTH   ( 32 )

/* set string constraint handler */
#include "../src/safeclib/safe_str_constraint.c"
extern constraint_handler_t
set_str_constraint_handler_s(constraint_handler_t handler);


/* fitted string concatenate */
extern errno_t
strncat_s(char *dest, rsize_t dmax, const char *src, rsize_t slen);
#include "../src/safeclib/strncat_s.c"

/* fitted string copy */
extern errno_t
strncpy_s(char *dest, rsize_t dmax, const char *src, rsize_t slen);
#include "../src/safeclib/strncpy_s.c"

/* string length */
extern rsize_t
strnlen_s (const char *s, rsize_t smax);
#include "../src/safeclib/strnlen_s.c"

/* find a substring */
extern errno_t
strstr_s(char *dest, rsize_t dmax,
         const char *src, rsize_t slen, char **substring);
#include "../src/safeclib/strstr_s.c"

#endif   /* __SAFE_STR_LIB_H__ */
