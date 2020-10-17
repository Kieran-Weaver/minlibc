#ifndef KERNEL32_CONSOLE_H
#define KERNEL32_CONSOLE_H

#include <stdint.h>
#include <kernel32/types.h>

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

__declspec(dllimport) int ReadConsoleOutputAttribute(void*, void*, uint32_t, coord_t, uint32_t*);
__declspec(dllimport) int AllocConsole();
__declspec(dllimport) int AttachConsole(uint32_t);
__declspec(dllimport) int FlushConsoleInputBuffer(void*);
__declspec(dllimport) int FreeConsole();
__declspec(dllimport) int GenerateConsoleCtrlEvent(uint32_t, uint32_t);
__declspec(dllimport) unsigned int GetConsoleCP();
__declspec(dllimport) int GetConsoleCursorInfo(void*, console_cursor_info_t*);
__declspec(dllimport) int GetConsoleDisplayMode(uint32_t*);
__declspec(dllimport) coord_t GetConsoleFontSize(void*, uint32_t);
__declspec(dllimport) int GetConsoleMode(void*, uint32_t*);
__declspec(dllimport) unsigned int GetConsoleOutputCP();
__declspec(dllimport) uint32_t GetConsoleProcessList(uint32_t*, uint32_t);
__declspec(dllimport) int GetConsoleScreenBufferInfo(void*, console_screen_buffer_info_t*);
__declspec(dllimport) int GetConsoleSelectionInfo(console_selection_info_t*);
__declspec(dllimport) void* GetConsoleWindow();
__declspec(dllimport) int GetCurrentConsoleFont(void*, int, console_font_info_t*);
__declspec(dllimport) int GetNumberOfConsoleInputEvents(void*, uint32_t*);
__declspec(dllimport) int GetNumberOfConsoleMouseButtons(uint32_t*);
__declspec(dllimport) void* GetStdHandle(uint32_t handle);
__declspec(dllimport) int SetConsoleActiveScreenBuffer(void*);
__declspec(dllimport) int SetConsoleCP(unsigned int);
__declspec(dllimport) int SetConsoleCtrlHandler(handler_routine_t, int);
__declspec(dllimport) int SetConsoleCursorInfo(void*, const console_cursor_info_t*);
__declspec(dllimport) int SetConsoleCursorPosition(void*, coord_t);
__declspec(dllimport) int SetConsoleDisplayMode(void*, uint32_t, coord_t*);
__declspec(dllimport) int SetConsoleMode(void*, uint32_t);
__declspec(dllimport) int SetConsoleOutputCP(unsigned int);
__declspec(dllimport) int SetConsoleScreenBufferSize(void*, coord_t);
__declspec(dllimport) int SetConsoleTextAttribute(void*, uint16_t);
__declspec(dllimport) int SetConsoleWindowInfo(void*, int, const small_rect_t*);
__declspec(dllimport) int SetStdHandle(uint32_t, void*);
__declspec(dllimport) int AddConsoleAliasA(const char*, const char*, const char*);
__declspec(dllimport) uint32_t GetConsoleAliasA(char*, char*, uint32_t, char*);
__declspec(dllimport) uint32_t GetConsoleAliasExesA(char*, uint32_t);
__declspec(dllimport) uint32_t GetConsoleAliasExesLengthA(void);
__declspec(dllimport) uint32_t GetConsoleAliasesA(char*, uint32_t, char*);
__declspec(dllimport) uint32_t GetConsoleAliasesLengthA(char*);
__declspec(dllimport) uint32_t GetConsoleTitleA(char*, uint32_t);
__declspec(dllimport) int ScrollConsoleScreenBufferA(void*, const small_rect_t*, const small_rect_t*, coord_t, const char_info_t*);
__declspec(dllimport) int ReadConsoleA(void*, void*, uint32_t, uint32_t*, void*);
__declspec(dllimport) int ReadConsoleInputA(void*, input_record_t*, uint32_t, uint32_t*);
__declspec(dllimport) int ReadConsoleOutputA(void*, char_info_t*, coord_t, coord_t, small_rect_t*);
__declspec(dllimport) int ReadConsoleOutputCharacterA(void*, char*, uint32_t, coord_t, uint32_t*);
__declspec(dllimport) int WriteConsoleA(void*, const void*, uint32_t, uint32_t*, void*);
__declspec(dllimport) int WriteConsoleInputA(void*, const input_record_t *, uint32_t, uint32_t*);
__declspec(dllimport) int WriteConsoleOutputA(void*, const char_info_t*, coord_t*, coord_t*, small_rect_t*);
__declspec(dllimport) int WriteConsoleOutputCharacterA(void*, const char*, uint32_t, coord_t, uint32_t*);
__declspec(dllimport) int SetConsoleTitleA(const char*);
__declspec(dllimport) int PeekConsoleInputA(void*, input_record_t*, uint32_t, uint32_t*);
__declspec(dllimport) int FillConsoleOutputCharacterA(void*, char, uint32_t, coord_t, uint32_t*);
__declspec(dllimport) int WriteConsoleOutputAttribute(void*, const uint16_t*, uint32_t, coord_t, uint32_t*);
__declspec(dllimport) uint32_t WTSGetActiveConsoleSessionId();
__declspec(dllimport) coord_t GetLargestConsoleWindowSize(void*);
__declspec(dllimport) int FillConsoleOutputAttribute(void*, uint16_t, uint32_t, coord_t, uint32_t*);
__declspec(dllimport) void* CreateConsoleScreenBuffer(uint32_t, uint32_t, const security_attributes_t*, uint32_t, void*);

#ifdef __cplusplus
}
#endif

#endif
