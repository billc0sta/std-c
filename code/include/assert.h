#ifndef _STDLIBC_ASSERT_H_
#define _STDLIBC_ASSERT_H_

#ifdef NDEBUG
#define assert(condition) ((void)0)
#else
// -> TODO: requires fprintf() and abort()
#endif

#endif