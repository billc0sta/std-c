#ifndef _STDLIBC_STDINT_H_
#define _STDLIBC_STDINT_H_

#define __NEED_INT8T
#define __NEED_INT16T
#define __NEED_INT32T
#define __NEED_INT64T

#define __NEED_UINT8T
#define __NEED_UINT16T
#define __NEED_UINT32T
#define __NEED_UINT64T

#define __NEED_INT_FAST8T
#define __NEED_INT_FAST16T
#define __NEED_INT_FAST32T
#define __NEED_INT_FAST64T

#define __NEED_UINT_FAST8T
#define __NEED_UINT_FAST16T
#define __NEED_UINT_FAST32T
#define __NEED_UINT_FAST64T

#define __NEED_INT_LEAST8T
#define __NEED_INT_LEAST16T
#define __NEED_INT_LEAST32T
#define __NEED_INT_LEAST64T

#define __NEED_UINT_LEAST8T
#define __NEED_UINT_LEAST16T
#define __NEED_UINT_LEAST32T
#define __NEED_UINT_LEAST64T

#define __NEED_INTMAXT
#define __NEED_INTPTRT

#define __NEED_UINTMAXT
#define __NEED_UINTPTRT

#include "../bits/alltypes.h"

#define INT8_WIDTH  8
#define INT16_WIDTH 16
#define INT32_WIDTH 32
#define INT64_WIDTH 64

#define INT_FAST8_WIDTH  (sizeof(int_fast8_t) * 8)
#define INT_FAST16_WIDTH (sizeof(int_fast16_t) * 8)
#define INT_FAST32_WIDTH (sizeof(int_fast32_t) * 8)
#define INT_FAST64_WIDTH (sizeof(int_fast64_t) * 8)

#define INT_LEAST8_WIDTH  (sizeof(int_least8_t) * 8)
#define INT_LEAST16_WIDTH (sizeof(int_least16_t) * 8)
#define INT_LEAST32_WIDTH (sizeof(int_least32_t) * 8)
#define INT_LEAST64_WIDTH (sizeof(int_least64_t) * 8)

#define INTPTR_WIDTH (sizeof(intptr_t) * 8)
#define INTMAX_WIDTH (sizeof(intmax_t) * 8)

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

#define UINT8_WIDTH  8
#define UINT16_WIDTH 16
#define UINT32_WIDTH 32
#define UINT64_WIDTH 64

#define UINT_FAST8_WIDTH  (sizeof(uint_fast8_t) * 8)
#define UINT_FAST16_WIDTH (sizeof(uint_fast16_t) * 8)
#define UINT_FAST32_WIDTH (sizeof(uint_fast32_t) * 8)
#define UINT_FAST64_WIDTH (sizeof(uint_fast64_t) * 8)

#define UINT_LEAST8_WIDTH  (sizeof(uint_least8_t) * 8)
#define UINT_LEAST16_WIDTH (sizeof(uint_least16_t) * 8)
#define UINT_LEAST32_WIDTH (sizeof(uint_least32_t) * 8)
#define UINT_LEAST64_WIDTH (sizeof(uint_least64_t) * 8)

#define UINTPTR_WIDTH (sizeof(uintptr_t) * 8)
#define UINTMAX_WIDTH (sizeof(uintmax_t) * 8)

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
#define UINT64_C(c) c ## ULL

#define UINTMAX_C(c) c ## ULL

#endif