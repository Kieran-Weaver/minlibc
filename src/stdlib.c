#include <stdlib.h>
#include <ntdll/rtlcrt.h>
#include <kernel32/heap.h>
static unsigned long rand_state = 0;
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
