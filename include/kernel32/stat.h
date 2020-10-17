#ifndef KERNEL32_STAT_H
#define KERNEL32_STAT_H

#include <stdint.h>
#include <kernel32/types.h>

#ifdef __cplusplus
extern "C" {
#endif

__declspec(dllimport) int GetFileInformationByHandle(void*, by_handle_file_information_t*);
__declspec(dllimport) uint32_t GetFileSize(void*, uint32_t*);
__declspec(dllimport) uint32_t GetFileSizeEx(void*, uint64_t*);
__declspec(dllimport) uint32_t GetFileType(void*);
__declspec(dllimport) int SetFileAttributesA(const char*, uint32_t);
__declspec(dllimport) int SetFileShortNameA(void*, const char*);
__declspec(dllimport) uint32_t GetFileAttributesA(const char*);
__declspec(dllimport) int GetFileAttributesExA(const char*, get_fileex_info_levels_e, void*);

#ifdef __cplusplus
}
#endif

#endif
