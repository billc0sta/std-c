#ifndef _STDLIBC_STDLIB_H_
#define _STDLIBC_STDLIB_H_

float atof(const char* str);
int atoi(const char* str);
long atol(const char* str);
long long atoll(const char* str);
long strtol(const char* str, char** str_end, int base);
long long strtoll(const char* str, char** str_end, int base);
unsigned long strtoul(const char* str, char** str_end, int base);
unsigned long long strtoull(const char* str, char** str_end, int base); 
float strtof(const char* str, char** str_end);
double strtod(const char* str, char** str_end);
long double strtold(const char* str, char** str_end);

#endif