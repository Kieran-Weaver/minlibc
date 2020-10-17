#ifndef W32_STDIO_H
#define W32_STDIO_H

#include <ntdll/stdio.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef EOF
#define EOF -1
#endif

typedef void FILE;
extern FILE* stdin;
extern FILE* stdout;
extern FILE* stderr;

int fflush(FILE* stream);
int printf(const char* format, ...);
int vprintf(const char* format, va_list arg);
int fprintf(FILE* stream, const char* format, ...);
int vfprintf(FILE* stream, const char* format, va_list arg);
int fgetc(FILE* stream);
char* fgets(char* str, int num, FILE* stream);
int fputc(int character, FILE * stream);
int fputs(const char* str, FILE* stream);
int getchar(void);
int putchar(int character);
size_t fread(void* ptr, size_t size, size_t count, FILE* stream);
size_t fwrite(const void* ptr, size_t size, size_t count, FILE* stream);

#ifndef getc
#define getc(stream) fgetc(stream)
#endif

#ifndef putc
#define putc(stream) fputc(stream)
#endif

#ifdef __cplusplus
}
#endif

#endif
