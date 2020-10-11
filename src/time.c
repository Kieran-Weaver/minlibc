#include <time.h>
#include <kernel32/time.h>
clock_t clock(){
	filetime_t ft;
	GetSystemTimeAsFileTime(&ft);
	clock_t ck = ft.dwHighDateTime;
	ck = ck << 32;
	ck += ft.dwLowDateTime;
	return ck;
}
