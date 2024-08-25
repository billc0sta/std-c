#ifndef _STDLIBC_WCHAR_H_
#define _STDLIBC_WCHAR_H_

typedef int wchar_t; 
typedef long int wint_t;
typedef int wctrans_t;
typedef int wctype_t;
#define WEOF -1;
#define WCHAR_MIN INT_MIN;
#define WCHAR_MAX INT_MAX;

extern wchar_t* wstrtok_prev;

long wcstol(const wchar_t* str, wchar_t** str_end, int base);
long long wcstoll(const wchar_t* restrict str, wchar_t** restrict str_end, int base);
unsigned long wcstoul(const wchar_t* str, wchar_t** str_end, int base);
unsigned long long wcstoull(const wchar_t* str, wchar_t** str_end, int base);
float wcstof(const wchar_t* str, wchar_t** str_end);
double wcstod(const wchar_t* str, wchar_t** str_end);
long double wcstold(const wchar_t* str, wchar_t** str_end);
wchar_t* wcscpy(wchar_t* dest, const wchar_t* src);
wchar_t* wcsncpy(wchar_t* dest, const wchar_t* src, size_t count);
wchar_t* wcscat(wchar_t* dest, const wchar_t src);
wchar_t* wcsncat(wchar_t* dest, const wchar_t* src, size_t count);
size_t wscxfrm(char *restrict dest, const char *restrict src, size_t count);
size_t wsclen(const wchar_t* str);
int wsccmp(const wchar_t* lhs, const wchar_t* rhs);
int wscncmp(const wchar_t* lhs, const wchar_t* rhs, size_t count);
int wsccoll(const wchar_t* lhs, const wchar_t* rhs);
wchar_t* wscchr(const wchar_t* str, wchar_t chr);
wchar_t* wscrchr(const wchar_t* str, wchar_t chr);
size_t wscspn(const wchar_t* dest, const wchar_t* src);
size_t wsccspn(const wchar_t* dest, const wchar_t* src);
char* wcspbrk(const wchar_t* dest, const wchar_t* src);
wchar_t* wcsstr(const wchar_t* str, const wchar_t* substr);
wchar_t* wcstok(wchar_t *restrict str, const wchar_t *restrict delim)
wchar_t* wmemchr(const wchar_t* ptr, wchar_t ch, size_t count);
int wmemcmp(const wchar_t* lhs, const wchar_t* rhs, size_t count);
wchar_t* wmemset(const wchar_t* dest, wchar_t ch, size_t count);
wchar_t* wmemcpy(wchar_t* dest, const wchar_t* src, size_t count);
wchar_t* wmemmove(wchar_t* dest, const wchar_t* src, size_t count);

#endif 