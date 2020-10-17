#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <kernel32/console.h>
#include <kernel32/stdio.h>
FILE* stdin = NULL;
FILE* stdout = NULL;
FILE* stderr = NULL;
int fflush(FILE* stream){
	FlushFileBuffers(stream);
}

int printf(const char* format, ...){
	va_list ap;
	va_start(ap, format);
	return vprintf(format, ap);
}

int vprintf(const char* format, va_list ap){
	return vfprintf(stdout, format, ap);
}

int fprintf(FILE* st, const char* format, ...){
	va_list ap;
	va_start(ap, format);
	return vfprintf(st, format, ap);
}

int vfprintf(FILE* st, const char* format, va_list ap){
	uint32_t ret;
	char tmpbuf[64] = {};
	char *abuf = tmpbuf;
	int size = _vsnprintf(abuf, 64, format, ap);

	if (size >= 64){
		abuf = malloc(size + 1);
		_vsnprintf(abuf, size, format, ap);
	}

	ret = size * fwrite(abuf, size, 1, st);

	if (size >= 64){
		free(abuf);
	}

	return ret;
}

int fgetc(FILE* stream){
	char data[4];

	if (fread(data, 1, 1, stream) == 1){
		return data[0];
	} else {
		return EOF;
	}
}

char* fgets(char* str, int num, FILE* stream){
	char data[4] = {};
	int i = 0;

	while ((data[0] != '\n') && (i < num) && (fread(data, 1, 1, stream) == 1)){
		str[i] = data[0];
		i++;
	}

	if (i){
		str[i] = '\0';
		return str;
	} else {
		return NULL;
	}
}

int fputc(int character, FILE * stream){
	unsigned char data[4] = {};
	data[0] = (unsigned char)character;
	
	if (fwrite(data, 1, 1, stream) == 1){
		return data[0];
	} else {
		return EOF;
	}
}

int fputs(const char* str, FILE* stream){
	if (fwrite(str, strlen(str), 1, stream) == 1){
		return 0;
	} else {
		return EOF;
	}
}

int getchar(void){
	return fgetc(stdin);
}

char* gets(char* str){
	char* tempstr = fgets(str, INT_MAX, stdin);
	if (tempstr){
		tempstr[strlen(tempstr)] = '\0';
	}
	return tempstr;
}


int putchar(int character){
	return fputc(character, stdout);
}

int puts(const char* str){
	if (fputs(str, stdout) == 0){
		return fputs("\r\n", stdout);
	} else {
		return EOF;
	}
}

size_t fread(void* ptr, size_t size, size_t count, FILE* stream){
	size_t cnt;
	uint32_t temp;
	for (cnt = 0; cnt < count; cnt++){
		if ((!ReadFile(stream, ptr, size, &temp, NULL)) || (temp != size)){
			break;
		} else {
			ptr += temp;
		}
	}
	return cnt;
}

size_t fwrite(const void* ptr, size_t size, size_t count, FILE* stream){
	size_t cnt;
	uint32_t temp;
	for (cnt = 0; cnt < count; cnt++){
		if ((!WriteFile(stream, ptr, size, &temp, NULL)) || (temp != size)){
			break;
		} else {
			ptr += temp;
		}
	}
	return cnt;
}
