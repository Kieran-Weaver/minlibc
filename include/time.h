#ifndef W32_TIME_H
#define W32_TIME_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef CLOCKS_PER_SEC
#define CLOCKS_PER_SEC 10000000ULL
#endif

typedef uint64_t clock_t;

struct tm{
	int tm_sec;
	int tm_min;
	int tm_hour;
	int tm_mday;
	int tm_mon;
	int tm_year;
	int tm_wday;
	int tm_yday;
	int tm_isdst;
};

clock_t clock();
double difftime(time_t, time_t);
time_t mktime(struct tm * timeptr);
time_t time(time_t*);
char* asctime(const struct tm *timeptr);
char* ctime(const time_t* timer);
struct tm * gmtime(const time_t * timer);
struct tm * localtime(const time_t * timer);

#ifdef __cplusplus
}
#endif

#endif
