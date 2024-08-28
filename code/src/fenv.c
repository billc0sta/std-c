#include "../include/fenv.h"

fenv_t __pubfenv { .__exceptions = 0, .__rounding = FE_DOWNWARD, .__hold = 0 };
fexcept_t __prev_exceptions;
int __round; 

int feclearexcept(int excepts) {
	excepts = ~excepts;
	__pubfenv.__exceptions &= excepts;
	return 0; 
}

int fetestexcept(int excepts) {
	return (excepts & __pubfenv.__exceptions) == excepts; 
}

int feraiseexcept(int excepts) {
	__pubfenv.__exceptions |= excepts;
	return 0;
}

int fegetexceptflag(fexcept_t* flagp, int excepts) {
	if (!flagp) return 1;
	*flagp = __pubfenv.__exceptions & excepts;
	return 0; 
}

int fesetexceptflag(const fexcept_t* flagp, int excepts) {
	if (!flagp) return 1;
	__pubfenv.__exceptions |= *flagp & excepts;
	return 0; 
}

int fegetenv(fenv_t* envp) {
	if (!envp) return 1;
	*envp = __pubfenv;
	return 0;
}

int fesetenv(const fenv_t* envp) {
	if (!envp) return 1;
	__pubfenv = *envp;
	return 0;
}

int feholdexcept(fenv_t* envp) {
	if (!envp || __pubfenv.__hold) return 1;
	__prev_exceptions      = __pubfenv.__exceptions;
	__pubfenv.__hold       = 1;
	__pubfenv.__exceptions = 0;
	*envp = __pubfenv; 
	return 0; 
}

int feupdateenv(const fenv_t* envp) {
	if (!envp || !__pubfenv.__hold) return 1;
	__pubfenv              = *envp;
	__pubfenv.__hold       = 0;
	__pubfenv.__exceptions |= __prev_exceptions;
	return 0; 
}

int fesetround(int round) {
	if (round < FE_DOWNWARD || round > FE_UPWARD)
		return -1;
	__round = round; 
}

int fegetround(int round) {
	return __round; 
}