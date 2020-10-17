#ifndef KERNEL32_PROCESS_H
#define KERNEL32_PROCESS_H

#include <stdint.h>
#include <stddef.h>
#include <kernel32/types.h>

#ifdef __cplusplus
extern "C" {
#endif

__declspec(dllimport) int CreateProcessA(const char*, char*, security_attributes_t*,
security_attributes_t*, int, uint32_t, void*, const char*, startup_info_t*, process_info_t*);
__declspec(dllimport) void ExitProcess(unsigned int exitcode);
__declspec(dllimport) void * GetCurrentProcess();
__declspec(dllimport) uint32_t GetCurrentProcessId();
__declspec(dllimport) int GetExitCodeProcess(void*, uint32_t*);
__declspec(dllimport) int GetProcessAffinityMask(void*, uintptr_t*, uintptr_t*);
__declspec(dllimport) int GetProcessDEPPolicy(void*, uint32_t*, int*);
__declspec(dllimport) int GetProcessHandleCount(void*, uint32_t*);
__declspec(dllimport) uint32_t GetProcessId(void*);
__declspec(dllimport) int GetProcessIoCounters(void*, io_counters_t*);
__declspec(dllimport) int GetProcessPriorityBoost(void*, int*);
__declspec(dllimport) int GetProcessShutdownParameters(uint32_t*, uint32_t*);
__declspec(dllimport) uint32_t GetProcessVersion(uint32_t);
__declspec(dllimport) int GetProcessWorkingSetSize(void*, size_t*, size_t*);
__declspec(dllimport) int IsWow64Process(void*, int*);
__declspec(dllimport) void* OpenProcess(uint32_t, int, uint32_t);
__declspec(dllimport) int ProcessIdToSessionId(uint32_t, uint32_t*);
__declspec(dllimport) int ReadProcessMemory(void*, const void*, void*, size_t, size_t*);
__declspec(dllimport) int SetProcessAffinityMask(void*, uintptr_t);
__declspec(dllimport) int SetProcessDEPPolicy(uint32_t);
__declspec(dllimport) int SetProcessPriorityBoost(void*, int);
__declspec(dllimport) int SetProcessShutdownParameters(uint32_t, uint32_t);
__declspec(dllimport) int SetProcessWorkingSetSize(void*, size_t, size_t);
__declspec(dllimport) int TerminateProcess(void*, unsigned int);
__declspec(dllimport) int WriteProcessMemory(void*, void*, const void*, size_t, size_t*);

#ifdef __cplusplus
}
#endif

#endif
