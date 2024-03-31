#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
int my_putchard (char c) {
    write(1, &c, 1);
    return (1);
}

int my_printd (int nbr) {
    int len = 0;
    if (nbr < 0) {
        len += my_putchard('-');
        nbr *= -1;
    }
    if (nbr > 9)
        len += my_printd(nbr / 10);
    return (len + my_putchard(nbr % 10 + '0'));
}

int printfab (unsigned int nbr) {
    int len = 0;
    if (nbr > 9)
        len += printfab(nbr / 10);
    return (len + my_putchard(nbr % 10 + '0'));
}

int printfx (unsigned int nbr) {
    int len = 0;
    if (nbr > 7)
        len += printfx(nbr / 8);
    return (len + my_putchard(nbr % 8 + '0'));
}

int printx (unsigned long int nbr) {

    int len = 0;
    if (nbr > 15)
        len += printx(nbr / 16);
    if (nbr%16 > 9 && nbr%16 < 16)
        return (len + my_putchard(nbr%16-10 + 'A'));
    else
        return (len + my_putchard(nbr % 16  + '0'));
}




int my_putstra(char *s) {
    int len = 0;
    while (*s)
        len += my_putchard(*s++);
    return len;
}





int my_printf(char* format, ...) {

    va_list ap;
    char *s, c;
    int d;
    unsigned int u;
    intptr_t x;
    int len = 0;

    va_start(ap, format);

    while (*format) {
        if (*format == '%') {
            switch (*++format) {
                case 's':
                    s = va_arg(ap, char *);
                    if(!s || !*s) {
                        len += my_putstra("(null)");
                        len += 6;
                    }
                    else
                    len += my_putstra(s);
                    break;

                case 'd':
                    d = va_arg(ap, int);
                    len += my_printd(d);
                    break;

                case 'c':
                    c = va_arg(ap, int);
                    len += my_putchard(c);
                    break;

                case 'u':
                    u = va_arg(ap, unsigned int);
                    len += printfab(u);
                    break;

                case 'o':
                    u = va_arg(ap, unsigned int);
                    len += printfx(u);
                    break;

                case 'x':
                    x = va_arg(ap, intptr_t);
                    len += printx(x);
                    break;

                case 'p':
                    x = va_arg(ap, intptr_t);
                    len += my_putstra("0x") + printx(x);
                    break;

                default:
                    len += my_putchard('%');
            }
            format++;
        }
        if (*format != '%') {
            len += my_putchard(*format);
            format++;
        }
    }
    va_end(ap);

    return (len);
}