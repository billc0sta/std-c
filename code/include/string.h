#ifndef _STDLIBC_STRING_H_
#define _STDLIBC_STRING_H_

extern char* strtok_prev;

char* strcpy(char *restrict dest, const char *restrict src);
char* strncpy(char *restrict dest, const char *restrict src, size_t count);
char* strcat(char *restrict dest, const char *restrict src);
char* strncat(char *restrict dest, const char* restrict src, size_t count);
size_t strxfrm(char *restrict dest, const char *restrict src, size_t count);
char* strdup(const char* src);
char* strndup(const char* src, size_t size);
size_t strlen(const char* str);
int strcmp(const char* lhs, const char* rhs);
int strncmp(const char* lhs, const char* rhs, size_t count);
int strcoll(const char* lhs, const char* rhs);
char* strchr(const char* str, int chr);
char* strrchr(const char* str, int chr);
size_t strspn(const char* dest, const char* src);
size_t strcspn(const char* dest, const char* src);
char* strpbrk(const char* dest, const char* src);
char* strstr(const char* str, const char* substr);
char* strtok(char *restrict str, const char *restrict delim)
void* memchr(const void* ptr, int ch, size_t count);
int memcmp(const void* lhs, const void* rhs, size_t count);
void* memset(const void* dest, int ch, size_t count);
void* memcpy(void *restrict dest, const void *restrict src, size_t count);
void* memmove(void* dest, const void* src, size_t count);
void* memccpy(void *restrict dest, const void *restrict src, int ch, size_t count);
char* strerror(int errnum);

#endif