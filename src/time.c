#include <time.h>
#include <stdio.h>
#include <kernel32/time.h>
static clock_t ninteenseventy = 0;
static systemtime_t nt70 = {1970, 1, 4, 1, 0, 0, 0, 0};
static struct tm gmdata;
static clock_t getClock(const filetime_t* ft){
	clock_t ck = ft->dwHighDateTime;
	ck = ck << 32;
	ck += ft->dwLowDateTime;
	return ck;
}

static clock_t get1970(){
	if (!ninteenseventy){
		filetime_t ft;
		SystemTimeToFileTime(&nt70, &ft);
		ninteenseventy = getClock(&ft);
	}
	return ninteenseventy;
}

static filetime_t getFT(time_t ft){
	clock_t ck = ft * CLOCKS_PER_SEC + get1970();
	filetime_t ftm;
	ftm.dwLowDateTime = ck & 0xFFFFFFFF;
	ftm.dwHighDateTime = ck >> 32;
	return ftm;
}

static void stimeToTm(const systemtime_t* stime, struct tm* data){
	int days[] = {-1, -1, 30, 58, 89, 119, 150, 180, 211, 242, 272, 303, 333, 0};
	data->tm_year = stime->wYear - 1900;
	data->tm_mon = stime->wMonth;
	data->tm_yday = days[data->tm_mon] + stime->wDay + (data->tm_year % 4 == 0);
	data->tm_wday = stime->wDayOfWeek;
	data->tm_mday = stime->wDay;
	data->tm_hour = stime->wHour;
	data->tm_min = stime->wMinute;
	data->tm_sec = stime->wSecond;
	data->tm_isdst = 0;
}

static void tmToStime(const struct tm* timeptr, systemtime_t* stime){
	stime->wYear = timeptr->tm_year + 1900;
	stime->wMonth = timeptr->tm_mon;
	stime->wDayOfWeek = timeptr->tm_wday;
	stime->wDay = timeptr->tm_mday;
	stime->wHour = timeptr->tm_hour;
	stime->wMinute = timeptr->tm_min;
	stime->wSecond = timeptr->tm_sec;
	stime->wMilliseconds = 0;
}

clock_t clock(){
	filetime_t ft;
	GetSystemTimeAsFileTime(&ft);
	return getClock(&ft);
}

time_t time(time_t *tmr){
	clock_t ck = clock() / CLOCKS_PER_SEC;
	time_t tim = ck - (get1970() / CLOCKS_PER_SEC);

	if (tmr){
		*tmr = tim;
	}

	return tim;
}

double difftime(time_t end, time_t beginning){
	return (end - beginning);
}

time_t mktime(struct tm * timeptr){
	systemtime_t stime;
	filetime_t ftime;
	
	tmToStime(timeptr, &stime);	
	SystemTimeToFileTime(&stime, &ftime);
	FileTimeToSystemTime(&ftime, &stime);
	stimeToTm(&stime, timeptr);
	
	return getClock(&ftime) / CLOCKS_PER_SEC;
}

struct tm * gmtime(const time_t * timer){
	filetime_t ftime = getFT(*timer);
	systemtime_t stime;
	
	FileTimeToSystemTime(&ftime, &stime);
	stimeToTm(&stime, &gmdata);
	
	return &gmdata;
}

struct tm * localtime(const time_t * timer){
	filetime_t ftime = getFT(*timer);
	systemtime_t stime;
	systemtime_t ltime;
	tzinfo_t ctz;
	
	GetTimeZoneInformation(&ctz);
	FileTimeToSystemTime(&ftime, &stime);
	SystemTimeToTzSpecificLocalTime(&ctz, &stime, &ltime);
	stimeToTm(&ltime, &gmdata);
	
	return &gmdata;
}

char* asctime(const struct tm *timeptr){
	static const char wday_name[][4] = {
		"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
	};
	static const char mon_name[][4] = {
		"Jan", "Feb", "Mar", "Apr", "May", "Jun",
		"Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
	};
	static char result[26];
	sprintf(result, "%.3s %.3s%3d %.2d:%.2d:%.2d %d\n",
	wday_name[timeptr->tm_wday],
	mon_name[timeptr->tm_mon],
	timeptr->tm_mday, timeptr->tm_hour,
	timeptr->tm_min, timeptr->tm_sec,
	1900 + timeptr->tm_year);
	return result;
}

char* ctime(const time_t* timer){
	return asctime(localtime(timer));
}
