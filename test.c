#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <kernel32/process.h>
__declspec(dllimport) void Sleep(unsigned int);
void exitfunc(void){
	printf("%s\n", "Bruh moment");
}
int mainCRTStartup(void){
	atexit(exitfunc);
	srand(RAND_MAX);
	printf("%s\n", "Hello World");
	printf("%d\n", rand());
	clock_t ct = clock();
	printf("Low %u\n", ct & 0xFFFFFFFF);
	printf("High %u\n", ct >> 32);
	Sleep(10);
	printf("CLOCK %u ms\n", (clock() - ct) / 10000);
	
	time_t st = time(NULL);
	
	struct tm data;
	data = *(gmtime(&st));
	
	mktime(&data);
	printf("%s%s", asctime(&data), ctime(&st));
	
	system("notepad.exe");
	exit(0);
	return 0;
}
