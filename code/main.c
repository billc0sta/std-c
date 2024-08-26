#include "include/math.h"
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

int main() {
	union {unsigned u; float f;} prt = {.u = 0};
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
	assert(isless(2.f, 10.f));
	assert(!isless(10.f, 10.f));
	assert(!isless(11.f, 10.f));
	assert(!isgreaterequal(2.f, 1.f));
	assert(islessequal(10.f, 10.f));
	assert(islessequal(2.f, 10.f));
	assert(!islessequal(10.f, 2.f));
	assert(islessgreater(10.f, 11.f));
	assert(islessgreater(11.f, 10.f));
	assert(!islessgreater(10.f, 10.f));
	assert(isunordered(NAN, 1.f));
	assert(isunordered(1.f, NAN));
	assert(isunordered(1.f, 1.f));
}