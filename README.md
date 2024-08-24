# std-c
my implementation of the C20 standard library

this library is highly unportable, as it only adheres to these specifications
- The NT kernel syscalls
- little-endian byte order
- IEEE 754 floating-point representation

## currently supports
- string.h
- ctype.h
- wctype.h
- wchar.h 
- fenv.h
- stdnoreturn.h

I intend to support all the available standard libraries as if C20.

__UNUSABLE: Still Under Development__
