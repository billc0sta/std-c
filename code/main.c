#include "include/math.h"
#include <assert.h>
#include <stdio.h>

int main() {
	union {unsigned u; float f;} prt = {.u = 1};
	assert(isnan(NAN));
	assert(!isnan(12.f));
	assert(!isfinite(INFINITY));
	assert(!isfinite(NAN));
	assert(isfinite(12.f));
	assert(isinf(INFINITY));
	assert(!isinf(NAN));
	assert(!isinf(12.f));
	assert(!isnormal(prt.f));
	assert(isnormal(1.f));
	assert(!signbit(1.f));
	assert(signbit(-1.f));
	assert(isgreater(10.f, 2.f));
	assert(!isgreater(10.f, 10.f));
	assert(!isgreater(10.f, 11.f));
	assert(isgreaterequal(10.f, 10.f));
	assert(isgreaterequal(10.f, 2.f));
	assert(!isgreaterequal(1.f, 2.f));  
	assert(isless(2.f, 10.f));
	assert(!isless(10.f, 10.f));
	assert(!isless(11.f, 10.f));
	assert(islessequal(10.f, 10.f));
	assert(islessequal(2.f, 10.f));
	assert(!islessequal(10.f, 2.f));
	assert(islessgreater(10.f, 11.f));
	assert(islessgreater(11.f, 10.f));
	assert(!islessgreater(10.f, 10.f));
	assert(isunordered(NAN, 1.f));
	assert(isunordered(1.f, NAN));
	assert(!isunordered(1.f, 1.f));

	assert(fabsf(-1.32f) == 1.32f);
	assert(fabsf(1.32f) == 1.32f);
	assert(fabs(-1.32) == 1.32);
	assert(fabs(1.32) == 1.32);
	assert(fabsl(-1.32) == 1.32);
	assert(fabsl(1.32) == 1.32);
	assert(truncf(3.423f) == 3.f); 
	assert(truncf(313.423f) == 313.f); 
	assert(truncf(0) == 0); 
	assert(trunc(3.423) == 3.0);
	assert(trunc(3123.423) == 3123.0);
	assert(trunc(0) == 0);
	assert(trunc(3.423L) == 3.0L);
	assert(trunc(3123.423L) == 3123.0L);
	assert(trunc(0) == 0);

	double x = 543.0;
	double y = 312.0;
	printf("fmod(%f, %f): %f", x, y, fmod(x, y));
}