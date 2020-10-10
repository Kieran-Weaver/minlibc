#ifndef NTDLL_STRING_H
#define NTDLL_STRING_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

__declspec(dllimport) void* _memccpy(void*, const void*, int, size_t);
__declspec(dllimport) int _memicmp(const void*, const void*, size_t);
__declspec(dllimport) int _stricmp(const char*, const char*);
__declspec(dllimport) int _strnicmp(const char*, const char*, size_t);
__declspec(dllimport) char* _strlwr(char*);
__declspec(dllimport) char* _strupr(char*);
__declspec(dllimport) char* strcat(char*, const char*);
__declspec(dllimport) const char* strchr(const char*, int);
__declspec(dllimport) int strcmp(const char*, const char*);
__declspec(dllimport) char* strcpy(char*, const char*);
__declspec(dllimport) size_t strcspn(const char*, const char*);
__declspec(dllimport) size_t strlen(const char*);
__declspec(dllimport) char* strncat(char*, const char*, size_t);
__declspec(dllimport) int strncmp(const char*, const char*, size_t);
__declspec(dllimport) char* strncpy(char*, const char*, size_t);
__declspec(dllimport) const char* strpbrk(const char*, const char*);
__declspec(dllimport) const char* strrchr(const char*, int);
__declspec(dllimport) size_t strspn(const char*, const char*);
__declspec(dllimport) const char* strstr(const char*, const char*);
__declspec(dllimport) const void* memchr(const void*, int, size_t);
__declspec(dllimport) int memcmp(const void*, const void*, size_t);
__declspec(dllimport) void* memcpy(void*, const void*, size_t);
__declspec(dllimport) void* memmove(void*, const void*, size_t);
__declspec(dllimport) void* memset(void*, int, size_t);

#ifdef __cplusplus
}
#endif

#endif
