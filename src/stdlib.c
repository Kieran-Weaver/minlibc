#include <stdlib.h>
#include <string.h>
#include <ntdll/rtlcrt.h>
#include <kernel32/environ.h>
#include <kernel32/heap.h>
#include <kernel32/handle.h>
#include <kernel32/object.h>
#include <kernel32/process.h>
#define _NUM_EXIT 16
#define ENVBUFLEN 256
#ifndef PATH_MAX
#define PATH_MAX 260
#endif
static unsigned long rand_state = 0;
static char envbuf[ENVBUFLEN] = {};
typedef void (*_atexit_func)(void);
typedef struct _exit_val{
	int num_funcs;
	struct _exit_val* next;
	_atexit_func funcs[_NUM_EXIT];
} _exit_t;

static _exit_t exit_state = {0, NULL, {}};

void* malloc(size_t sz){
	void* heap = GetProcessHeap();
	return HeapAlloc(heap, 0, sz);
}

void* calloc(size_t sz){
	void* heap = GetProcessHeap();
	return HeapAlloc(heap, 8, sz);
}

void* realloc(void *ptr, size_t sz){
	void* heap = GetProcessHeap();
	return HeapReAlloc(heap, 0, ptr, sz);
}

void free(void *ptr){
	void* heap = GetProcessHeap();
	HeapFree(heap, 0, ptr);
}

unsigned int rand(void){
	return RtlRandomEx(&rand_state);
}

void srand(unsigned int seed){
	rand_state = seed;
}

void abort(void){
	TerminateProcess(GetCurrentProcess(), 1);
}

int atexit(_atexit_func func){
	_exit_t * curr = &exit_state;
	while (curr->next != NULL){
		curr = curr->next;
	}
	curr->funcs[curr->num_funcs] = func;
	curr->num_funcs++;
	if (curr->num_funcs == _NUM_EXIT){
		curr->next = calloc(sizeof(_exit_t));
	}
}

static void call_exitfuncs(_exit_t* curr){
	int i;
	for (i = 0; i < curr->num_funcs; i++){
		curr->funcs[i]();
	}
	if (curr->next != NULL){
		call_exitfuncs(curr->next);
		free(curr->next);
	}
}

void exit(int code){
	call_exitfuncs(&exit_state);
	ExitProcess(code);
}

char *getenv(const char* val){
	GetEnvironmentVariableA(val, envbuf, ENVBUFLEN);
	return envbuf;
}

int system(const char* name){
	if (name == NULL){
		return 1;
	} else {
		char temp[PATH_MAX] = {0};
		strcpy(temp, name);
		startup_info_t si = {0};
		si.cb = sizeof(si);
		process_info_t pi = {0};
		CreateProcessA(NULL, temp, NULL, NULL, 0, 0, NULL, NULL, &si, &pi);
		WaitForSingleObject(pi.hProcess, 0xFFFFFFFF);
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	return 0;
}

div_t div(int x, int y){
	div_t dv;
	dv.quot = x/y;
	dv.rem = x%y;
	return dv;
}

ldiv_t ldiv(long x, long y){
	ldiv_t dv;
	dv.quot = x/y;
	dv.rem = x%y;
	return dv;
}
