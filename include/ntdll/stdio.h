#ifndef NTDLL_STDIO_H
#define NTDLL_STDIO_H

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

__declspec(dllimport) int vsprintf(char *buf, const char* fmt, va_list args);
__declspec(dllimport) int sprintf(char *buf, const char* fmt, ...);
__declspec(dllimport) int sscanf(const char* buf, const char* fmt, ...);
__declspec(dllimport) int _snprintf(char* buf, size_t cnt, const char* fmt, ...);
__declspec(dllimport) int _vsnprintf(char* buf, size_t cnt, const char* fmt, va_list args);

#ifdef __cplusplus
}
#endif

#endif
