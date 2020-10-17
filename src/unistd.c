#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <util/list.h>
#include <kernel32/stdio.h>
#include <kernel32/console.h>
#include <kernel32/process.h>
typedef struct _FILE{
	void* handle;
	int8_t feof;
	int8_t ferror;
	char back;
} FILE;
static _list_t filetable = {};
static void closefunc(void* data){
	fclose(*((FILE**)data));
}
void _init(void){
	_LIST_PUSH(&filetable, stdin);
	_LIST_PUSH(&filetable, stdout);
	_LIST_PUSH(&filetable, stderr);
	stdin->handle = GetStdHandle(STD_INPUT_HANDLE);
	stdout->handle = GetStdHandle(STD_OUTPUT_HANDLE);
	stderr->handle = GetStdHandle(STD_ERROR_HANDLE);
}
int chdir(const char *);
int close(int fd){
	return fclose(getfd(fd));
}
int creat(const char * path, mode_t mode){
	return open(path, O_WRONLY|O_CREAT|O_TRUNC, mode);
}
int dup(int);
int dup2(int, int);
void _exit(int code){
	list_iter(&filetable, closefunc);
	list_free(&filetable);
	ExitProcess(code);
}
int fchdir(int);
int fcntl(int, int, ...);
int fdatasync(int);
int fsync(int);
int ftruncate(int, off_t);
char *getcwd(char *, size_t);
FILE* getfd(int index){
	FILE* data;
	_LIST_GET(&filetable, data, index);
	return data;
}
char *getwd(char *);
int isatty(int);
int lockf(int, int, off_t);
off_t lseek(int, off_t, int);
int open(const char * path, int oflag, ...){
	int fd;
	FILE *hdl = malloc(sizeof(FILE));
	hdl->handle = CreateFileA(path, oflag & O_RDWR, 7, NULL, oflag & 7, 0x80, NULL);
	if (oflag & O_APPEND){
		fseek(hdl, 0, SEEK_END);
	}
	list_len(&filetable, &fd);
	_LIST_PUSH(&filetable, hdl);
	return fd;
}
ssize_t pread(int, void *, size_t, off_t);
ssize_t pwrite(int, const void *, size_t, off_t);
ssize_t read(int fd, void * buf, size_t nb){
	return fread(buf, 1, nb, getfd(fd));
}
int rmdir(const char *);
void setfd(int index, FILE* ptr){
	_LIST_SET(&filetable, ptr, index);
}
unsigned int sleep(unsigned int);
void swab(const void * _src, void * _dest, ssize_t nbytes){
	const unsigned short * src = _src;
	unsigned short * dst = _dest;
	for (; nbytes>1; nbytes-= 2){
		dst[0] = src[1];
		dst[1] = src[0];
		dst += 2;
		src += 2;
	}
}
void sync(void);
int truncate(const char *, off_t);
int unlink(const char *);
ssize_t write(int fd, const void *buf, size_t nb){
	return fwrite(buf, 1, nb, getfd(fd));
}
