/*------------------------------------------------------------------
 * safe_str_lib.h -- Safe C Library String APIs
 *
 * October 2008, Bo Berry
 * Modified 2015, James Benner <james.benner@gmail.com>
 *------------------------------------------------------------------*/

#pragma once

#ifndef __SAFE_STR_LIB_H__
#define __SAFE_STR_LIB_H__

#include "safe_lib.h"

/* The makeup of a password */
#define SAFE_STR_MIN_LOWERCASE (2)
#define SAFE_STR_MIN_UPPERCASE (2)
#define SAFE_STR_MIN_NUMBERS   (1)
#define SAFE_STR_MIN_SPECIALS  (1)

#define SAFE_STR_PASSWORD_MIN_LENGTH (6)
#define SAFE_STR_PASSWORD_MAX_LENGTH (32)

#include "strnlen_s/strnlen_s.h"

#endif  /* __SAFE_STR_LIB_H__ */
