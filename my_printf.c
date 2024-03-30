#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <inttypes.h>

int my_puts(const char *str) {
    int count = 0;
    if (str == NULL) {
        str = "(null)";
    }
    while (*str) {
        if (write(STDOUT_FILENO, str, 1) < 0) {
            return -1;
        }
        count++;
        str++;
    }
    return count;
}
char *convert_unsigned_int_to_string(unsigned int justNum) {
    char *resultstr = NULL;
    int num_chars = snprintf(NULL, 0, "%u", justNum);
    if (num_chars >= 0) {
        resultstr = malloc((num_chars + 1) * sizeof(char));
        if (resultstr != NULL) {
            sprintf(resultstr, "%u", justNum);
        }
    }
    return resultstr;
}
int my_puti(int num, int base) {
    static const char digits[] = "0123456789abcdef";
    char buffer[32];
    int count = 0;
    int is_negative = 0;

    if (num == 0) {
        return my_puts("0");
    }

    if (num < 0 && base == 10) {
        is_negative = 1;
        num *= -1;
    }

    int i = 0;
    while (num > 0) {
        buffer[i++] = digits[num % base];
        num /= base;
    }

    if (is_negative) {
        buffer[i++] = '-';
    }

    for (int j = i - 1; j >= 0; j--) {
        if (write(STDOUT_FILENO, &buffer[j], 1) < 0) {
            return -1;
        }
        count++;
    }

    return count;
}
int my_printf(const char *restrict format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;
    char *str_arg;
    int int_arg;
    void *ptr_arg;

    while (*format) {
        if (*format == '%') {
            format++;

            switch (*format) {
                case 's':
                    str_arg = va_arg(args, char*);
                    count += my_puts(str_arg);
                    break;
                case 'd':
                    int_arg = va_arg(args, int);
                    count += my_puti(int_arg, 10);
                    break;
                case 'o':
                    int_arg = va_arg(args, int);
                    count += my_puti(int_arg, 8);
                    break;
                case 'u':
                    int_arg = va_arg(args, int);
                    count += my_puti(int_arg, 10);
                    break;
                case 'x':
                    int_arg = va_arg(args, int);
                    count += my_puti(int_arg, 16);
                    break;
                case 'c':
                    int_arg = va_arg(args, int);
                    count += write(STDOUT_FILENO, &int_arg, 1);
                    break;
                case 'p':
                    ptr_arg = va_arg(args, void*);
                    count += my_puts("0x");
                    count += my_puti((uintptr_t)ptr_arg, 16);
                    break;
                case 'X':
                    int_arg = va_arg(args, int);
                    count += my_puti(int_arg, 16);
                    break;
                default:
                    count += write(STDOUT_FILENO, format, 1);
                    break;
            }
        } else {
            count += write(STDOUT_FILENO, format, 1);
        }

        format++;
    }

    va_end(args);

    return count;
}
int main() {
    int num = 123;
    void* ptr = (void*)(uintptr_t)num;

  my_printf("\t-p-\t\n");

  my_printf("Address: %p\n", ptr);

  printf("Address: %p\n", ptr);

  my_printf("\t-s-\t\n");

  my_printf("Hello, %s!\n", "world");

  printf("Hello, %s!\n", "world");

  my_printf("\t-d-\t\n");

  my_printf("The answer is %d.\n", 991);

  printf("The answer is %d.\n", 991);

  my_printf("\t-o-\t\n");

  my_printf("Octal value: %o\n", 991);

  printf("Octal value: %o\n", 991);

  my_printf("\t-u-\t\n");

  my_printf("Unsigned decimal: %u\n", 991);

  printf("Unsigned decimal: %u\n", 991);

  my_printf("\t-x-\t\n");

  my_printf("Hexadecimal: %x\n", 991);

  printf("Hexadecimal: %x\n", 991);

  my_printf("\t-c-\t\n");

  my_printf("Character: %c\n", 'A');

  printf("Character: %c\n", 'A');

}

