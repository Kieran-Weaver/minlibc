#ifndef W32_STDIO_H
#define W32_STDIO_H

#include <ntdll/stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

int printf(const char* format, ...);

#ifdef __cplusplus
}
#endif

#endif
