#include "../include/math.h"
#include "../include/fenv.h"
#include "../include/stdint.h"
#include "../include/stddef.h"

void __fpartsf(float arg, int* sgn, int* exp, int* mts) {
	union {double f; long long i;} u = {arg};
	if (sgn) *sgn = (u.i >> 31) & 0x1;
	if (exp) *exp = (u.i >> 24) & 0x7F8;
	if (mts) *mts = u.i & 0x7FFFFF;
}

void __fparts(double arg, int* sgn, int* exp, long* mts) {
	union {double f; long long i;} u = {arg};
	if (sgn) *sgn = (unsigned int)(u.i >> 62 & 0x1);
	if (exp) *exp = (unsigned int)(u.i >> 52 & 0x7FF);
	if (mts) *mts = (unsigned long)(u.i & 0xFFFFFFFFFFFFF);
}

int __isnrmlf(float arg) {
	int mts = 0;
	__fpartsf(arg, NULL, NULL, &mts);
	return (mts & 0x400000) != 0;
}

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

float fmodf(float x, float y) {
	if (isnan(x) || isnan(y))
		return NAN;
	if (!isfinite(x) || y == 0) {
		feraiseexcept(FE_INVALID);
		return NAN;
	}
	// -> TODO: fix
	// return x % y;
}

double fmod(double x, double y) {
	if (isnan(x) || isnan(y))
		return NAN;
	if (!isfinite(x) || y == 0) {
		feraiseexcept(FE_INVALID);
		return NAN;
	}
	// -> TODO: fix
	// return x % y;
}

long double fmodl(long double x, long double y) {
	if (isnan(x) || isnan(y))
		return NAN;
	if (!isfinite(x) || y == 0) {
		feraiseexcept(FE_INVALID);
		return NAN;
	}
	// -> TODO: fix
	// return x % y;
}

float remainderf(float x, float y) {
	if (isnan(x) || isnan(y))
		return NAN;
	if (!isfinite(x) || y == 0) {
		feraiseexcept(FE_INVALID);
		return NAN;
	}
	return x - (x/y) * y;
}

double remainder(double x, double y) {
	if (isnan(x) || isnan(y))
		return NAN;
	if (!isfinite(x) || y == 0) {
		feraiseexcept(FE_INVALID);
		return NAN;
	}
	return x - (x/y) * y;
}

long double remainderl(long double x, long double y) {
	if (isnan(x) || isnan(y))
		return NAN;
	if (!isfinite(x) || y == 0) {
		feraiseexcept(FE_INVALID);
		return NAN;
	}
	return x - (x/y) * y;
}

float remquof(float x, float y, int *quo) {
	if (isnan(x) || isnan(y))
		return NAN;
	if (!isfinite(x) || y == 0) {
		feraiseexcept(FE_INVALID);
		return NAN;
	}
	float divd = (x/y);
	// -> TODO: FIX
	// *quo = 0;
	// *quo |= ((*(int*)&divd) & (1LL << sizeof(divd) * 8 - 1));
	// *quo |= ((*(int*)&divd) & ((1 << 3) - 1)) << sizeof(divd) - sizeof(quo);
	return x - divd * y;
}

double remquo(double x, double y, int *quo) {
	if (isnan(x) || isnan(y))
		return NAN;
	if (!isfinite(x) || y == 0) {
		feraiseexcept(FE_INVALID);
		return NAN;
	}
	double divd = (x/y);
	// -> TODO: FIX
	// *quo = 0;
	// *quo |= ((*(int*)&divd) & (1LL << sizeof(divd) * 8 - 1));
	// *quo |= ((*(int*)&divd) & ((1 << 3) - 1)) << sizeof(divd) - sizeof(quo);
	return x - divd * y;
}

long double remquol(long double x, long double y, int *quo) {
	if (isnan(x) || isnan(y))
		return NAN;
	if (!isfinite(x) || y == 0) {
		feraiseexcept(FE_INVALID);
		return NAN;
	}
	long double divd = (x/y);
	// -> TODO: FIX
	// *quo = 0;
	// *quo |= ((*(int*)&divd) & (1LL << sizeof(divd) * 8 - 1));
	// *quo |= ((*(int*)&divd) & ((1 << 3) - 1)) << sizeof(divd) - sizeof(quo);
	return x - divd * y;
}

float fmaf(float x, float y, float z) {
	// this is suboptimal
	// there's a dedicated cpu instruction for this function
	// but i won't try to use it because
	return (x * y + z);
}

double fma(double x, double y, double z) {
	return (x * y + z);
}

long double fmal(long double x, long double y, long double z) {
	return (x * y + z);
}

float fmaxf(float x, float y) {
	return (x > y) ? x : y;
}

double fmax(double x, double y) {
	return (x > y) ? x : y;
}

long double fmaxl(long double x, long double y) {
	return (x > y) ? x : y;
}

float fminf(float x, float y) {
	return (x < y) ? x : y;
}

double fmin(double x, double y) {
	return (x < y) ? x : y;
}

long double fminl(long double x, long double y) {
	return (x < y) ? x : y;
}

float fdimf(float x, float y) {
	return fmaxf(0.f, x - y);
}

double fdim(double x, double y) {
	return fmax(0.f, x - y);
}

long double fdiml(long double x, long double y) {
	return fmaxl(0.f, x - y);
}

float truncf(float arg) {
	int exp = 0;
	__fpartsf(arg, NULL, &exp, NULL);
	if (exp > 150) return arg;
	if (exp < 128) return 0; 
	short rexp = -126 + exp - 1;
	union { unsigned int u; float f; } prt = {.u = arg};
	prt.u >>= 24 - rexp;
	prt.u <<= 24 - rexp;
	return prt.f; 
}

double trunc(double arg) {
	int exp = 0;
	__fparts(arg, NULL, &exp, NULL);
	if (exp > 564) return arg;
	if (exp < 512) return 0; 
	int rexp = -510 + exp - 1;
	union { unsigned long u; double f; } prt = {.u = arg};
	prt.u >>= 53 - rexp;
	prt.u <<= 53 - rexp;
	return prt.f; 
}

// -> TODO: Complete math.h 