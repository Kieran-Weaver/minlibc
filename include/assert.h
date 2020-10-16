#ifndef W32_ASSERT_H
#define W32_ASSERT_H

#include <ntdll/rtlcrt.h>

#ifdef assert
#undef assert
#endif

#ifdef NDEBUG
#define assert(x) (void)0
#else
#define assert(x) ((void)((x) || (RtlAssert(#x, __FILE__, __LINE__, __func__),0)))
#endif

#endif
