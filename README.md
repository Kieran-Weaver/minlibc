# minlibc

minlibc is a partial implementation of the C89/C90 standard library designed for
static linking on Win32.

## Purpose

minlibc is intended to be an alternative to MinGW for
applications which do not want to depend on msvcrt.dll. Instead, minlibc
uses only functions from ntdll.dll and kernel32.dll, on top of a freestanding
environment. It prioritizes small size and zero dependencies over strictly
adhering to the C89 standard. According to <https://nullprogram.com/blog/2016/02/28/>,
kernel32.dll and ntdll.dll get loaded for every process on Win32, so using them does not incur
any memory overhead, unlike when using msvcrt.dll.

## Building

The Makefile is designed for a cross-compiler at the moment. The Makefile
should work on MinGW if you set CC to gcc instead of x86_64-w64-mingw32-gcc.

## Test Program

The test program test.exe is run through wine. At the moment, it's full output
should be:

```
Hello World
1454471165
Low 1222957347
High 30844988
CLOCK 10 ms
(The current time)
(The current time, again)
Written
atexit() test
```

It should also create a file "3.txt" with the following contents:

```
file test
```

## Space Savings

The test program was recompiled using standard MinGW with `-Os -static`,
using the same version of the cross-compiler that is used to compile the
test program normally.

File Sizes:

```
MinGW		177147 bytes
minlibc		 23899 bytes
```

The overall space savings is 153248 bytes, or 86.5%.

## TODO

- Add proper test suite
- Add benchmark
- Implement remaining C89/C90/C99 functions
- Implement posix functions
- Add wchar support
- Add error handling
- Extract more functions from kernel32.dll and ntdll.dll listings
- Create a new gcc target triplet that uses minlibc

## Links and Acknowledgements

The ntdll.dll and kernel32.dll listings used to make this possible are from
<https://nullprogram.com/blog/2016/02/28/>. They list the exported symbols
from Windows XP SP3's ntdll.dll and kernel32.dll files.

Information on the function signatures was taken from MSDN, as well as from
<http://undocumented.ntinternals.net/>.
