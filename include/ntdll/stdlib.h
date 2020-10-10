#ifndef NTDLL_STDLIB_H
#define NTDLL_STDLIB_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

__declspec(dllimport) void _splitpath(const char* path, char* drv, char* dir, char* fname, char* ext);
__declspec(dllimport) int atoi(const char* str);
__declspec(dllimport) long atol(const char* str);
__declspec(dllimport) long long _atoi64(const char* str);
__declspec(dllimport) char *_itoa(int val, char* buf, int radix);
__declspec(dllimport) char *_ltoa(long val, char* buf, int radix);
__declspec(dllimport) char *_i64toa(long long val, char* buf, int radix);
__declspec(dllimport) char *_ultoa(unsigned long val, char* buf, int radix);
__declspec(dllimport) char *_ui64toa(unsigned long long val, char* buf, int radix);
__declspec(dllimport) long strtol(const char*, char**, int);
__declspec(dllimport) unsigned long strtoul(const char*, char**, int);
__declspec(dllimport) void* _lfind(const void*, const void*, unsigned int*, unsigned int, int (__cdecl *compare)(const void*, const void*));
__declspec(dllimport) void* bsearch(const void*, const void*, size_t, size_t, int (__cdecl *compare)(const void*, const void*));
__declspec(dllimport) size_t mbstowcs(wchar_t*, const char*, size_t);
__declspec(dllimport) void qsort(void*, size_t, size_t, int (__cdecl *compare)(const void*, const void*));

#ifdef __cplusplus
}
#endif

#endif
