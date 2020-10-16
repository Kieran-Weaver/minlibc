#ifndef W32_CTYPE_H
#define W32_CTYPE_H

#include <ntdll/ctype.h>

#ifdef __cplusplus
extern "C" {
#endif

int isxdigit(int c);
int isblank(int c);

#ifdef __cplusplus
}
#endif

#endif
