#ifndef _STDLIBC_MATH_H_
#define _STDLIBC_MATH_H_

int __isnrmlf(float arg);

union __fprt {
	unsigned int u;
	float f;
}; extern union __fprt __nan, __inf;

#define NAN (__nan.f)
#define INFINITY (__inf.f)
#define isnan(arg) (arg != arg)
#define isfinite(arg) (!isnan(arg) && arg != INFINITY)
#define isinf(arg) (!isnan(arg) && arg == INFINITY)
#define isnormal(arg) (arg != 0 && !isnan(arg) && !isinf(arg) && __isnrmlf((float)arg))
#define signbit(arg) (arg < 0)
#define isgreater(x, y) (x > y)
#define isgreaterequal(x, y) (!(x < y))
#define isless(x, y) (x < y)
#define islessequal(x, y) (!(x > y))
#define islessgreater(x, y) (x != y)
#define isunordered(x, y) (isnan(x) || isnan(y)) 
#define HUGE_VAL ((double)INFINITY)
#define HUGE_VALF ((float)INFINITY)
#define HUGE_VALL ((long double)INFINITY)
#define FP_NORMAL 1
#define FP_SUBNORMAL 2
#define FP_ZERO 4
#define FP_INFINITE 8
#define FP_NAN 16
#define MATH_ERRNO 1
#define MATH_ERREXCEPT 2
#define math_errhandling MATH_ERREXCEPT

float fabsf(float arg);
double fabs(double arg);
long double fabsl(long double arg);
float fmodf(float x, float y);
double fmod(double x, double y);
long double fmodl(long double x, long double y);
float remainderf(float x, float y);
double remainder(double x, double y);
long double remainderl(long double x, long double y);
float remquof(float x, float y, int *quo);
double remquo(double x, double y, int *quo);
long double remquol(long double x, long double y, int *quo);
float fmaf(float x, float y, float z);
double fma(double x, double y, double z);
long double fmal(long double x, long double y, long double z);
float fmaxf(float x, float y);
double fmax(double x, double y);
long double fmaxl(long double x, long double y);
float fminf(float x, float y);
double fmin(double x, double y);
long double fminl(long double x, long double y);
float fdimf(float x, float y);
double fdim(double x, double y);
long double fdiml(long double x, long double y);
float truncf(float arg);
double trunc(double arg);
double trunl(double arg);

#endif