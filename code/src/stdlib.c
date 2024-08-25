#include "../include/stdlib.h"

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