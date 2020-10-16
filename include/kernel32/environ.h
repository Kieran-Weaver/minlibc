#ifndef KERNEL32_ENV_H
#define KERNEL32_ENV_H

#ifdef __cplusplus
extern "C" {
#endif

__declspec(dllimport) unsigned int GetEnvironmentStrings(const char*, char*, unsigned int);
__declspec(dllimport) unsigned int ExpandEnvironmentStringsA(const char*, char*, unsigned int);
__declspec(dllimport) int FreeEnvironmentStringsA(char*);
__declspec(dllimport) char* GetEnvironmentStringsA();
__declspec(dllimport) unsigned int GetEnvironmentVariableA(const char*, char*, unsigned int);
__declspec(dllimport) unsigned int GetFirmwareEnvironmentVariableA(const char*, const char*, void*, unsigned int);
__declspec(dllimport) int SetEnvironmentVariableA(const char*, const char*);
__declspec(dllimport) int SetFirmwareEnvironmentVariableA(const char*, const char*, void*, unsigned int);

#ifdef __cplusplus
}
#endif

#endif
