#ifndef W32_STDLIB_H
#define W32_STDLIB_H

#include <stddef.h>
#include <ntdll/stdlib.h>
#include <ntdll/math.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef RAND_MAX
#define RAND_MAX 0xFFFFFFFFu
#endif

typedef struct {
	int quot;
	int rem;
} div_t;

typedef struct {
	long quot;
	long rem;
} ldiv_t;

void* malloc(size_t sz);
void* calloc(size_t sz);
void* realloc(void *ptr, size_t sz);
void free(void *ptr);
void srand(unsigned int seed);
unsigned int rand();
void abort(void);
int atexit(void (*func)(void));
void exit(int);
char *getenv(const char*);
int system(const char*);
div_t div(int, int);
ldiv_t ldiv(long, long);
// Not implemented:
// int mblen(const char* s, size_t n);
// int mbtowc(wchar_t*, const char*, size_t);
// int wctomb(char*, wchar_t);

#ifdef __cplusplus
}
#endif

#endif
