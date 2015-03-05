//- `safe_lib_errno.h`

#pragma once

#ifndef __SAFE_LIB_ERRNO_H__
#define __SAFE_LIB_ERRNO_H__

/**
 * @link https://www.securecoding.cert.org/confluence/display/seccode/DCL09-C.+Declare+functions+that+return+errno+with+a+return+type+of+errno_t
 */
#ifndef __STDC_LIB_EXT1__
    /* C11 appendix K type - specific for bounds checking */
    typedef int errno_t;
#endif

/*
 * Safe Lib specific errno codes.  These can be added to the errno.h file
 * if desired.
 */
#ifndef ESNULLP
    /* null ptr */
    #define ESNULLP 400
#endif

#ifndef ESZEROL
    /* length is zero */
    #define ESZEROL 401
#endif

#ifndef ESLEMIN
    /* length is below min */
    #define ESLEMIN 402
#endif

#ifndef ESLEMAX
    /* length exceeds max */
    #define ESLEMAX 403
#endif

#ifndef ESOVRLP
    /* overlap undefined */
    #define ESOVRLP 404
#endif

#ifndef ESEMPTY
    /* empty string */
    #define ESEMPTY 405
#endif

#ifndef ESNOSPC
    /* not enough space for s2 */
    #define ESNOSPC 406
#endif

#ifndef ESUNTERM
    /* unterminated string */
    #define ESUNTERM 407
#endif

#ifndef ESNODIFF
    /* no difference */
    #define ESNODIFF 408
#endif

#ifndef ESNOTFND
    /* not found */
    #define ESNOTFND 409
#endif

/* EOK may or may not be defined in errno.h */
#ifndef EOK
    #define EOK 0
#endif

#endif /* __SAFE_LIB_ERRNO_H__ */
//-
