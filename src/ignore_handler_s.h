//- `ignore_handler_s.h`

#pragma once

/**
 * Not sure if this should be dropped from the lib....
 */
void ignore_handler_s(const char *msg, void *ptr, errno_t error)
{
    //-/ sldebug_printf("IGNORE CONSTRAINT HANDLER: (%u) %s\n", error,
    //-/           (msg) ? msg : "Null message");
    return;
}
//-
