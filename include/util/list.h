#ifndef GENERIC_LIST_H
#define GENERIC_LIST_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _NUM_ELEMENTS
#define _NUM_ELEMENTS 16
#endif

// Generic List
// This implementation has a maximum size of sizeof(uintptr_t) bytes per element
// API:
//  _list is always passed as a pointer
//  data is always passed by value
//  _LIST_PUSH(_list, data): Adds an element to the end of the list
//  _LIST_POP(_list, data): Removes an element from the end of the list, stores it into data
//  _LIST_SET(_list, data, index): Sets an element in the list, does not check bounds
//  _LIST_GET(_list, data, index): Gets an element from the list, does not check bounds
//  list_iter(list, func): Calls func on every element in the list, in forwards order
//  list_backiter(list, func): Calls func on every element in the list, in backwards order
//  list_free(list): Deletes list
//  All functions return 1 on error and 0 on success
typedef struct _generic_list{
	int count;
	struct _generic_list* next;
	uintptr_t elems[_NUM_ELEMENTS]; // To ensure alignment, not necessarily an array of pointers
} _list_t;

typedef void (*_list_cb)(void*);

#define _LIST_PUSH(_list, data) (list_push(_list, &data, sizeof(data)))
#define _LIST_POP(_list, data) (list_pop(_list, &data, sizeof(data)))
#define _LIST_SET(_list, data, index) (list_set(_list, index, &data, sizeof(data)))
#define _LIST_GET(_list, data, index) (list_get(_list, index, &data, sizeof(data)))

int list_push(_list_t* _list, const void* data, unsigned int size);
int list_pop(_list_t* _list, void* data, unsigned int size);
int list_set(_list_t* _list, unsigned int index, const void* data, unsigned int size);
int list_get(_list_t* _list, unsigned int index, void* data, unsigned int size);
int list_len(_list_t* _list, int* ret);
int list_iter(_list_t* _list, _list_cb func);
int list_backiter(_list_t* _list, _list_cb func);
int list_free(_list_t* _list);

#ifdef __cplusplus
}
#endif

#endif
