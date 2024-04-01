# Task

Your code must be compiled with the flags -Wall -Wextra -Werror.
Hint(s)
• man printf

• man 3 stdarg

• Watch out for memory leaks !

• You can test your code against memory errors by compiling with the debugging flags -g3 -fsanitize=address

• Global variables are strictly FORBIDDEN

• Static variables are strictly FORBIDDEN

Authorized function(s)
• write(2)
• malloc
• free
• va_start, va_arg, va_copy, va_end (see man 3 stdarg)
(Obvious) Unauthorized functions
printf and co. (fprintf, sprintf, snprintf, asprintf, dprintf, vprintf, vfprintf, vsprintf, vsnprintf, vasprintf, vdprintf)
Multiline macros are forbidden
Include another .c is forbidden
Macros with logic (while/if/variables/...) are forbidden

# Description

The my_printf() function produce output according to a format as described below. The my_printf() functions write output to stdout, the standard output stream;

This function writes the output under the control of a format string that specifies how subsequent arguments (or arguments accessed via the variable-length argument facilities of stdarg(3)) are converted for output.

The format string is composed of zero or more directives: ordinary characters (not PERCENT), which are copied unchanged to the output stream; and conversion specifications, each of which results in fetching zero or more subsequent arguments.

Each conversion specification is introduced by the PERCENT character. The arguments must correspond properly (after type promotion) with the conversion specifier. After the PERCENT, the following appear in sequence:

doux The int (or appropriate variant) argument is converted to signed decimal (d). unsigned octal (o), unsigned decimal (u), unsigned hexadecimal (x).
c The int argument is converted to an unsigned char, and the resulting character is written.
s The char * argument is expected to be a pointer to an array of character type (pointer to a string). Characters from the array are written up to (but not including) a terminating NUL character.
p The void * pointer argument is printed in hexadecimal.

# Installation
Make


# Usage
gcc my_printf.c

