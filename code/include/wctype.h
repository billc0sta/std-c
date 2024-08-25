#ifndef _STDLIBC_WCTYPE_H_
#define _STDLIBC_WCTYPE_H_

int iswalnum(wint_t ch);
int iswalpha(wint_t ch);
int iswlower(wint_t ch);
int iswupper(wint_t ch);
int iswdigit(wint_t ch);
int iswxdigit(wint_t ch);
int iswcntrl(wint_t ch);
int iswgraph(wint_t ch);
int iswspace(wint_t ch);
int iswblank(wint_t ch);
int iswprint(wint_t ch);
int iswpunct(wint_t ch);
int towlower(wint_t ch);
int towupper(wint_t ch);
wint_t towctrans(wint_t wc, wctrans_t desc);
wctrans_t wctrans(const char* str);

#endif