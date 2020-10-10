#include <stdio.h>
#include <stdlib.h>
#include <ntdll/stdio.h>
#include <kernel32/console.h>
int printf(const char* format, ...){
	uint32_t ret;
	va_list ap;
	va_start(ap, format);
	char tmpbuf[64] = {};
	char *abuf = tmpbuf;
	void* stdhdl = GetStdHandle(STD_OUTPUT_HANDLE);
	int size = _vsnprintf(abuf, 64, format, ap);

	if (size >= 64){
		abuf = malloc(size + 1);
		_vsnprintf(abuf, size, format, ap);
	}

	WriteConsoleA(stdhdl, abuf, size, &ret, NULL);

	if (size >= 64){
		free(abuf);
	}

	return ret;
}
