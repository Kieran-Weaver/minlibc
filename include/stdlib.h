#ifndef W32_STDLIB_H
#define W32_STDLIB_H

#include <stddef.h>
#include <ntdll/stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef RAND_MAX
#define RAND_MAX 0xFFFFFFFFu
#endif

void* malloc(size_t sz);
void* calloc(size_t sz);
void* realloc(void *ptr, size_t sz);
void free(void *ptr);
void srand(unsigned int seed);
unsigned int rand();

#ifdef __cplusplus
}
#endif

#endif
