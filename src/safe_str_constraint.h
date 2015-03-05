//================================

#pragma once

#ifndef __SAFE_STR_CONSTRAINT_H__
#define __SAFE_STR_CONSTRAINT_H__

//- `safe_lib.h`
/*
 * We depart from the standard and allow memory and string operations to
 * have different max sizes. See the respective safe_mem_lib.h or
 * safe_str_lib.h files.
 */
typedef void (*constraint_handler_t) (const char * /* msg */,
                                      void *       /* ptr */,
                                      errno_t      /* error */);

//-/ extern void ignore_handler_s(const char *msg, void *ptr, errno_t error);

//-/ #define sl_default_handler ignore_handler_s

//================================

/**
 * `ignore_handler_s` is defined in "ignore_handler_s.h" (surprise!)
 */
#ifndef sl_default_handler
    #define sl_default_handler ignore_handler_s
#endif

//================================

static constraint_handler_t str_handler = NULL;

//-

constraint_handler_t set_str_constraint_handler_s(constraint_handler_t handler)
{
    constraint_handler_t prev_handler = str_handler;

    if (handler == NULL) {
        str_handler = sl_default_handler;
    } else {
        str_handler = handler;
    }

    return prev_handler;
}

/*
 * Function used by the libraries to invoke the registered
 * runtime-constraint handler. Always needed.
 */
void invoke_safe_str_constraint_handler(const char *msg, void *ptr, errno_t error)
{
    if (str_handler != NULL) {
        str_handler(msg, ptr, error);
    } else {
        sl_default_handler(msg, ptr, error);
    }
}

/*
 * Safe C Lib internal string routine to consolidate error handling
 */
//-/ static inline void handle_error(char *orig_dest, rsize_t orig_dmax, char *err_msg, errno_t err_code)
//-/ {
//-/ #ifdef SAFECLIB_STR_NULL_SLACK
//-/     /* null string to eliminate partial copy */
//-/     while (orig_dmax) { *orig_dest = '\0'; orig_dmax--; orig_dest++; }
//-/ #else
//-/     *orig_dest = '\0';
//-/ #endif
//-/
//-/     invoke_safe_str_constraint_handler(err_msg, NULL, err_code);
//-/     return;
//-/ }

#endif   /* __SAFE_STR_CONSTRAINT_H__ */
