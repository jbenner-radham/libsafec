#pragma once

/**
 * @link https://www.securecoding.cert.org/confluence/display/seccode/DCL09-C.+Declare+functions+that+return+errno+with+a+return+type+of+errno_t
 */
#ifndef __STDC_LIB_EXT1__
    //-/ Moved to `safe_lib_errno.h`
    //-/ typedef int errno_t;
    typedef size_t rsize_t;

    #ifndef RSIZE_MAX
        /** @see ISO/IEC TR 24731-1: Section 6.4 */
        #define RSIZE_MAX (SIZE_MAX >> 1)
    #endif
#endif

#ifndef RSIZE_MIN_STR
    /* The shortest string is a null string!! */
    #define RSIZE_MIN_STR (1)
#endif

#ifndef RSIZE_MAX_STR
    /* maximum sring length - 4KB */
    #define RSIZE_MAX_STR (4UL << 10)
#endif
