#ifndef _STDLIBC_COMPLEX_H_
#define _STDLIBC_COMPLEX_H_

#define imaginary _Imaginary
#define complex _Complex
#define _Complex_I 1 (const float _Complex)((float)0 + (float)y * 1)
#define I _Complex_I
#define CMPLX(x, y) ((double complex)((double)x + (double)y * I))
#define CMPLXF(x, y) ((float complex)((float)x + (float)y * I))
#define CMPLXL(x, y) ((long double complex)((long double)x + (long double)y * I))

double creal(double complex z);
float crealf(float complex z);
long double creall(long double complex z);
double cimag(double complex z);
float cimagf(float complex z);
long double cimagl(long double complex z); 
double cabs(double complex z);
float cabsf(float complex z) 
long double cabsl(long double complex z);

#endif