#ifndef _STDLIBC_BITS_ALLTYPES_H_
#define _STDLIBC_BITS_ALLTYPES_H_

#if defined(__NEED_INT8T) && !defined(__DEFINED_INT8T)
#if defined(__GNUC__)
typedef __INT8_TYPE__ int8_t;
#elif defined(_MSC_VER)
typedef __int8 int8_t;
#else
typedef char int8_t;
#endif
#define __DEFINED_INT8T
#endif

#if defined(__NEED_INT16T) && !defined(__DEFINED_INT16T)
#if defined(__GNUC__)
typedef __INT16_TYPE__ int16_t;
#elif defined(_MSC_VER)
typedef __int16 int16_t;
#else
typedef short int16_t;
#endif
#define __DEFINED_INT16T
#endif

#if defined(__NEED_INT32T) && !defined(__DEFINED_INT32T)
#if defined(__GNUC__)
typedef __INT32_TYPE__ int32_t;
#elif defined(_MSC_VER)
typedef __int32 int32_t;
#else
typedef int int32_t;
#endif
#define __DEFINED_INT32T
#endif

#if defined(__NEED_INT64T) && !defined(__DEFINED_INT64T)
#if defined(__GNUC__)
typedef __INT64_TYPE__ int64_t;
#elif defined(_MSC_VER)
typedef __int64 int64_t;
#else
typedef long long int64_t;
#endif
#define __DEFINED_INT64T
#endif

#if defined(__NEED_UINT8T) && !defined(__DEFINED_UINT8T)
#if defined(__GNUC__)
typedef __UINT8_TYPE__ uint8_t;
#else
typedef unsigned char uint8_t;
#endif
#define __DEFINED_UINT8T
#endif

#if defined(__NEED_UINT16T) && !defined(__DEFINED_UINT16T)
#if defined(__GNUC__)
typedef __UINT16_TYPE__ uint16_t;
#else
typedef unsigned short uint16_t;
#endif
#define __DEFINED_UINT16T
#endif

#if defined(__NEED_UINT32T) && !defined(__DEFINED_UINT32T)
#if defined(__GNUC__)
typedef __UINT32_TYPE__ uint32_t;
#else
typedef unsigned int uint32_t;
#endif
#define __DEFINED_UINT32T
#endif

#if defined(__NEED_UINT64T) && !defined(__DEFINED_UINT64T)
#if defined(__GNUC__)
typedef __UINT64_TYPE__ uint64_t;
#else
typedef unsigned long long uint64_t;
#endif
#define __DEFINED_UINT64T
#endif

#if defined(__NEED_UINT64T) && !defined(__DEFINED_UINT64T)
#if defined(__GNUC__)
typedef __UINT64_TYPE__ uint64_t;
#else
typedef unsigned long long uint64_t;
#endif
#define __DEFINED_UINT64T
#endif

#if defined(__NEED_INT_FAST8T) && !defined(__DEFINED_INT_FAST8T)
#if defined(__GNUC__)
typedef __INT_FAST8_TYPE__ int_fast8_t;
#elif defined (__DEFINED_INT8T)
typedef int8_t int_fast8_t;
#else 
typedef char int_fast8_t;
#endif
#define __DEFINED_INT_FAST8T
#endif

#if defined(__NEED_INT_FAST16T) && !defined(__DEFINED_INT_FAST16T)
#if defined(__GNUC__)
typedef __INT_FAST16_TYPE__ int_fast16_t;
#elif defined (__DEFINED_INT16T)
typedef int16_t int_fast16_t;
#else 
typedef short int_fast16_t;
#endif
#define __DEFINED_INT_FAST16T
#endif

#if defined(__NEED_INT_FAST32T) && !defined(__DEFINED_INT_FAST32T)
#if defined(__GNUC__)
typedef __INT_FAST32_TYPE__ int_fast32_t;
#elif defined (__DEFINED_INT32T)
typedef int32_t int_fast32_t;
#else 
typedef int int_fast32_t;
#endif
#define __DEFINED_INT_FAST32T
#endif

#if defined(__NEED_INT_FAST64T) && !defined(__DEFINED_INT_FAST64T)
#if defined(__GNUC__)
typedef __INT_FAST64_TYPE__ int_fast64_t;
#elif defined (__DEFINED_INT64T)
typedef int64_t int_fast64_t;
#else 
typedef long long int_fast64_t;
#endif
#define __DEFINED_INT_FAST64T
#endif

#if defined(__NEED_UINT_FAST8T) && !defined(__DEFINED_UINT_FAST8T)
#if defined(__GNUC__)
typedef __UINT_FAST8_TYPE__ uint_fast8_t;
#elif defined (__DEFINED_UINT8T)
typedef uint8_t uint_fast8_t;
#else 
typedef unsigned char uint_fast8_t;
#endif
#define __DEFINED_UINT_FAST8T
#endif

#if defined(__NEED_UINT_FAST16T) && !defined(__DEFINED_UINT_FAST16T)
#if defined(__GNUC__)
typedef __UINT_FAST16_TYPE__ uint_fast16_t;
#elif defined (__DEFINED_UINT16T)
typedef uint16_t uint_fast16_t;
#else 
typedef unsigned short uint_fast16_t;
#endif
#define __DEFINED_UINT_FAST16T
#endif

#if defined(__NEED_UINT_FAST32T) && !defined(__DEFINED_UINT_FAST32T)
#if defined(__GNUC__)
typedef __UINT_FAST32_TYPE__ uint_fast32_t;
#elif defined (__DEFINED_UINT32T)
typedef uint32_t uint_fast32_t;
#else 
typedef unsigned int uint_fast32_t;
#endif
#define __DEFINED_UINT_FAST32T
#endif

#if defined(__NEED_UINT_FAST64T) && !defined(__DEFINED_UINT_FAST64T)
#if defined(__GNUC__)
typedef __UINT_FAST64_TYPE__ uint_fast64_t;
#elif defined (__DEFINED_UINT64T)
typedef uint64_t uint_fast64_t;
#else 
typedef unsigned long long uint_fast64_t;
#endif
#define __DEFINED_UINT_FAST64T
#endif

#if defined(__NEED_INT_LEAST8T) && !defined(__DEFINED_INT_LEAST8T)
#if defined(__GNUC__)
typedef __INT_LEAST8_TYPE__ int_least8_t;
#elif defined (__DEFINED_INT8T)
typedef int8_t int_least8_t;
#else 
typedef char int_least8_t;
#endif
#define __DEFINED_INT_LEAST8T
#endif

#if defined(__NEED_INT_LEAST16T) && !defined(__DEFINED_INT_LEAST16T)
#if defined(__GNUC__)
typedef __INT_LEAST16_TYPE__ int_least16_t;
#elif defined (__DEFINED_INT16T)
typedef int16_t int_least16_t;
#else 
typedef short int_least16_t;
#endif
#define __DEFINED_INT_LEAST16T
#endif

#if defined(__NEED_INT_LEAST32T) && !defined(__DEFINED_INT_LEAST32T)
#if defined(__GNUC__)
typedef __INT_LEAST32_TYPE__ int_least32_t;
#elif defined (__DEFINED_INT32T)
typedef int32_t int_least32_t;
#else 
typedef int int_least32_t;
#endif
#define __DEFINED_INT_LEAST32T
#endif

#if defined(__NEED_INT_LEAST64T) && !defined(__DEFINED_INT_LEAST64T)
#if defined(__GNUC__)
typedef __INT_LEAST64_TYPE__ int_least64_t;
#elif defined (__DEFINED_INT64T)
typedef int64_t int_least64_t;
#else 
typedef long long int_least64_t;
#endif
#define __DEFINED_INT_LEAST64T
#endif

#if defined(__NEED_UINT_LEAST8T) && !defined(__DEFINED_UINT_LEAST8T)
#if defined(__GNUC__)
typedef __UINT_LEAST8_TYPE__ uint_least8_t;
#elif defined (__DEFINED_UINT8T)
typedef uint8_t uint_least8_t;
#else 
typedef unsigned char uint_least8_t;
#endif
#define __DEFINED_UINT_LEAST8T
#endif

#if defined(__NEED_UINT_LEAST16T) && !defined(__DEFINED_UINT_LEAST16T)
#if defined(__GNUC__)
typedef __UINT_LEAST16_TYPE__ uint_least16_t;
#elif defined (__DEFINED_UINT16T)
typedef uint16_t uint_least16_t;
#else 
typedef unsigned short uint_least16_t;
#endif
#define __DEFINED_UINT_LEAST16T
#endif

#if defined(__NEED_UINT_LEAST32T) && !defined(__DEFINED_UINT_LEAST32T)
#if defined(__GNUC__)
typedef __UINT_LEAST32_TYPE__ uint_least32_t;
#elif defined (__DEFINED_UINT32T)
typedef uint32_t uint_least32_t;
#else 
typedef unsigned int uint_least32_t;
#endif
#define __DEFINED_UINT_LEAST32T
#endif

#if defined(__NEED_SIZET) && !defined(__DEFINED_SIZET)
#if defined(__GNUC__)
typedef __SIZE_TYPE__ size_t;
#elif defined (__DEFINED_UINT64T)
typedef uint64_t size_t;
#else 
typedef unsigned long long size_t;
#endif
#define __DEFINED_SIZET
#endif

#if defined(__NEED_INTMAXT) && !defined(__DEFINED_INTMAXT)
#if defined(__GNUC__)
typedef __INTMAX_TYPE__ intmax_t;
#elif defined (__DEFINED_INT64T)
typedef int64_t intmax_t;
#else 
typedef long long intmax_t;
#endif
#define __DEFINED_INTMAXT
#endif

#if defined(__NEED_UINTMAXT) && !defined(__DEFINED_UINTMAXT)
#if defined(__GNUC__)
typedef __UINTMAX_TYPE__ uintmax_t;
#elif defined (__DEFINED_UINT64T)
typedef uint64_t uintmax_t;
#else 
typedef unsigned long long uintmax_t;
#endif
#define __DEFINED_UINTMAXT
#endif

#if defined(__NEED_INTPTRT) && !defined(__DEFINED_INTPTRT)
#if defined(__GNUC__)
typedef __INTPTR_TYPE__ intptr_t;
#elif defined (__DEFINED_INT64T)
typedef int64_t intptr_t;
#else 
typedef long long intptr_t;
#endif
#define __DEFINED_INTPTRT
#endif

#if defined(__NEED_UINTPTRT) && !defined(__DEFINED_UINTPTRT)
#if defined(__GNUC__)
typedef __UINTPTR_TYPE__ uintptr_t;
#elif defined (__DEFINED_UINT64T)
typedef uint64_t uintptr_t;
#else 
typedef unsigned long long uintptr_t;
#endif
#define __DEFINED_UINTPTRT
#endif

#endif 