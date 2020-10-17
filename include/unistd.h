#ifndef W32_UNISTD_H
#define W32_UNISTD_H

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#undef O_RDONLY
#undef O_WRONLY
#undef O_RDWR
#undef O_APPEND
#undef O_CREAT
#undef O_EXCL
#undef O_TRUNC
#define O_RDONLY 0x80000000
#define O_WRONLY 0x40000000
#define O_RDWR (O_RDONLY | O_WRONLY)
#define O_APPEND 8
#define O_CREAT  1
#define O_EXCL   3
#define O_TRUNC  2

typedef uint64_t off_t;
void         _init(void);
int          chdir(const char *);
int          close(int);
int          dup(int);
int          dup2(int, int);
void         _exit(int);
int          fchdir(int);
int          fdatasync(int);
int          fsync(int);
int          ftruncate(int, off_t);
char        *getcwd(char *, size_t);
FILE        *getfd(int);
char        *getwd(char *);
int          isatty(int);
int          lockf(int, int, off_t);
off_t        lseek(int, off_t, int);
ssize_t      pread(int, void *, size_t, off_t);
ssize_t      pwrite(int, const void *, size_t, off_t);
ssize_t      read(int, void *, size_t);
int          rmdir(const char *);
void         setfd(int, FILE*);
unsigned int sleep(unsigned int);
void         swab(const void *, void *, ssize_t);
void         sync(void);
int          truncate(const char *, off_t);
int          unlink(const char *);
ssize_t      write(int, const void *, size_t);

#ifdef __cplusplus
}
#endif

#endif
