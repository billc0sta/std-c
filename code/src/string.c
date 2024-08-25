#include "../include/string.h"

char* strtok_prev = NULL;

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
