#ifndef KERNEL32_HEAP_H
#define KERNEL32_HEAP_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef STD_INPUT_HANDLE
#define STD_INPUT_HANDLE -10
#endif

#ifndef STD_OUTPUT_HANDLE
#define STD_OUTPUT_HANDLE -11
#endif

#ifndef STD_ERROR_HANDLE
#define STD_ERROR_HANDLE -12
#endif

__declspec(dllimport) void* GetStdHandle(uint32_t handle);
__declspec(dllimport) int WriteConsoleA(void*, const void*, uint32_t, uint32_t*, void*);

#ifdef __cplusplus
}
#endif

#endif
