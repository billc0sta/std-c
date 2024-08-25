#include <stdio.h>

int main() {
	double vl = -12412.3232; 
	unsigned int sgn, exp;
	unsigned long mts;
	printf("double: %f, truncated: %f", vl, trunc(vl));
	return 0;
}