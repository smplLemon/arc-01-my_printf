# Custom `my_printf` Function

## Overview
This is a custom implementation of the classic `printf` function found in the C standard library. The `my_printf` function is designed to provide formatted output to the console, interpreting various format specifiers to display different types of data.

## Usage
The function supports a variety of format specifiers:

- `%d`: Signed decimal integer
- `%o`: Unsigned octal
- `%u`: Unsigned decimal integer
- `%x`: Unsigned hexadecimal integer (lowercase)
- `%c`: Single character
- `%s`: String of characters
- `%p`: Pointer address

By default, the function will interpret and print data according to the format specifiers provided in the input string.

Example usage:

```c
my_printf("String: %s, Decimal: %d, Pointer: %p\n", "Hello, World!", 123, &variable);
```

## Functionality
The `my_printf` function begins by parsing the format string supplied by the user. It then reads the corresponding arguments and prints them to the standard output according to the format specifiers encountered.

## Compilation
To compile a program using the my_printf function, include the source file my_printf.c and header file my_printf.h in your project, and compile them along with your main program file.

Or you can just use `make` :-)

## License
This project is open-source and available for free. Not licensed.