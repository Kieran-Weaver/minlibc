#ifndef KERNEL32_TIME_H
#define KERNEL32_TIME_H

#include <stdint.h>
#include <kernel32/types.h>

#ifdef __cplusplus
extern "C" {
#endif

__declspec(dllimport) int QueryPerformanceCounter(long long* freq);
__declspec(dllimport) int QueryPerformanceFrequency(long long* freq);
__declspec(dllimport) long CompareFileTime(const filetime_t*, const filetime_t*);
__declspec(dllimport) int DosDateTimeToFileTime(uint16_t, uint16_t, filetime_t*);
__declspec(dllimport) int FileTimeToDosDateTime(const filetime_t*, uint16_t*, uint16_t*);
__declspec(dllimport) int LocalFileTimeToFileTime(const filetime_t*, filetime_t*);
__declspec(dllimport) int FileTimeToLocalFileTime(const filetime_t*, filetime_t*);
__declspec(dllimport) int SystemTimeToFileTime(const systemtime_t*, filetime_t*);
__declspec(dllimport) int SystemTimeToTzSpecificLocalTime(const tzinfo_t*, const systemtime_t*, systemtime_t*);
__declspec(dllimport) int TzSpecificLocalTimeToSystemTime(const tzinfo_t*, const systemtime_t*, systemtime_t*);
__declspec(dllimport) int FileTimeToSystemTime(const filetime_t*, systemtime_t*);
__declspec(dllimport) int GetFileTime(void*, filetime_t*, filetime_t*, filetime_t*);
__declspec(dllimport) void GetLocalTime(systemtime_t*);
__declspec(dllimport) void GetSystemTime(systemtime_t*);
__declspec(dllimport) int GetSystemTimeAdjustment(uint32_t*, uint32_t*, int*);
__declspec(dllimport) void GetSystemTimeAsFileTime(filetime_t*);
__declspec(dllimport) int GetSystemTimes(filetime_t*, filetime_t*, filetime_t*);
__declspec(dllimport) int GetProcessTimes(void*, filetime_t*, filetime_t*, filetime_t*, filetime_t*);
__declspec(dllimport) int GetThreadTimes(void*, filetime_t*, filetime_t*, filetime_t*, filetime_t*);
__declspec(dllimport) uint32_t GetTimeZoneInformation(tzinfo_t*);
__declspec(dllimport) int SetTimeZoneInformation(const tzinfo_t*);
__declspec(dllimport) int SetFileTime(void*, const filetime_t*, const filetime_t*, const filetime_t*);
__declspec(dllimport) int SetLocalTime(const systemtime_t*);
__declspec(dllimport) int SetSystemTime(const systemtime_t*);
__declspec(dllimport) int SetSystemTimeAdjustment(uint32_t, int);

#ifdef __cplusplus
}
#endif

#endif
