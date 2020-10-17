#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <fcntl.h>
#include <kernel32/console.h>
#include <kernel32/handle.h>
#include <kernel32/stdio.h>
typedef struct _FILE{
	void* handle;
	int8_t feof;
	int8_t ferror;
	char back;
} FILE;
static FILE _stdin = {};
static FILE _stdout = {};
static FILE _stderr = {};
FILE* stdin = &_stdin;
FILE* stdout = &_stdout;
FILE* stderr = &_stderr;

static int __fmodeflags(const char *mode)
{
	int flags;
	switch (*mode){
		case 'r': 
			flags = O_RDONLY | O_EXCL;
			break;
		case 'w':
			flags = O_WRONLY | O_TRUNC;
			break;
		default :
			flags = O_RDONLY | O_EXCL;
			break;
	}
	if (strchr(mode, '+')) flags |= O_RDWR;
	if (*mode == 'a') flags |= O_APPEND;
	return flags;
}

FILE* fopen(const char* filename, const char* mode){
	int flags = __fmodeflags(mode);
	int fd = open(filename, flags);
	FILE* newfd = getfd(fd);
	return newfd;
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

	if (stream->back){
		char bck = stream->back;
		stream->back = 0;
		return bck;
	} else if (fread(data, 1, 1, stream) == 1){
		return data[0];
	} else {
		return EOF;
	}
}

char* fgets(char* str, int num, FILE* stream){
	char data = 0;
	int i = 0;

	while ((data != '\n') && (i < num) && (data != EOF)){
		data = fgetc(stream);
		str[i] = data;
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

int fflush(FILE* stream){
	FlushFileBuffers(stream->handle);
}

size_t fread(void* ptr, size_t size, size_t count, FILE* stream){
	size_t cnt;
	uint32_t temp;
	for (cnt = 0; cnt < count; cnt++){
		if (stream->back){
			memcpy(ptr, &stream->back, 1);
			stream->back = 0;
			if ((!ReadFile(stream->handle, ptr+1, size-1, &temp, NULL)) || (temp != (size-1))){
				break;
			}
		} else if ((!ReadFile(stream->handle, ptr, size, &temp, NULL)) || (temp != size)){
			break;
		}
		ptr += size;
	}
	return cnt;
}

size_t fwrite(const void* ptr, size_t size, size_t count, FILE* stream){
	size_t cnt;
	uint32_t temp;
	for (cnt = 0; cnt < count; cnt++){
		if ((!WriteFile(stream->handle, ptr, size, &temp, NULL)) || (temp != size)){
			break;
		} else {
			ptr += temp;
		}
	}
	return cnt;
}

int ungetc(int c, FILE* s){
	if (s->back){
		return EOF;
	} else {
		s->back = c;
		s->feof = 0;
		return s->back;
	}
}

void rewind(FILE* stream){
	fseek(stream, 0, SEEK_SET);
}

int fseek(FILE* stream, long offset, int origin){
	stream->back = 0;
	uint32_t off_low = offset & 0xFFFFFFFF;
	long off_high = ((uint64_t)offset) >> 32;
	uint32_t ret = SetFilePointer(stream->handle, off_low, &off_high, origin);
	return (ret == INVALID_SET_FILE_POINTER);
}

long int ftell(FILE* stream){
	long off_high = 0;
	uint32_t off_low = SetFilePointer(stream->handle, 0, &off_high, SEEK_CUR);
	uint64_t off = (uint64_t)(off_high) << 32 + off_low;
	return off;
}

int fgetpos (FILE * stream, fpos_t* pos){
	if (pos == NULL){
		return -1;
	} else {
		*pos = ftell(stream);
	}
}

int fsetpos (FILE * stream, const fpos_t* pos){
	if (pos == NULL){
		return -1;
	} else {
		fseek(stream, *pos, SEEK_SET);
	}
}

int fclose(FILE* stream){
	if (stream == NULL){
		return EOF;
	}
	CloseHandle(stream->handle);
	stream->feof = 0;
	stream->ferror = 0;
	stream->back = 0;
	if ((stream != stdin) && (stream != stdout) && (stream != stderr)){
		free(stream);
	}
	return 0;
}
