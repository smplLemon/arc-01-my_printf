#include <stdarg.h>
#include <unistd.h>

int my_putchar(char c) {
    write(1, &c, 1);
    return 1;
}

int my_putstr(char *str) {
    int count = 0;
    while (*str) {
        count += my_putchar(*str++);
    }
    return count;
}

int my_putnbr(int n) {
    int count = 0;
    if (n < 0) {
        count += my_putchar('-');
        n = -n;
    }
    if (n >= 10) {
        count += my_putnbr(n / 10);
    }
    count += my_putchar((n % 10) + '0');
    return count;
}

int my_putoct(int n) {
    int count = 0;
    if (n >= 8) {
        count += my_putoct(n / 8);
    }
    count += my_putchar((n % 8) + '0');
    return count;
}

int my_putuint(unsigned int n) {
    int count = 0;
    if (n >= 10) {
        count += my_putuint(n / 10);
    }
    count += my_putchar((n % 10) + '0');
    return count;
}

int my_puthex(unsigned int n) {
    int count = 0;
    if (n >= 16) {
        count += my_puthex(n / 16);
    }
    char hex_digit = (n % 16) < 10 ? '0' + (n % 16) : 'a' + (n % 16) - 10;
    count += my_putchar(hex_digit);
    return count;
}

int my_putptr(void *p) {
    int count = my_putstr("0x");
    count += my_puthex((uintptr_t)p);
    return count;
}

int my_printf(char * restrict format, ...) {
    va_list args;
    va_start(args, format);

    char *s;
    int d, count = 0;
    unsigned int u;
    void *p;

    for (char *traverse = format; *traverse != '\0'; traverse++) {
        if (*traverse == '%') {
            traverse++;
            switch(*traverse) {
                case 'd':
                    d = va_arg(args, int);
                    count += my_putnbr(d);
                    break;
                case 'o':
                    d = va_arg(args, int);
                    count += my_putoct(d);
                    break;
                case 'u':
                    u = va_arg(args, unsigned int);
                    count += my_putuint(u);
                    break;
                case 'x':
                    u = va_arg(args, unsigned int);
                    count += my_puthex(u);
                    break;
                case 'c':
                    d = va_arg(args, int);
                    count += my_putchar(d);
                    break;
                case 's':
                    s = va_arg(args, char*);
                    count += my_putstr(s);
                    break;
                case 'p':
                    p = va_arg(args, void*);
                    count += my_putptr(p);
                    break;
                default:
                    count += my_putchar('%');
                    count += my_putchar(*traverse);
                    break;
            }
        } else {
            count += my_putchar(*traverse);
        }
    }

    va_end(args);
    return count;
}