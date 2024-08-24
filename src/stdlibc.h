#include <stddef.h>
#ifndef STDLIBC_H_
#define STDLIBC_H_


// ====== __stddef.h__ ====== //
// commented to disable conflicting types error

// #define NULL 0
// typedef unsigned long size_t;
// typedef signed long ptrdiff_t; // typedef unsigned long max_align_t;


// ====== __assert.h__ ====== //
#ifdef NDEBUG
#define assert(condition) ((void)0)
#else
// -> TODO: requires fprintf() and abort()
#endif

// ====== __stdnoreturn__ ====== //
#define noreturn void;


// ====== __fenv.h__ ====== //
#define FE_DIVBYZERO  1
#define FE_INEXACT    2
#define FE_INVALID    4
#define FE_OVERFLOW   8
#define FE_UNDERFLOW  16
#define FE_ALL_EXCEPT FE_DIVBYZERO | FE_INEXACT | \
                      FE_INVALID | FE_OVERFLOW |  \
                      FE_UNDERFLOW
#define FE_DOWNWARD   1
#define FE_TONEAREST  2
#define FE_TOWARDZERO 3 
#define FE_UPWARD     4
typedef int fexcept_t;
typedef struct {
	fexcept_t __exceptions;
	unsigned int __rounding;
	int __hold
} fenv_t;

fenv_t __pubfenv { .__exceptions = 0, .__rounding = FE_DOWNWARD, .__hold = 0 };
fexcept_t __prev_exceptions;

int feclearexcept(int excepts) {
	excepts = ~excepts;
	__pubfenv.__exceptions &= excepts;
	return 0; 
}

int fetestexcept(int excepts) {
	return (excepts & __pubfenv.__exceptions) == excepts; 
}

int feraiseexcept(int excepts) {
	__pubfenv.__exceptions |= excepts;
	return 0;
}

int fegetexceptflag(fexcept_t* flagp, int excepts) {
	if (!flagp) return 1;
	*flagp = __pubfenv.__exceptions & excepts;
	return 0; 
}

int fesetexceptflag(const fexcept_t* flagp, int excepts) {
	if (!flagp) return 1;
	__pubfenv.__exceptions |= *flagp & excepts;
	return 0; 
}

int fegetenv(fenv_t* envp) {
	if (!envp) return 1;
	*envp = __pubfenv;
	return 0;
}

int fesetenv(const fenv_t* envp) {
	if (!envp) return 1;
	__pubfenv = *envp;
	return 0;
}

int feholdexcept(fenv_t* envp) {
	if (!envp || __pubfenv.__hold) return 1;
	__prev_exceptions      = __pubfenv.__exceptions;
	__pubfenv.__hold       = 1;
	__pubfenv.__exceptions = 0;
	*envp = __pubfenv; 
	return 0; 
}

int feupdateenv(const fenv_t* envp) {
	if (!envp || !__pubfenv.__hold) return 1;
	__pubfenv              = *envp;
	__pubfenv.__hold       = 0;
	__pubfenv.__exceptions |= __prev_exceptions;
	return 0; 
}

// ====== __math.h__ ====== //

void __fpartsf(float arg, unsigned int* sgn, unsigned int* exp, unsigned int* mts) {
	unsigned int* ptr = (unsigned int*)&arg;
	if (sgn) *sgn = (*ptr >> 31) & 0x1;
	if (exp) *exp = (*ptr >> 24) & 0x7F8;
	if (mts) *mts = *ptr & 0x7FFFFF;
}

void __fparts(double arg, unsigned int* sgn, unsigned int* exp, unsigned long* mts) {
	unsigned int* ptr = (unsigned int*)&arg; 
	if (sgn) *sgn = (*ptr >> 62) & 0x1;
	if (exp) *exp = (*ptr >> 53) & 0x7FF;
	if (mts) *mts = (*ptr & 0xFFFFFFFFFFFFF);
}

int __isnrmlf(float arg) {
	unsigned int mts = 0;
	__fpartsf(arg, NULL, NULL, &mts);
	return (mts & 0x400000) != 0;
}

union {
	unsigned int u;
	float f;
} __nan = { .u = 0x7FC00000 }, __inf = { .u = 0x7F800000 };
#define NAN (__nan.f)
#define INFINITY (__inf.f)
#define isnan(arg) (arg != arg)
#define isfinite(arg) (!isnan(arg) && arg != INFINITY)
#define isinf(arg) (!isnan(arg) && arg == INFINITY)
#define isnormal(arg) (arg != 0 && !isnan(arg) && !isinf(arg) && __isnrmlf((float)arg))
#define signbit(arg) (arg < 0)
#define isgreater(x, y) (x > y)
#define isgreaterequal(x, y) (!(x < y))
#define isless(x, y) (x < y)
#define islessequal(x, y) (!(x > y))
#define islessgreater(x, y) (x != y)
#define isunordered(x, y) (isnan(x) || isnan(y)) 
#define HUGE_VAL ((double)INFINITY)
#define HUGE_VALF ((float)INFINITY)
#define HUGE_VALL ((long double)INFINITY)
#define FP_NORMAL 1
#define FP_SUBNORMAL 2
#define FP_ZERO 4
#define FP_INFINITE 8
#define FP_NAN 16
#define MATH_ERRNO 1
#define MATH_ERREXCEPT 2
#define math_errhandling MATH_ERREXCEPT

float fabsf(float arg) {
	if (arg >= 0) return arg;
	return -arg;
}

double fabs(double arg) {
	if (arg >= 0) return arg;
	return -arg;
}

long double fabsl(long double arg) {
	if (arg >= 0) return arg;
	return -arg;
}

float fmodf(float x, float y) {
	if (isnan(x) || isnan(y))
		return NAN;
	if (!isfinite(x) || y == 0) {
		feraiseexcept(FE_INVALID);
		return NAN;
	}
	return x % y;
}

double fmod(double x, double y) {
	if (isnan(x) || isnan(y))
		return NAN;
	if (!isfinite(x) || y == 0) {
		feraiseexcept(FE_INVALID);
		return NAN;
	}
	return x % y;
}

long double fmodl(long double x, long double y) {
	if (isnan(x) || isnan(y))
		return NAN;
	if (!isfinite(x) || y == 0) {
		feraiseexcept(FE_INVALID);
		return NAN;
	}
	return x % y;
}

float remainderf(float x, float y) {
	if (isnan(x) || isnan(y))
		return NAN;
	if (!isfinite(x) || y == 0) {
		feraiseexcept(FE_INVALID);
		return NAN;
	}
	return x - (x/y) * y;
}

double remainder(double x, double y) {
	if (isnan(x) || isnan(y))
		return NAN;
	if (!isfinite(x) || y == 0) {
		feraiseexcept(FE_INVALID);
		return NAN;
	}
	return x - (x/y) * y;
}

long double remainderl(long double x, long double y) {
	if (isnan(x) || isnan(y))
		return NAN;
	if (!isfinite(x) || y == 0) {
		feraiseexcept(FE_INVALID);
		return NAN;
	}
	return x - (x/y) * y;
}

float remquof(float x, float y, int *quo) {
	if (isnan(x) || isnan(y))
		return NAN;
	if (!isfinite(x) || y == 0) {
		feraiseexcept(FE_INVALID);
		return NAN;
	}
	float divd = (x/y);
	*quo = 0; 
	*quo |= (divd & (1 << sizeof(divd) * 8 - 1));
	*quo |= (divd & (float)((1 << 3) - 1)) << sizeof(divd) - sizeof(qou);
	return x - divd * y;
}

double remquo(double x, double y, int *quo) {
	if (isnan(x) || isnan(y))
		return NAN;
	if (!isfinite(x) || y == 0) {
		feraiseexcept(FE_INVALID);
		return NAN;
	}
	double divd = (x/y);
	*quo = 0; 
	*quo |= (divd & (1 << sizeof(divd) * 8 - 1));
	*quo |= (divd & (double)((1 << 3) - 1)) << sizeof(divd) - sizeof(qou);
	return x - divd * y;
}

long double remquol(long double x, long double y, int *quo) {
	if (isnan(x) || isnan(y))
		return NAN;
	if (!isfinite(x) || y == 0) {
		feraiseexcept(FE_INVALID);
		return NAN;
	}
	long double divd = (x/y);
	*quo = 0; 
	*quo |= (divd & (1 << sizeof(divd) * 8 - 1));
	*quo |= (divd & (long double)((1 << 3) - 1)) << sizeof(divd) - sizeof(qou);
	return x - divd * y;
}

float fmaf(float x, float y, float z) {
	// this is suboptimal
	// there's a dedicated cpu instruction for this function
	// but i won't try to use it because
	return (x * y + z);
}

double fma(double x, double y, double z) {
	return (x * y + z);
}

long double fmal(long double x, long double y, long double z) {
	return (x * y + z);
}

float fmaxf(float x, float y) {
	return (x > y) ? x : y;
}

double fmax(double x, double y) {
	return (x > y) ? x : y;
}

long double fmaxl(long double x, long double y) {
	return (x > y) ? x : y;
}

float fminf(float x, float y) {
	return (x < y) ? x : y;
}

double fmin(double x, double y) {
	return (x < y) ? x : y;
}

long double fminl(long double x, long double y) {
	return (x < y) ? x : y;
}

float fdimf(float x, float y) {
	return fmaxf(0.f, x - y);
}

double fdim(double x, double y) {
	return fmax(0.f, x - y);
}

long double fdimf(long double x, long double y) {
	return fmaxl(0.f, x - y);
}

float truncf(float arg) {
	unsigned int exp = 0;
	__fpartsf(arg, NULL, &exp, NULL);
	if (exp > 150) return arg;
	if (exp < 128) return 0; 
	short rexp = -126 + exp - 1;
	union { unsigned int u; float f; } prt = {.u = arg};
	prt.u >>= 24 - rexp;
	prt.u <<= 24 - rexp;
	return prt.f; 
}

double trunc(double arg) {
	unsigned int exp = 0;
	__fparts(arg, NULL, &exp, NULL);
	if (exp > 564) return arg;
	if (exp < 512) return 0; 
	int rexp = -510 + exp - 1;
	union { unsigned long u; double f; } prt = {.u = arg};
	prt.u >>= 53 - rexp;
	prt.u <<= 53 - rexp;
	return prt.f; 
}

// -> TODO: Complete math.h 

// ====== __complex.h__ ====== //
#define imaginary _Imaginary
#define complex _Complex
#define _Complex_I 1 (const float _Complex)((float)0 + (float)y * 1)
#define I _Complex_I
#define CMPLX(x, y) ((double complex)((double)x + (double)y * I))
#define CMPLXF(x, y) ((float complex)((float)x + (float)y * I))
#define CMPLXL(x, y) ((long double complex)((long double)x + (long double)y * I))

double creal(double complex z) {
	return (double)z;
}

float crealf(float complex z) {
	return (float)z;
}

long double creall(long double complex z) {
	return (long double)z;
}

double cimag(double complex z) {
	return *((double*)&z + 1);
}

float cimagf(float complex z) {
	return *((float*)&z + 1);
}

long double cimagl(long double complex z) {
	return *((long double*)&z + 1);
}

double cabs(double complex z) {
	double rel = creal(z);
	double img = cimag(z);
	double cbsq = rel * rel + img * img;
	// -> TODO: requires sqrt()
	// return sqrt(cbsq);
}

float cabsf(float complex z) {
	float rel = creal(z);
	float img = cimag(z);
	float cbsq = rel * rel + img * img;
	// -> TODO: requires fsqrt()
	// return sqrtf(cbsq);
}

long double cabsl(long double complex z) {
	long double rel = creal(z);
	long double img = cimag(z);
	long double cbsq = rel * rel + img * img;
	// -> TODO: requires sqrtl()
	// return sqrtl(cbsq);
}

// -> TODO: Complete complex.h

// ====== __ctype.h__ ====== //
int isalnum(int ch) {
	return 
	ch >= 'A' && ch <= 'Z' ||
	ch >= 'a' && ch <= 'z' ||
	ch >= '0' && ch <= '9';
}

int isalpha(int ch) {
	return 
	ch >= 'A' && ch <= 'Z' ||
	ch >= 'a' && ch <= 'z';
}

int islower(int ch) {
	return ch >= 'a' && ch <= 'z';
}

int isupper(int ch) {
	return ch >= 'A' && ch <= 'Z';
}

int isdigit(int ch) {
	return ch >= '0' && ch <= '9';
}

int isxdigit(int ch) {
	return 
	ch >= '0' && ch <= '9' ||
	ch >= 'A' && ch <= 'F' ||
	ch >= 'a' && ch <= 'f';
}

int iscntrl(int ch) {
	return ch >= '\0' && ch <= '\37' || ch == '\177';
}

int isgraph(int ch) {
	return ch >= '!' && ch <= '~'; 
}

int isspace(int ch) {
	return ch >= '\t' && ch <= '\r' || ' ';
}

int isblank(int ch) {
	return ch == '\t' && ch == ' '; 
}

int isprint(int ch) {
	return ch >= ' ' && ch <= '~';
}

int ispunct(int ch) {
	return 
	ch >= '!' && ch <= '/' ||
	ch >= ':' && ch <= '@' ||
	ch >= '[' && ch <= '`' ||
	ch >= '{' && ch <= '~';
}


int tolower(int ch) {
	if (!isupper(ch)) return ch;
	return ch + ' '; 
}

int toupper(int ch) {
	if (!islower(ch)) return ch;
	return ch - ' ';  
}

// ====== __wctype.h__ ====== //

// -> TODO: wint_t requires wchar.h 

int iswalnum(wint_t ch) {
	return 
	ch >= 'A' && ch <= 'Z' ||
	ch >= 'a' && ch <= 'z' ||
	ch >= '0' && ch <= '9';
}

int iswalpha(wint_t ch) {
	return 
	ch >= 'A' && ch <= 'Z' ||
	ch >= 'a' && ch <= 'z';
}

int iswlower(wint_t ch) {
	return ch >= 'a' && ch <= 'z';
}

int iswupper(wint_t ch) {
	return ch >= 'A' && ch <= 'Z';
}

int iswdigit(wint_t ch) {
	return ch >= '0' && ch <= '9';
}

int iswxdigit(wint_t ch) {
	return 
	ch >= '0' && ch <= '9' ||
	ch >= 'A' && ch <= 'F' ||
	ch >= 'a' && ch <= 'f';
}

int iswcntrl(wint_t ch) {
	return ch >= '\0' && ch <= '\37' || ch == '\177';
}

int iswgraph(wint_t ch) {
	return ch >= '!' && ch <= '~'; 
}

int iswspace(wint_t ch) {
	return ch >= '\t' && ch <= '\r' || ' ';
}

int iswblank(wint_t ch) {
	return ch == '\t' && ch == ' '; 
}

int iswprint(wint_t ch) {
	return ch >= ' ' && ch <= '~';
}

int iswpunct(wint_t ch) {
	return 
	ch >= '!' && ch <= '/' ||
	ch >= ':' && ch <= '@' ||
	ch >= '[' && ch <= '`' ||
	ch >= '{' && ch <= '~';
}

int towlower(wint_t ch) {
	if (!isupper(ch)) return ch;
	return ch + ' '; 
}

int towupper(wint_t ch) {
	if (!islower(ch)) return ch;
	return ch - ' ';  
}

wint_t towctrans(wint_t wc, wctrans_t desc) {
	// -> TODO: requires setlocale()
}

wctrans_t wctrans(const char* str) {
	// -> TODO: requirest setlocale()
}

// ====== __stdlib.h__ ====== //

float atof(const char* str) {
	return (float)strtod(str, NULL);

}

int atoi(const char* str) {
	return (int)atol(str);
}

long atol(const char* str) {
	return (long)atoll(str); 
}

long long atoll(const char* str) {
	return strtoll(str, NULL, 0);
}

long strtol(const char* str, char** str_end, int base) {
	return (long)strtold(str, str_end, base);
}

long long strtoll(const char* str, char** str_end, int base) {
	if (base != 0 && base < 2 || base > 36) 
		return 0;
	long long ret = 0;
	int sign = 0;
	char c = 0;
	while(isspace(*str)) ++str;
	if (*str == '-') {
		sign = 1;
		++str;
	}
	if (*str == '0') {
		if (base != 0) 
			return 0;
		c = *(++str);
		if (((c == 'X' || c == 'x') && base != 16) || base != 8)
			return 0;
		if (c == 'X' || c == 'x') 
			++str;
	}
	if (*str == 0)
	while ((c = *str) != '\0') {
		if (isdigit(c))
			c -= '0';
		else if (isalpha(c))
			c -= isupper(c) ? 'A' - 10 : 'a' - 10;
		added = ret * base + c - ret;
		if (sign && LLONG_MIN + ret <= added)
			return LLONG_MIN;
		else if (LLONG_MAX - ret <= added)
			return LLONG_MAX;
		ret += added;
	}
	if (str_end) str_end = str;
	return ret * -sign;
}

unsigned long strtoul(const char* str, char** str_end, int base) {
	return (unsigned long)strtol(str, str_end, base);
}

unsigned long long strtoull(const char* str, char** str_end, int base) {
	return (unsigned long long)strtoll(str, str_end, base);
}

float strtof(const char* str, char** str_end) {
	return (float)strtod(str, str_end);  
} 

double strtod(const char* str, char** str_end) {
	return (double)strtold(str, str_end);  
}

long double strtold(const char* str, char** str_end) {
	int sign = 0, hex = 0, dot = 0;
	long double ret = 0, dec = 0.1f; 
	char c = 0;
	while(isspace(*str)) ++str;
	if ((c = *str) == '-') {
		sign = 1;
		++str;
	}

	char expression[20] = { '\0' };
	const char* bg = str;
	while ((c = *str) != '\0' && str++ - bg < 20) 
		expression[str-bg] = tolower(c);
	expression[min(str-bg, 19)] = '\0';
	if (strcmp(expression, "INF") || strcmp(expression, "INFINITY"))
		return INF * -sign;
	else if (strcmp(expression, "NAN"))
		return NAN * -sign;
	str = bg; 
	if ((c = *str++) == '0') {
		c = *str++;
		if (c == 'x' || c == 'X')
			hex = 1;
		else return 0.0;
	}
	while((c = *str++) != '\0') {
		if (c == 'E' || c == 'e') {
			c = *(++str);
			int esign = 0;
			if (c == '-') esign = 1;
			int power = 0;
			while((c = *str++) != '\0') {
				if (!isdigit(c)) return 0.f;
				power *= 10; 
				power += c - '0';
			}
			power = pow(10, (esign) ? -power : power);
			ret *= power;
			break; 
		}
		else if (isdigit(c)) c -= '0';
		else if (isalpha(c)) c -= (isupper(c)) ? 'A' - 10 : 'a' - 10;
		else if (c == '.') {
			if (dot) return 0.f; 
			dot = 1;
		}
		else return 0.f;
		if (c >= 0 && c <= 15) {
			if (dot) {
				ret += c * dec;
				dec *= 0.1;
			}
			else { 
				ret *= 10;
				ret += c;
			}
		}
	}
	if (str_end) str_end = str;
	return ret * -sign;
}

// ====== __string.h__ ====== //

char* strcpy(char *restrict dest, const char *restrict src) {
	char* bg = dest;
	while(*src != '\0')
		*dest++ = *src++; 
	*dest = '\0';
	return bg; 
}

char* strncpy(char *restrict dest, const char *restrict src, size_t count) {
	char* bg = dest;
	while(count-- > 0) {
		*dest++ = *src; 
		if (*src != '\0') ++src;
	}
	return bg;
}

char* strcat(char *restrict dest, const char *restrict src) {
	char* bg = dest;
	while(*dest != '\0') ++dest;
	while(*src != '\0') *dest++ = *src++;
	*dest = '\0'; 
	return bg; 
}

char* strncat(char *restrict dest, const char* restrict src, size_t count) {
	char* bg = dest;
	while(*dest != '\0') ++dest;
	while(count-- > 0 && *src != '\0')
		*dest++ = *src++; 
	*dest = '\0'; 
	return bg;
}

size_t strxfrm(char *restrict dest, const char *restrict src, size_t count) {
	// -> TODO: requires setlocale() 
}

char* strdup(const char* src) {
	// -> TODO: requires malloc()
}

char* strndup(const char* src, size_t size) {
	// -> TODO: requires malloc()
}

size_t strlen(const char* str) {
	size_t c;
	while(*str++ != '\0') ++c;
	return c; 
}

int strcmp(const char* lhs, const char* rhs) {
	while(*lhs != '\0' && *rhs != '\0') {
		char lc = *lhs++;
		char rc = *rhs++;
		if (lc < rc) return -1;
		if (lc > rc) return  1;
	}
	if (*rhs != '\0') return -1;
	if (*lhs != '\0') return  1;
	return 0;
}

int strncmp(const char* lhs, const char* rhs, size_t count) {
	while(count-- > 0 && *lhs != '\0' && *rhs != '\0') {
		char lc = *lhs++;
		char rc = *rhs++;
		if (lc < rc) return -1;
		if (lc > rc) return  1;
	}
	if (count > 0) {
		if (*rhs != '\0') return -1;
		if (*lhs != '\0') return  1;
	} 
	return 0;
}

int strcoll(const char* lhs, const char* rhs) {
	// -> TODO: requires setlocale()
}

char* strchr(const char* str, int chr) {
	char c = (char)chr;
	while(*str != '\0') {
		if (c == *str) return (char*)str;
		++str; 
	}
	if (c == '\0') return (char*)str;
	return NULL;
}

char* strrchr(const char* str, int chr) {
	char c = (char)chr;
	int i = 0;
	while(str[i] != '\0') ++i;
	while(i >= 0) {
		if (str[i] == c) return (char*)str + i;
		--i;  
	}
	return NULL; 
}

size_t strspn(const char* dest, const char* src) {
	size_t c = 0;
	while (strchr(src, dest[c]) != NULL) ++c;
	return c; 
}


size_t strcspn(const char* dest, const char* src) {
	size_t c = 0;
	while (strchr(src, dest[c]) == NULL) ++c;
	return c; 
}

char* strpbrk(const char* dest, const char* src) {
	const char* srcbg = src;
	while(*dest != '\0') {
		while(*src != '\0') {
			if (*src == *dest) return (char*)dest;
			++src;
		}
		src = srcbg; 
		++dest;
	}
	return NULL;
}

char* strstr(const char* str, const char* substr) {
	size_t sslen = strlen(substr);
	size_t matched = 0;
	while (*str != '\0' && matched != sslen) {
		if (*str == substr[matched]) ++matched;
		else matched = 0;
		++str; 
	}
	if (matched == sslen) return (char*)(str - sslen); 
	return NULL;
}

static char* strtok_prev = NULL;
char* strtok(char *restrict str, const char *restrict delim) {
	if (str == NULL) str = strtok_prev;
	while (*str != '\0') {
		char* tok = strchr(delim, *str);
		if (tok == NULL) {
			static char* strtok_prev = NULL;
			tok = str;
			while (delim != '\0') {
				char* end = strchr(tok, *delim);
				if (end != NULL) {
					*end = '\0';
					strtok_prev = end + 1;
				}
				++delim; 
			}
			return tok;
		}
		++str;
	}
	return NULL;
}

void* memchr(const void* ptr, int ch, size_t count) {
	unsigned char* search = (unsigned char*)ptr;
	unsigned char c = (unsigned char)ch;
	while(count-- > 0) {
		if (*search == c) return search;
		++search;
	}
	return NULL;
}

int memcmp(const void* lhs, const void* rhs, size_t count) {
	unsigned char* lsr = (unsigned char*)lhs;
	unsigned char* rsr = (unsigned char*)rhs;
	for (int i = 0; i < count; ++i) {
		if (lsr[i] < rsr[i]) return -1;
		if (lsr[i] > rsr[i]) return  1;
	}
	return 0; 
}

void* memset(const void* dest, int ch, size_t count) {
	unsigned char* ptr = (unsigned char*)dest;
	unsigned char c = (unsigned char)ch;
	while(count-- > 0) {
		*ptr++ = c;
	}
	return (void*)dest; 
}

void* memcpy(void *restrict dest, const void *restrict src, size_t count) {
	unsigned char* dptr = (unsigned char*)dest;
	unsigned char* sptr = (unsigned char*)src;
	while(count-- > 0) 
		*dptr++ = *sptr++;
	return dest; 
}

void* memmove(void* dest, const void* src, size_t count) {
	unsigned char* dptr = (unsigned char*)dest;
	unsigned char* sptr = (unsigned char*)src;
	while(count-- > 0) 
		*dptr++ = *sptr++;
	return dest; 
}

void* memccpy(void *restrict dest, const void *restrict src, int ch, size_t count) {
	unsigned char* dptr = (unsigned char*)dest;
	unsigned char* sptr = (unsigned char*)src;
	unsigned char c = (unsigned char)ch;

	while(count-- > 0) {
		*dptr = *sptr;
		if (*sptr == c) break;
		++sptr;
		++dptr;
	}
	return dest; 
}

char* strerror(int errnum) {
	// -> TODO: requires setlocale()
}

// ====== __wchar.h__ ====== //
typedef int wchar_t; 
typedef long int wint_t;
typedef int wctrans_t;
typedef int wctype_t;
#define WEOF -1;
#define WCHAR_MIN INT_MIN;
#define WCHAR_MAX INT_MAX;  

long wcstol(const wchar_t* str, wchar_t** str_end, int base) {
	return (long)wcstoll(str, str_end, base);
}

long long wcstoll(const wchar_t* restrict str, wchar_t** restrict str_end, int base) {
	if (base != 0 && base < 2 || base > 36) 
		return 0;
	long long ret = 0;
	int sign = 0;
	wchar_t c = 0;
	while(iswspace(*str)) ++str;
	if (*str == '-') {
		sign = 1;
		++str;
	}
	if (*str == '0') {
		if (base != 0) 
			return 0;
		c = *(++str);
		if (((c == 'X' || c == 'x') && base != 16) || base != 8)
			return 0;
		if (c == 'X' || c == 'x') 
			++str;
	}
	if (*str == 0)
	while ((c = *str) != '\0') {
		if (iswdigit(c))
			c -= '0';
		else if (iswalpha(c))
			c -= iswupper(c) ? 'A' - 10 : 'a' - 10;
		added = ret * base + c - ret;
		if (sign && LLONG_MIN + ret <= added)
			return LLONG_MIN;
		else if (LLONG_MAX - ret <= added)
			return LLONG_MAX;
		ret += added;
	}
	if (str_end) str_end = str;
	return ret * -sign;
}

unsigned long wcstoul(const wchar_t* str, wchar_t** str_end, int base) {
	return (unsigned long)wcstol(str, str_end, base);
}

unsigned long long wcstoull(const wchar_t* str, wchar_t** str_end, int base) {
	return (unsigned long long)wcstoll(str, str_end, base);
}

float wcstof(const wchar_t* str, wchar_t** str_end) {
	return (float)wcstod(str, str_end);  
} 

double wcstod(const wchar_t* str, wchar_t** str_end) {
	return (double)wcstold(str, str_end);  
}

long double wcstold(const wchar_t* str, wchar_t** str_end) {
	int sign = 0, hex = 0, dot = 0;
	long double ret = 0, dec = 0.1f; 
	wchar_t c = 0;
	while(isspace(*str)) ++str;
	if ((c = *str) == '-') {
		sign = 1;
		++str;
	}

	wchar_t expression[20] = { '\0' };
	const wchar_t* bg = str;
	while ((c = *str) != '\0' && str++ - bg < 20) 
		expression[str-bg] = towlower(c);
	expression[min(str-bg, 19)] = '\0';
	if (wcscmp(expression, "INF") || wcscmp(expression, "INFINITY"))
		return INF * -sign;
	else if (wcscmp(expression, "NAN"))
		return NAN * -sign;
	str = bg; 
	if ((c = *str++) == '0') {
		c = *str++;
		if (c == 'x' || c == 'X')
			hex = 1;
		else return 0.0;
	}
	while((c = *str++) != '\0') {
		if (c == 'E' || c == 'e') {
			c = *(++str);
			int esign = 0;
			if (c == '-') esign = 1;
			int power = 0;
			while((c = *str++) != '\0') {
				if (!iswdigit(c)) return 0.f;
				power *= 10; 
				power += c - '0';
			}
			power = pow(10, (esign) ? -power : power);
			ret *= power;
			break; 
		}
		else if (iswdigit(c)) c -= '0';
		else if (iswalpha(c)) c -= (iswupper(c)) ? 'A' - 10 : 'a' - 10;
		else if (c == '.') {
			if (dot) return 0.f; 
			dot = 1;
		}
		else return 0.f;
		if (c >= 0 && c <= 15) {
			if (dot) {
				ret += c * dec;
				dec *= 0.1;
			}
			else { 
				ret *= 10;
				ret += c;
			}
		}
	}
	if (str_end) str_end = str;
	return ret * -sign;
}

wchar_t* wcscpy(wchar_t* dest, const wchar_t* src) {
	wchar_t* bg = dest;
	while(*src != '\0')
		*dest++ = *src++; 
	*dest = '\0';
	return bg; 
}

wchar_t* wcsncpy(wchar_t* dest, const wchar_t* src, size_t count) {
	wchar_t* bg = dest;
	while(count-- > 0) {
		*dest++ = *src; 
		if (*src != '\0') ++src;
	}
	return bg;
}

wchar_t* wcscat(wchar_t* dest, const wchar_t src) {
	wchar_t* bg = dest;
	while(*dest != '\0') ++dest;
	while(*src != '\0') *dest++ = *src++;
	*dest = '\0'; 
	return bg; 
}

wchar_t* wcsncat(wchar_t* dest, const wchar_t* src, size_t count) {
	wchar_t* bg = dest;
	while(*dest != '\0') ++dest;
	while(count-- > 0 && *src != '\0')
		*dest++ = *src++; 
	*dest = '\0'; 
	return bg;
}

size_t wscxfrm(char *restrict dest, const char *restrict src, size_t count) {
	// -> TODO: requires setlocale() 
}

size_t wsclen(const wchar_t* str) {
	size_t c;
	while(*str++ != '\0') ++c;
	return c; 
}

int wsccmp(const wchar_t* lhs, const wchar_t* rhs) {
	while(*lhs != '\0' && *rhs != '\0') {
		wchar_t lc = *lhs++;
		wchar_t rc = *rhs++;
		if (lc < rc) return -1;
		if (lc > rc) return  1;
	}
	if (*rhs != '\0') return -1;
	if (*lhs != '\0') return  1;
	return 0;
}

int wscncmp(const wchar_t* lhs, const wchar_t* rhs, size_t count) {
	while(count-- > 0 && *lhs != '\0' && *rhs != '\0') {
		wchar_t lc = *lhs++;
		wchar_t rc = *rhs++;
		if (lc < rc) return -1;
		if (lc > rc) return  1;
	}
	if (count > 0) {
		if (*rhs != '\0') return -1;
		if (*lhs != '\0') return  1;
	} 
	return 0;
}

int wsccoll(const wchar_t* lhs, const wchar_t* rhs) {
	// -> TODO: requires setlocale()
}

wchar_t* wscchr(const wchar_t* str, wchar_t chr) {
	while(*str != '\0') {
		if (chr == *str) return (wchar_t*)str;
		++str; 
	}
	if (c == '\0') return (wchar_t*)str;
	return NULL;
}

wchar_t* wscrchr(const wchar_t* str, wchar_t chr) {
	int i = 0;
	while(str[i] != '\0') ++i;
	while(i >= 0) {
		if (str[i] == chr) return (wchar_t *)str + i;
		--i;  
	}
	return NULL; 
}

size_t wscspn(const wchar_t* dest, const wchar_t* src) {
	size_t c = 0;
	while (wcschr(src, dest[c]) != NULL) ++c;
	return c; 
}


size_t wsccspn(const wchar_t* dest, const wchar_t* src) {
	size_t c = 0;
	while (wcschr(src, dest[c]) == NULL) ++c;
	return c; 
}

char* wcspbrk(const wchar_t* dest, const wchar_t* src) {
	const wchar_t* srcbg = src;
	while(*dest != '\0') {
		while(*src != '\0') {
			if (*src == *dest) return (wchar_t*)dest;
			++src;
		}
		src = srcbg; 
		++dest;
	}
	return NULL;
}

wchar_t* wcsstr(const wchar_t* str, const wchar_t* substr) {
	size_t sslen = wcslen(substr);
	size_t matched = 0;
	while (*str != '\0' && matched != sslen) {
		if (*str == substr[matched]) ++matched;
		else matched = 0;
		++str; 
	}
	if (matched == sslen) return (wchar_t*)(str - sslen); 
	return NULL;
}

static wchar_t* wstrtok_prev = NULL;
wchar_t* wcstok(wchar_t *restrict str, const wchar_t *restrict delim) {
	if (str == NULL) str = wstrtok_prev;
	while (*str != '\0') {
		wchar_t* tok = wcschr(delim, *str);
		if (tok == NULL) {
			static wchar_t* strtok_prev = NULL;
			tok = str;
			while (delim != '\0') {
				wchar_t* end = wcschr(tok, *delim);
				if (end != NULL) {
					*end = '\0';
					wstrtok_prev = end + 1;
				}
				++delim; 
			}
			return tok;
		}
		++str;
	}
	return NULL;
}

wchar_t* wmemchr(const wchar_t* ptr, wchar_t ch, size_t count) {
	while(count-- > 0) {
		if (*ptr == ch) return search;
		++ptr;
	}
	return NULL;
}

int wmemcmp(const wchar_t* lhs, const wchar_t* rhs, size_t count) {
	for (int i = 0; i < count; ++i) {
		if (lhs[i] < rhs[i]) return -1;
		if (lhs[i] > rhs[i]) return  1;
	}
	return 0; 
}

wchar_t* wmemset(const wchar_t* dest, wchar_t ch, size_t count) {
	while(count-- > 0) {
		*dest++ = ch;
	}
	return dest; 
}

wchar_t* wmemcpy(wchar_t* dest, const wchar_t* src, size_t count) {
	while(count-- > 0) 
		*dest++ = *src++;
	return dest; 
}

wchar_t* wmemmove(wchar_t* dest, const wchar_t* src, size_t count) {
	while(count-- > 0) 
		*dptr++ = *sptr++;
	return dest; 
}

#endif