#ifndef _STDLIBC_FENV_H_
#define _STDLIBC_FENV_H_

#define FE_DIVBYZERO  1
#define FE_INEXACT    2
#define FE_INVALID    4
#define FE_OVERFLOW   8
#define FE_UNDERFLOW  16
#define FE_ALL_EXCEPT FE_DIVBYZERO | FE_INEXACT | \
                      FE_INVALID | FE_OVERFLOW |  \
                      FE_UNDERFLOW
#define FE_DOWNWARD   1
#define FE_TONEAREST  2
#define FE_TOWARDZERO 3 
#define FE_UPWARD     4
typedef int fexcept_t;
typedef struct {
	fexcept_t __exceptions;
	int __rounding;
	int __hold;
} fenv_t;

extern fenv_t __pubfenv;
extern fexcept_t __prev_exceptions;

int feclearexcept(int excepts);
int fetestexcept(int excepts); 
int feraiseexcept(int excepts);
int fegetexceptflag(fexcept_t* flagp, int excepts);
int fesetexceptflag(const fexcept_t* flagp, int excepts);
int fegetenv(fenv_t* envp);
int fesetenv(const fenv_t* envp);
int feholdexcept(fenv_t* envp);
int feupdateenv(const fenv_t* envp);

#endif 