#ifndef W32_STDIO_H
#define W32_STDIO_H

#include <ntdll/stdio.h>
#include <stdarg.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef EOF
#define EOF -1
#endif

struct _FILE;
typedef struct _FILE FILE;
typedef uint64_t fpos_t;

extern FILE* stdin;
extern FILE* stdout;
extern FILE* stderr;

// High level functions
FILE* fopen(const char* filename, const char* mode);
int printf(const char* format, ...);
int vprintf(const char* format, va_list arg);
int fprintf(FILE* stream, const char* format, ...);
int vfprintf(FILE* stream, const char* format, va_list arg);
int snprintf(char* s, size_t maxlen, const char* format, ...);
int vsnprintf(char *s,size_t maxlen, const char* format, va_list ap);
int fgetc(FILE* stream);
char* fgets(char* str, int num, FILE* stream);
int fputc(int character, FILE * stream);
int fputs(const char* str, FILE* stream);
int getchar(void);
int putchar(int character);
// Low level functions
int fclose(FILE* stream);
int ungetc(int c, FILE* s);
size_t fread(void* ptr, size_t size, size_t count, FILE* stream);
size_t fwrite(const void* ptr, size_t size, size_t count, FILE* stream);
int fflush(FILE* stream);
int fseeko(FILE* stream, int64_t offset, int origin);
int fseek(FILE* stream, long offset, int origin);
long int ftell(FILE* stream);
int64_t ftello(FILE* stream);
int fgetpos (FILE * stream, fpos_t* pos);
int fsetpos (FILE * stream, const fpos_t* pos);
int feof(FILE* stream);

#ifndef getc
#define getc(stream) fgetc(stream)
#endif

#ifndef putc
#define putc(stream) fputc(stream)
#endif

#undef SEEK_SET
#undef SEEK_CUR
#undef SEEK_END

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

#ifdef __cplusplus
}
#endif

#endif
