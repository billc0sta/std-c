#include "../include/math.h"
#include "../include/fenv.h"
#include "../include/stdint.h"
#include "../include/limits.h"

union __fprt __nan = {0x7FC00000}, __inf = {0x7F800000};

int __isnrmlf(float arg) {
	union {float f; int i;} u = {arg};
	int mts = (u.i & 0x7FFFFF);
	return mts == 0 || mts >= 0x400000;
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
	return (float)(fmod(x, y));
}

double fmod(double x, double y) {
	return (double)(fmodl(x, y));
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
	return (float)(remainder(x, y));
}

double remainder(double x, double y) {
	return (double)(remainderl(x, y));
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
	return (float)(remquo(x, y, quo));
}

double remquo(double x, double y, int *quo) {
	return (double)(remquol(x, y, quo));
}

long double remquol(long double x, long double y, int *quo) {
	if (isnan(x) || isnan(y))
		return NAN;
	if (!isfinite(x) || y == 0) {
		feraiseexcept(FE_INVALID);
		return NAN;
	}
	long double divd = (x/y);
	*quo = 0;
	*quo |= signbit(divd) << 31;
	*quo |= (*(long long*)&divd) & 0x7; 
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
	union {float f; int i;} u = {arg};
	int exp = (u.i >> 24) & 0x7F8;
	exp -= 127;
	if (exp < 1) return 0;
	if (exp > 22) return arg;
	u.i >>= 23 - exp;
	u.i <<= 23 - exp;
	return u.f; 
}

double trunc(double arg) {
	union {float f; uint64_t i;} u = {arg};
	int exp = (u.i >> 53) & 0x7FF;
	exp -= 1023;
	if (exp < 1) return 0;
	if (exp > 51) return arg;
	u.i >>= 52 - exp;
	u.i <<= 52 - exp;
	return u.f;
}

long double truncl(long double arg) {
	// -> TODO: implement
}

// -> TODO: Complete math.h 