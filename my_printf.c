#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

char *convert_to_base(long long numbers, char *base_characters, int base);
int print_characters(const char  *text);
int print_number_with_sign(int number);
int print_unsigned_number(unsigned int number);

char *convert_to_base(long long number, char *base_characters, int base) {
    int result_length = 0;
    long long num_copy = number;

    while (num_copy > 0) {
        result_length++;
        num_copy /= base;
    }

    char *result = (char *)malloc(sizeof(char) * (result_length + 1));
    result[result_length] = '\0';

    while (number > 0) {
        result_length--;
        result[result_length] = base_characters[number % base];
        number /= base;
    }

    return result;
}

int print_characters(const char *text) {
    int character_count = 0;

    for (int index = 0; text[index] != '\0'; index++) {
        putchar(text[index]);
        character_count++;
    }

    return character_count;
}

int print_number_with_sign(int number) {
    int printed_characters = 0;

    if (number == 0) {
        putchar('0');
        printed_characters++;
        return printed_characters;
    }

    number = (number < 0) ? (putchar('-'), printed_characters++, -number) : number;

    int divisor = 1;

    while (number / divisor >= 10) {
        divisor *= 10;
    }

    for (; divisor > 0; divisor /= 10) {
        int digit = number / divisor;
        putchar(digit + '0');
        printed_characters++;
        number %= divisor;
    }

    return printed_characters;
}

int print_unsigned_number(unsigned int number) {
    if (number == 0) {
        putchar('0');
        return 1;
    }

    int digit_count = 0;

    unsigned int temp = number;
    while (temp > 0) {
        temp /= 10;
        digit_count++;
    }

    char digit_buffer[20];

    for (int i = digit_count - 1; i >= 0; i--) {
        digit_buffer[i] = (number % 10) + '0';
        number /= 10;
    }

    for (int j = 0; j < digit_count; j++) {
        putchar(digit_buffer[j]);
    }

    return digit_count;
}

int print_number(int num) {
    return print_number_with_sign(num);
}

int print_octal(long long num) {
    char *base = "01234567";
    char *oct = convert_to_base(num, base, 8);
    return print_characters(oct);
}

int print_unsigned(unsigned int num) {
    return print_unsigned_number(num);
}

int print_char(int ch) {
    putchar(ch);
    return 1;
}

int print_string(const char *str) {
    if (str == NULL) {
        str = "(null)";
    }
    return print_characters(str);
}

int print_pointer(void *ptr) {
    int count = 0;
    count += print_characters("0x");
    count += print_characters(convert_to_base((long long)ptr, "0123456789abcdef", 16));
    return count;
}

int my_printf(const char *format, ...) {
    int printed_characters = 0;
    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format != '%') {
            putchar(*format);
            printed_characters++;
        } else {
            format++;
            switch (*format) {
                case 'd':
                case 'i':
                    printed_characters += print_number(va_arg(args, int));
                    break;
                case 'o':
                    printed_characters += print_octal(va_arg(args, long long));
                    break;
                case 'u':
                    printed_characters += print_unsigned(va_arg(args, unsigned int));
                    break;
                case 'c':
                    printed_characters += print_char(va_arg(args, int));
                    break;
                case 's':
                    printed_characters += print_string(va_arg(args, char *));
                    break;
                case 'p':
                    printed_characters += print_pointer(va_arg(args, void *));
                    break;
                case 'x':
                    printed_characters += print_characters(convert_to_base(va_arg(args, int), "0123456789ABCDEF", 16));
                    break;
                default:
                    putchar('%');
                    putchar(*format);
                    printed_characters += 2;
                    break;
            }
        }
        format++;
    }

    va_end(args);
    return printed_characters;
}
