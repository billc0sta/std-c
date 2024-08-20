#include <stddef.h>
#ifndef STDLIBC_H_
#define STDLIBC_H_


// ====== __stddef.h__ ====== //
// commented to disable conflicting types error

// #define NULL 0
// typedef unsigned long size_t;
// typedef signed long ptrdiff_t;
// typedef unsigned long max_align_t;


// ====== __assert.h__ ====== //
#ifdef NDEBUG
#define assert(condition) ;
#else
// -> TODO: requires fwrite() and abort()
#endif

// ====== __math.h__ ====== //
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

float fmod(float x, float y) {
	if ()
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

#endif