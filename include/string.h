#ifndef W32_STRING_H
#define W32_STRING_H

#include <ntdll/string.h>

#ifdef __cplusplus
extern "C" {
#endif

char * strtok(char * str, const char* delim);

#ifdef __cplusplus
}
#endif

#endif
