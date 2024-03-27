# Task
The challenge lies in implementing the project logic.The challenge in this code  is to understand how to write a variadic function (my_printf) that mimics the behavior of the standard printf function in C. It involves parsing the format string and handling different format specifiers (%c, %s, %d, %o, %u, %x, %p) correctly, along with handling the variable arguments accordingly.

# Description
I set up a C project with necessary libraries (stdio.h, stdlib.h, string.h,stdarg.h,unistd.h).I created many  functions like my_putchar,my_putstring, my_hexadecimal,reverseString,toOctalNumber,createStringRepresentation,toString, my_printf.
my_putchar: Writes a single character to the standard output.
my_putstring: Writes a null-terminated string to the standard output.
my_hexadecimal: Converts an unsigned integer to its hexadecimal representation and writes it to the standard output.
reverseString: Reverses a null-terminated string and returns the reversed string.
toOctalNumber: Converts an integer to its octal representation and returns the octal string.
createStringRepresentation: Converts an integer to its string representation and returns the string.
toString: Converts an integer to its string representation and returns the reversed string.
The my_printf function uses a va_list to handle variable arguments and processes the format string str. It supports format specifiers such as %c for characters, %s for strings, %d for integers, %o for octal numbers, %u for unsigned integers, %x for hexadecimal numbers, and %p for pointers.
In the main function, an example usage of my_printf is demonstrated by printing "HELLO WORLD!" to the standard output and then printing the number of characters printed by my_printf.The my_printf function works similarly to the standard printf function in C, but it has been customized to support a subset of format specifiers and handle variable arguments.The my_printf function takes a format string (str) followed by a variable number of arguments using the ... syntax.The function iterates over each character in the format string. When it encounters a % character, it interprets the next character to determine the type of formatting to apply to the corresponding argument.If the specifier is %c, it retrieves the next argument as a character and uses my_putchar to print it.If the specifier is %d, %o, or %u, it retrieves the next argument as an integer, converts it to the corresponding base (decimal, octal, or unsigned decimal), and prints it using my_putstring.If the specifier is %x, it retrieves the next argument as an unsigned integer, converts it to hexadecimal, and prints it using my_hexadecimal.If the specifier is %p, it retrieves the next argument as a pointer, converts it to hexadecimal, and prints it using my_putstring and my_hexadecimal.

# Installation
git clone https://github.com/yourusername/my_printf.git cd my_printf gcc -o my_printf  my_printf.c
make

# Usage
First, include the declaration of your my_printf function in a header file (let's call it my_printf.h) Create a source file (let's call it my_printf.c) where you define the actual implementation of your my_printf function Compile your source files (my_printf.c and other necessary files) into an object file using a C compiler. gcc -c my_printf.c -o my_printf.o Write a test program that includes the my_printf header and links to the compiled object file Compile your test program and enter "make" to terminal Run the compiled program ./my_printf
