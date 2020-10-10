#include <stdlib.h>
#include <kernel32/heap.h>
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
