#include "../include/wctype.h"

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