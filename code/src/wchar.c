#include "../include/wchar.h"

wchar_t* wstrtok_prev = NULL;

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