//- `handle_error.h`

#pragma once

/*
 * Safe C Lib internal string routine to consolidate error handling
 */
static inline void handle_error(char *orig_dest, rsize_t orig_dmax, char *err_msg, errno_t err_code)
{
#ifdef SAFECLIB_STR_NULL_SLACK
    /* null string to eliminate partial copy */
    while (orig_dmax) { *orig_dest = '\0'; orig_dmax--; orig_dest++; }
#else
    *orig_dest = '\0';
#endif

    invoke_safe_str_constraint_handler(err_msg, NULL, err_code);
    return;
}
