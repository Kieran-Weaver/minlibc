#ifndef W32_FCNTL_H
#define W32_FCNTL_H

#ifdef __cplusplus
extern "C" {
#endif

typedef int mode_t;
int  creat(const char *, mode_t);
int  fcntl(int, int, ...);
int  open(const char *, int, ...);

#ifdef __cplusplus
}
#endif

#endif
