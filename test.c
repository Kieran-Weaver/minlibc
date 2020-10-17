#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <kernel32/process.h>
#include <kernel32/console.h>
__declspec(dllimport) void Sleep(unsigned int);
typedef struct _FILE{
	void* handle;
	int8_t feof;
	int8_t ferror;
	char back;
} FILE;
void exitfunc(void){
	printf("%s\n", "atexit() test");
}
int mainCRTStartup(void){
	_init();
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
	
	FILE* ofile = fopen("3.txt", "w+");
	fprintf(ofile, "%s\n", "file test");
	printf("%s\n", "Written");
	fclose(ofile);
	
	system("notepad.exe");
	exit(0);
	return 0;
}
