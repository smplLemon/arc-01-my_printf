# Custom printf Implementation

This C program demonstrates a custom implementation of the `printf` function. The `my_printf` function allows working with strings and format specifiers.

## Functions

- `my_putchar`: Used to print a character.
- `my_putstr`: Used to print a string.
- `proceed_flag`: Used to handle format specifiers.
- `my_printf`: Custom `printf` function.

## Format Specifiers

The following format specifiers are used in the `my_printf` function:

- `%s`: Used for printing strings.
- `%c`: Used for printing characters.
- `%d`: Used for printing integer numbers.

## Example

The following code prints strings and format specifiers:

```c
#include <stdio.h>

int main() {
  my_printf("Hello, everybody\n");
  my_printf("Hello world! this is five: %d\n", 5);
  my_printf("%c\n", 'H');
  my_printf("%c%c%c%c%c!\n", 'H', 'e', 'l', 'l', 'o');
  my_printf("%d!\n", 1337);

  return 0;
}
Hello, everybody
Hello world! this is five: 5
H
Hello!
1337!

gcc -o printf my_printf.c