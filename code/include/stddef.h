#ifndef _STDLIBC_STDDEF_H_
#define _STDLIBC_STDDEF_H_

#if __cplusplus >= 201103L
#define NULL nullptr
#elif defined(__cplusplus)
#define NULL 0L
#else
#define NULL ((void*)0)
#endif


#ifdef __GNUC__

typedef __SIZE_TYPE__ size_t;
typedef __PTRDIFF_TYPE__ ptrdiff_t;

#else

typedef unsigned long size_t;
typedef unsigned long ptrdiff_t;

#endif

#endif 