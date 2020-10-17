#ifndef KERNEL32_STDIO_H
#define KERNEL32_STDIO_H

#include <stdint.h>
#include <kernel32/types.h>

#ifdef __cplusplus
extern "C" {
#endif

__declspec(dllimport) int FlushFileBuffers(void*);
__declspec(dllimport) void* CreateFileA(const char*, uint32_t, uint32_t, security_attributes_t*, uint32_t, uint32_t, void*);
__declspec(dllimport) int DeleteFileA(const char*);
__declspec(dllimport) int MoveFileA(const char*, const char*);
__declspec(dllimport) int MoveFileExA(const char*, const char*, uint32_t);
__declspec(dllimport) int MoveFileWithProgressA(const char*, const char*, progress_routine_t, void*, uint32_t);
__declspec(dllimport) int ReadFile(void*, void*, uint32_t, uint32_t*, overlapped_t*);
__declspec(dllimport) int ReadFileEx(void*, void*, uint32_t, overlapped_t*, overlapped_completion_routine_t*);
__declspec(dllimport) int ReadFileScatter(void*, file_segment_element_t*, uint32_t, uint32_t*, overlapped_t*);
__declspec(dllimport) int ReplaceFileA(const char*, const char*, const char*, uint32_t, void*, void*);
__declspec(dllimport) int SetEndOfFile(void*);
__declspec(dllimport) uint32_t SetFilePointer(void*, long, long*, uint32_t);
__declspec(dllimport) int SetFilePointerEx(void*, uint64_t, uint64_t*, uint32_t);
__declspec(dllimport) int WriteFile(void*, const void*, uint32_t, uint32_t*, void*);
__declspec(dllimport) int WriteFileEx(void*, const void*, uint32_t, overlapped_t*, overlapped_completion_routine_t);
__declspec(dllimport) int WriteFileGather(void*, file_segment_element_t*, uint32_t, uint32_t*, overlapped_t*);

#ifndef INVALID_SET_FILE_POINTER
#define INVALID_SET_FILE_POINTER ((uint32_t)-1)
#endif

#ifdef __cplusplus
}
#endif

#endif
