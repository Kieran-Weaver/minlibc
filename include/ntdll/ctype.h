#ifndef NTDLL_CTYPES_H
#define NTDLL_CTYPES_H

#ifdef __cplusplus
extern "C" {
#endif

__declspec(dllimport) int __isascii(int c);
__declspec(dllimport) int __iscsym(int c);
__declspec(dllimport) int __iscsymf(int c);
__declspec(dllimport) int __toascii(int c);
__declspec(dllimport) int _tolower(int c);
__declspec(dllimport) int _toupper(int c);
__declspec(dllimport) int tolower(int c);
__declspec(dllimport) int toupper(int c);
__declspec(dllimport) int isalnum(int c);
__declspec(dllimport) int isalpha(int c);
__declspec(dllimport) int iscntrl(int c);
__declspec(dllimport) int isdigit(int c);
__declspec(dllimport) int isgraph(int c);
__declspec(dllimport) int islower(int c);
__declspec(dllimport) int isprint(int c);
__declspec(dllimport) int ispunct(int c);
__declspec(dllimport) int isspace(int c);
__declspec(dllimport) int isupper(int c);

#ifdef __cplusplus
}
#endif

#endif
