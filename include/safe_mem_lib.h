/*------------------------------------------------------------------
 * safe_mem_lib.h -- Safe C Library Memory APIs
 *
 * October 2008, Bo Berry
 * Modified 2015, James Benner <james.benner@gmail.com>
 *------------------------------------------------------------------*/

#ifndef __SAFE_MEM_LIB_H__
#define __SAFE_MEM_LIB_H__

#include "safe_lib.h"

#define RSIZE_MAX_MEM      ( 256UL << 20 )     /* 256MB */
#define RSIZE_MAX_MEM16    ( RSIZE_MAX_MEM/2 )
#define RSIZE_MAX_MEM32    ( RSIZE_MAX_MEM/4 )

/* set memory constraint handler */
extern constraint_handler_t
set_mem_constraint_handler_s(constraint_handler_t handler);


/* compare memory */
extern errno_t memcmp_s(const void *dest, rsize_t dmax,
                        const void *src, rsize_t slen, int *diff);

/* compare uint16_t memory */
extern errno_t memcmp16_s(const uint16_t *dest, rsize_t dmax,
                          const uint16_t *src, rsize_t slen, int *diff);

/* compare uint32_t memory */
extern errno_t memcmp32_s(const uint32_t *dest, rsize_t dmax,
                          const uint32_t *src, rsize_t slen, int *diff);


/* copy memory */
extern errno_t memcpy_s(void *dest, rsize_t dmax,
                        const void *src, rsize_t slen);

/* copy uint16_t memory */
extern errno_t memcpy16_s(uint16_t *dest, rsize_t dmax,
                          const uint16_t *src, rsize_t slen);

/* copy uint32_t memory */
extern errno_t memcpy32_s(uint32_t *dest, rsize_t dmax,
                          const uint32_t *src, rsize_t slen);


/* move memory, including overlapping memory */
extern errno_t memmove_s(void *dest, rsize_t  dmax,
                          const void *src, rsize_t slen);

/* uint16_t move memory, including overlapping memory */
extern errno_t memmove16_s(uint16_t *dest, rsize_t dmax,
                            const uint16_t *src, rsize_t slen);

/* uint32_t move memory, including overlapping memory */
extern errno_t memmove32_s(uint32_t *dest, rsize_t dmax,
                            const uint32_t *src, rsize_t slen);


/* set bytes */
extern errno_t memset_s(void *dest, rsize_t dmax, uint8_t value);

/* set uint16_t */
extern errno_t memset16_s(uint16_t *dest, rsize_t dmax, uint16_t value);

/* set uint32_t */
extern errno_t memset32_s(uint32_t *dest, rsize_t dmax, uint32_t value);


/* byte zero */
extern errno_t memzero_s(void *dest, rsize_t dmax);

/* uint16_t zero */
extern errno_t memzero16_s(uint16_t *dest, rsize_t dmax);

/* uint32_t zero */
extern errno_t memzero32_s(uint32_t *dest, rsize_t dmax);


#endif  /* __SAFE_MEM_LIB_H__ */
