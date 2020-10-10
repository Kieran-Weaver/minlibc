#ifndef NTDLL_WCHAR_H
#define NTDLL_WCHAR_H

#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef uint16_t wchar_t;
typedef uint16_t wint_t;

__declspec(dllimport) wchar_t* _itow(int value, wchar_t* buffer, int radix);
__declspec(dllimport) wchar_t* _ltow(long value, wchar_t* buffer, int radix);
__declspec(dllimport) wchar_t* _ultow(unsigned long value, wchar_t* buffer, int radix);
__declspec(dllimport) wchar_t* _i64tow(long long value, wchar_t* buffer, int radix);
__declspec(dllimport) wchar_t* _ui64tow(unsigned long long value, wchar_t* buffer, int radix);
__declspec(dllimport) int _wtoi(const wchar_t* str);
__declspec(dllimport) long _wtol(const wchar_t* str);
__declspec(dllimport) long long _wtoi64(const wchar_t* str);
__declspec(dllimport) int swprintf(wchar_t* buf, size_t cnt, const wchar_t* fmt, ...);
__declspec(dllimport) int _snwprintf(wchar_t* buf, size_t cnt, const wchar_t* fmt, ...);
__declspec(dllimport) int _vsnwprintf(wchar_t* buf, size_t cnt, const wchar_t* fmt, va_list aptr);
__declspec(dllimport) wchar_t* _wcslwr(wchar_t* str);
__declspec(dllimport) wchar_t* _wcsupr(wchar_t* str);
__declspec(dllimport) int _wcsicmp(const wchar_t* str1, const wchar_t* str2);
__declspec(dllimport) int _wcsnicmp(const wchar_t* str1, const wchar_t* str2);
__declspec(dllimport) int iswalpha(wint_t wc);
__declspec(dllimport) int iswctype(wint_t wc);
__declspec(dllimport) int iswdigit(wint_t wc);
__declspec(dllimport) int iswlower(wint_t wc);
__declspec(dllimport) int iswspace(wint_t wc);
__declspec(dllimport) int iswxdigit(wint_t wc);
__declspec(dllimport) int isxdigit(wint_t wc);
__declspec(dllimport) int towlower(wint_t wc);
__declspec(dllimport) int towupper(wint_t wc);
__declspec(dllimport) wchar_t* wcscat(wchar_t* dest, const wchar_t* src);
__declspec(dllimport) wchar_t* wcschr(const wchar_t* str, wchar_t c);
__declspec(dllimport) int wcscmp(const wchar_t* str1, const wchar_t* str2);
__declspec(dllimport) wchar_t* wcscpy(wchar_t* dest, const wchar_t* src);
__declspec(dllimport) size_t wcscspn(const wchar_t* str, const wchar_t* cset);
__declspec(dllimport) size_t wcslen(const wchar_t* str);
__declspec(dllimport) wchar_t* wcsncat(wchar_t* dest, const wchar_t* src, size_t cnt);
__declspec(dllimport) int wcsncmp(const wchar_t* dest, const wchar_t* src, size_t cnt);
__declspec(dllimport) wchar_t* wcsncpy(wchar_t* dest, const wchar_t* src, size_t cnt);
__declspec(dllimport) wchar_t* wcspbrk(const wchar_t*, const wchar_t*);
__declspec(dllimport) wchar_t* wcsrchr(const wchar_t*, wchar_t);
__declspec(dllimport) size_t wcsspn(const wchar_t*, const wchar_t*);
__declspec(dllimport) wchar_t* wcsstr(const wchar_t*, const wchar_t*);
__declspec(dllimport) long wcstol(const wchar_t*, wchar_t**, int base);
__declspec(dllimport) size_t wcstombs(char_t*, const wchar_t*, size_t);
__declspec(dllimport) unsigned long wcstoul(const wchar_t*, wchar_t**, int base);

#ifdef __cplusplus
}
#endif

#endif
