# std-c
my implementation of the C20 standard library

this library is highly unportable, as it only adheres to these specifications
- The NT kernel syscalls
- little-endian byte order
- IEEE 754 floating-point representation
- 0x86 - 0x86_64 architectures

this library supports the following compilers
- MSVC Compiler
- GCC/G++ Compiler

## currently supports
- assert.h
- complex.h
- ctype.h
- fenv.h
- float.h
- math.h
- stddef.h
- stdlib.h
- stdint.h
- stdalign.h
- stdbool.h  
- stdnoreturn.h
- string.h
- wchar.h
- wctype.h

I intend to support all the available standard libraries as if C20.

__UNUSABLE: Still Under Development__
