#ifndef KERNEL32_MMAP_H
#define KERNEL32_MMAP_H

#include <stdint.h>
#include <stddef.h>
#include <kernel32/types.h>

#ifdef __cplusplus
extern "C" {
#endif

__declspec(dllimport) int FlushViewOfFile(const void*, size_t);
__declspec(dllimport) void* MapViewOfFile(void*, uint32_t, uint32_t, uint32_t, size_t);
__declspec(dllimport) void* MapViewOfFileEx(void*, uint32_t, uint32_t, uint32_t, size_t, void*);
__declspec(dllimport) int UnmapViewOfFile(const void*);
__declspec(dllimport) void* OpenFileMappingA(uint32_t, int, const char*);
__declspec(dllimport) void* CreateFileMappingA(void*, security_attributes_t*, uint32_t, uint32_t, uint32_t, const char*);

#ifdef __cplusplus
}
#endif

#endif
