#ifndef W32_STDLIB_H
#define W32_STDLIB_H
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

void* malloc(size_t sz);
void* calloc(size_t sz);
void* realloc(void *ptr, size_t sz);
void free(void *ptr);

#ifdef __cplusplus
}
#endif

#endif
