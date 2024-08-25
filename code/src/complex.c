#include <../include/complex.h>

double creal(double complex z) {
	return (double)z;
}

float crealf(float complex z) {
	return (float)z;
}

long double creall(long double complex z) {
	return (long double)z;
}

double cimag(double complex z) {
	return *((double*)&z + 1);
}

float cimagf(float complex z) {
	return *((float*)&z + 1);
}

long double cimagl(long double complex z) {
	return *((long double*)&z + 1);
}

double cabs(double complex z) {
	double rel = creal(z);
	double img = cimag(z);
	double cbsq = rel * rel + img * img;
	// -> TODO: requires sqrt()
	// return sqrt(cbsq);
}

float cabsf(float complex z) {
	float rel = creal(z);
	float img = cimag(z);
	float cbsq = rel * rel + img * img;
	// -> TODO: requires fsqrt()
	// return sqrtf(cbsq);
}

long double cabsl(long double complex z) {
	long double rel = creal(z);
	long double img = cimag(z);
	long double cbsq = rel * rel + img * img;
	// -> TODO: requires sqrtl()
	// return sqrtl(cbsq);
}

// -> TODO: Complete complex.h