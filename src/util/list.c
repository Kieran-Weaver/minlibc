#include <util/list.h>
#include <stdlib.h>
#include <string.h>
int list_push(_list_t* _list, const void* data, unsigned int size){
	if (_list){
		while (_list->next){
			_list = _list->next;
		}
		memcpy(_list->elems + _list->count, data, size);
		_list->count++;
		if (_list->count == _NUM_ELEMENTS){
			_list->next = calloc(0, sizeof(_list_t));
		}
		return 0;
	}
	return 1;
}

int list_pop(_list_t* _list, void* data, unsigned int size){
	if (_list){
		while ((_list->next) && (_list->next->count)){
			_list = _list->next;
		}
		if (_list->count == _NUM_ELEMENTS){
			free(_list->next);
			_list->next = NULL;
		}
		_list->count--;
		memcpy(data, _list->elems + _list->count, size);
		return 0;
	}
	return 1;
}

static void* get_elem(_list_t* _list, unsigned int index){
	if (_list){
		while (index > _NUM_ELEMENTS){
			_list = _list->next;
			index -= _NUM_ELEMENTS;
		}
		return _list->elems + index;
	}
	return NULL;
}

int list_set(_list_t* _list, unsigned int index, const void* data, unsigned int size){
	void* location = get_elem(_list, index);
	if (location){
		memcpy(location, data, size);
		return 0;
	}
	return 1;
}

int list_get(_list_t* _list, unsigned int index, void* data, unsigned int size){
	const void* location = get_elem(_list, index);
	if (location){
		memcpy(data, location, size);
		return 0;
	}
	return 1;
}

int list_iter(_list_t* _list, _list_cb func){
	int i = 0;
	if (_list){
		for (i = 0; i < _list->count; i++){
			func(_list->elems + i);
		}
		list_iter(_list->next, func);
	}
	return 0;
}

int list_backiter(_list_t* _list, _list_cb func){
	int i = 0;
	if (_list){
		list_backiter(_list->next, func);
		for (i = (_list->count - 1); i >= 0; i--){
			func(_list->elems + i);
		}
	}
	return 0;
}

int list_free(_list_t* _list){
	if (_list){
		list_free(_list->next);
		if (_list->next){
			free(_list->next);
			_list->next = NULL;
			_list->count = 0;
		}
	}
	return 0;
}
