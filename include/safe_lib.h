/*------------------------------------------------------------------
 * safe_lib.h -- Safe C Library Memory APIs
 *
 * October 2008, Bo Berry
 * Modified 2015, James Benner <james.benner@gmail.com>
 *------------------------------------------------------------------*/

#ifndef __SAFE_LIB_H__
#define __SAFE_LIB_H__

#include "safe_types.h"
#include "safe_lib_errno.h"

/* C11 appendix K types - specific for bounds checking */
//-// typedef size_t  rsize_t;

/*
 * We depart from the standard and allow memory and string operations to
 * have different max sizes. See the respective safe_mem_lib.h or
 * safe_str_lib.h files.
 */
/* #define RSIZE_MAX (~(rsize_t)0)  - leave here for completeness */

typedef void (*constraint_handler_t) (const char * /* msg */,
                                      void *       /* ptr */,
                                      errno_t      /* error */);

extern void abort_handler_s(const char *msg, void *ptr, errno_t error);
extern void ignore_handler_s(const char *msg, void *ptr, errno_t error);

#include "../src/safeclib/abort_handler_s.c"
#include "../src/safeclib/ignore_handler_s.c"

#define sl_default_handler ignore_handler_s

#include "safe_mem_lib.h"
#include "safe_str_lib.h"

#endif /* __SAFE_LIB_H__ */
