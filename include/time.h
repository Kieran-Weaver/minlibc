#ifndef W32_TIME_H
#define W32_TIME_H
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef CLOCKS_PER_SEC
#define CLOCKS_PER_SEC 10000000ULL
#endif

typedef uint64_t clock_t;
clock_t clock();

#ifdef __cplusplus
}
#endif

#endif
