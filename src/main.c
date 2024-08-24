#include <stdio.h>

void __fparts(double arg, unsigned int* sgn, unsigned int* exp, unsigned long* mts) {
	unsigned int* ptr = (unsigned int*)&arg; 
	if (sgn) *sgn = (*ptr >> 62) & 0x1;
	if (exp) *exp = (*ptr >> 53) & 0x7FF;
	if (mts) *mts = (*ptr & 0xFFFFFFFFFFFFF);
}

double trunc(double arg) {
	unsigned int exp = 0;
	__fparts(arg, NULL, &exp, NULL);
	printf("in trunc: exp -> %u\n", exp); 
	if (exp > 1076) return arg;
	if (exp < 1024) return 0;
	int rexp = -510 + exp - 1;
	union { unsigned long u; double f; } prt = {.u = arg};
	prt.u >>= 53 - rexp;
	prt.u <<= 53 - rexp;
	return prt.f; 
}

int main() {
	double vl = -12412.3232; 
	unsigned int sgn, exp;
	unsigned long mts;
	printf("double: %f, truncated: %f", vl, trunc(vl));
	return 0;
}