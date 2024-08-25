#include "../include/ctype.h"

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
