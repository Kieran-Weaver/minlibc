#ifndef NTDLL_RTLCRT_H
#define NTDLL_RTLCRT_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

__declspec(dllimport) unsigned long RtlRandom(unsigned long* seed);
__declspec(dllimport) unsigned long RtlRandomEx(unsigned long* seed);
__declspec(dllimport) void RtlAssert(void*, void*, unsigned long, char*);
__declspec(dllimport) size_t RtlCompareMemory(const void*, const void*, size_t);
__declspec(dllimport) size_t RtlCompareMemoryUlong(const void*, size_t, unsigned long);
__declspec(dllimport) void RtlZeroMemory(void* dest, size_t length);
__declspec(dllimport) void RtlMoveMemory(void*, const void*, size_t);
__declspec(dllimport) void RtlFillMemory(void*, size_t, int);
__declspec(dllimport) void RtlFillMemoryUlong(void*, size_t, unsigned long);
__declspec(dllimport) uint32_t RtlComputeCrc32(uint32_t, const char*, int);
__declspec(dllimport) unsigned long RtlUlongByteSwap(unsigned long);
__declspec(dllimport) unsigned long long RtlUlonglongByteSwap(unsigned long long);
__declspec(dllimport) int RtlCharToInteger(const char*, unsigned long, unsigned long*);
__declspec(dllimport) int RtlIntegerToChar(unsigned long, unsigned long, unsigned long, char*);

#ifdef __cplusplus
}
#endif

#endif
