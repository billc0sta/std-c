#include "../include/float.h"
#include "../include/fenv.h"

// unportable
int __flt_rounds() {
	return fegetround();
}
// 