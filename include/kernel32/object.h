#ifndef KERNEL32_OBJECT_H
#define KERNEL32_OBJECT_H

#include <stdint.h>
#include <kernel32/types.h>

#ifdef __cplusplus
extern "C" {
#endif

__declspec(dllimport) int RegisterWaitForSingleObject(void**, void*, _wait_or_timer_callback, void*, unsigned long, unsigned long);
__declspec(dllimport) void* RegisterWaitForSingleObjectEx(void*, _wait_or_timer_callback, void*, unsigned long, unsigned long);
__declspec(dllimport) uint32_t SignalObjectAndWait(void*, void*, uint32_t, int);
__declspec(dllimport) uint32_t WaitForMultipleObjects(uint32_t, const void**, int, uint32_t);
__declspec(dllimport) uint32_t WaitForMultipleObjectsEx(uint32_t, const void**, int, uint32_t, int);
__declspec(dllimport) uint32_t WaitForSingleObject(void*, uint32_t);
__declspec(dllimport) uint32_t WaitForSingleObjectEx(void*, uint32_t, int);

#ifdef __cplusplus
}
#endif

#endif
