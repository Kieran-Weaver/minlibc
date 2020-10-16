#ifndef KERNEL32_HANDLE_H
#define KERNEL32_HANDLE_H

#ifdef __cplusplus
extern "C" {
#endif

__declspec(dllimport) int CloseHandle(void*);
__declspec(dllimport) int DuplicateHandle(void*, void*, void*, void**, unsigned int, void*, unsigned int);
__declspec(dllimport) int GetHandleInformation(void*, unsigned int*);
__declspec(dllimport) unsigned int SetHandleCount(unsigned int);
__declspec(dllimport) int SetHandleInformation(void*, unsigned int, unsigned int);

#ifdef __cplusplus
}
#endif

#endif
