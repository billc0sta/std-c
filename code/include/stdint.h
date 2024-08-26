#ifndef _STDLIBC_STDINT_H_
#define _STDLIBC_STDINT_H_

#ifdef __GNUC__ 

typedef __INT8_TYPE__ int8_t;
typedef __INT16_TYPE__ int16_t;
typedef __INT32_TYPE__ int32_t;
typedef __INT64_TYPE__ int64_t;

typedef __UINT8_TYPE__ uint8_t;
typedef __UINT16_TYPE__ uint16_t;
typedef __UINT32_TYPE__ uint32_t;
typedef __UINT64_TYPE__ uint64_t;

#endif

#ifdef _MSC_BUILD

typedef __int8 int8_t;
typedef __int16 int16_t;
typedef __int32 int32_t;
typedef __int64 int64_t;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;

#endif

typedef int8_t int_fast8_t;
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef int64_t int_fast64_t;

typedef int8_t int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;
typedef int64_t int_least64_t;

typedef int64_t intmax_t;
typedef int64_t intptr_t;

typedef uint8_t uint_fast8_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
typedef uint64_t uint_fast64_t;

typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
typedef uint64_t uint_least64_t;

typedef uint64_t uintmax_t;
typedef uint64_t uintptr_t;

#define INT8_WIDTH 8
#define INT16_WIDTH 16
#define INT32_WIDTH 32
#define INT64_WIDTH 64

#define INT_FAST8_WIDTH 8
#define INT_FAST16_WIDTH 16
#define INT_FAST32_WIDTH 32
#define INT_FAST64_WIDTH 64

#define INT_LEAST8_WIDTH 8
#define INT_LEAST16_WIDTH 16
#define INT_LEAST32_WIDTH 32
#define INT_LEAST64_WIDTH 64

#define INTPTR_WIDTH 64
#define INTMAX_WIDTH 64

#define INT8_MIN (0 | 0xFF)
#define INT16_MIN (0 | 0xFFFF)
#define INT32_MIN (0 | 0xFFFFFFFF)
#define INT64_MIN (0 | 0xFFFFFFFFFFFFFFFF)

#define INT_FAST8_MIN (0 | 0xFF)
#define INT_FAST16_MIN (0 | 0xFFFF)
#define INT_FAST32_MIN (0 | 0xFFFFFFFF)
#define INT_FAST64_MIN (0 | 0xFFFFFFFFFFFFFFFF)

#define INT_LEAST8_MIN (0 | 0xFF)
#define INT_LEAST16_MIN (0 | 0xFFFF)
#define INT_LEAST32_MIN (0 | 0xFFFFFFFF)
#define INT_LEAST64_MIN (0 | 0xFFFFFFFFFFFFFFFF)

#define INTPTR_MIN (0 | 0xFFFFFFFFFFFFFFFF)
#define INTMAX_MIN (0 | 0xFFFFFFFFFFFFFFFF)

#define INT8_MAX (0 | 0x7F)
#define INT16_MAX (0 | 0x7FFF)
#define INT32_MAX (0 | 0x7FFFFFFF)
#define INT64_MAX (0 | 0x7FFFFFFFFFFFFFFF)

#define INT_FAST8_MAX (0 | 0x7F)
#define INT_FAST16_MAX (0 | 0x7FFF)
#define INT_FAST32_MAX (0 | 0x7FFFFFFF)
#define INT_FAST64_MAX (0 | 0x7FFFFFFFFFFFFFFF)

#define INT_LEAST8_MAX (0 | 0x7F)
#define INT_LEAST16_MAX (0 | 0x7FFF)
#define INT_LEAST32_MAX (0 | 0x7FFFFFFF)
#define INT_LEAST64_MAX (0 | 0x7FFFFFFFFFFFFFFF)

#define INTPTR_MAX (0 | 0x7FFFFFFFFFFFFFFF)
#define INTMAX_MAX (0 | 0x7FFFFFFFFFFFFFFF)

#define UINT8_WIDTH 8
#define UINT16_WIDTH 16
#define UINT32_WIDTH 32
#define UINT64_WIDTH 64

#define UINT_FAST8_WIDTH 8
#define UINT_FAST16_WIDTH 16
#define UINT_FAST32_WIDTH 32
#define UINT_FAST64_WIDTH 64

#define UINT_LEAST8_WIDTH 8
#define UINT_LEAST16_WIDTH 16
#define UINT_LEAST32_WIDTH 32
#define UINT_LEAST64_WIDTH 64

#define UINTPTR_WIDTH 64
#define UINTMAX_WIDTH 64

#define UINT8_MIN  0
#define UINT16_MIN 0
#define UINT32_MIN 0
#define UINT64_MIN 0

#define UINT_FAST8_MIN  0
#define UINT_FAST16_MIN 0
#define UINT_FAST32_MIN 0
#define UINT_FAST64_MIN 0

#define UINT_LEAST8_MIN 0
#define UINT_LEAST16_MIN 0
#define UINT_LEAST32_MIN 0
#define UINT_LEAST64_MIN 0

#define UINTPTR_MIN 0
#define UINTMAX_MIN 0

#define UINT8_MAX 0xFF
#define UINT16_MAX 0xFFFF
#define UINT32_MAX 0xFFFFFFFF
#define UINT64_MAX 0xFFFFFFFFFFFFFFFF

#define UINT_FAST8_MAX 0xFF
#define UINT_FAST16_MAX 0xFFFF
#define UINT_FAST32_MAX 0xFFFFFFFF
#define UINT_FAST64_MAX 0xFFFFFFFFFFFFFFFF

#define UINT_LEAST8_MAX 0xFF
#define UINT_LEAST16_MAX 0xFFFF
#define UINT_LEAST32_MAX 0xFFFFFFFF
#define UINT_LEAST64_MAX 0xFFFFFFFFFFFFFFFF

#define UINTPTR_MAX 0xFFFFFFFFFFFFFFFF
#define UINTMAX_MAX 0xFFFFFFFFFFFFFFFF

#define INT8_C(c) c
#define INT16_C(c) c
#define INT32_C(c) c
#define INT64_C(c) c ## L

#define INTMAX_C(c) c ## L

#define UINT8_C(c) c ## U
#define UINT16_C(c) c ## U
#define UINT32_C(c) c ## U
#define UINT64_C(c) c ## UL

#define UINTMAX_C(c) c ## UL 

#endif