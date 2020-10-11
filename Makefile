CC=x86_64-w64-mingw32-gcc
CFLAGS=-Os -ffreestanding -I include -mconsole -fno-stack-check -fno-stack-protector -mno-stack-arg-probe
LDFLAGS=-ffreestanding -static -mconsole -nostdlib -lntdll -lkernel32 -lntdllcrt
LIBC_SRCS=$(shell find src -path "*.c")
LIBC_OBJS=$(patsubst %.c, %.o, $(LIBC_SRCS))
SRCS=test.c
OBJS=$(patsubst %.c, %.o, $(SRCS))
all: test.exe

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

libminc.a: $(LIBC_OBJS)
	ar rcs $@ $^

test.exe: $(OBJS) libminc.a
	$(CC) $(CFLAGS) -L. $(OBJS) -lminc $(LDFLAGS) -o test

clean:
	rm -fr test.exe $(OBJS) $(LIBC_OBJS) libminc.a
