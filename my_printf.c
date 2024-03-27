#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int my_putchar(char c) {
    return write(1, &c, 1);
}

int my_putstring(const char *str) {
    int i = 0;
    while (str[i]) {
        my_putchar(str[i]);
        i++;
    }
    return i;
}

int my_hexadecimal(unsigned int number) {
    int len = 0;
    char hex_digits[] = "0123456789abcdef";
    if (number < 16) {
        return my_putchar(hex_digits[number]);
    } else {
        len += my_hexadecimal(number / 16);
        return len + my_putchar(hex_digits[number % 16]);
    }
}

char *reverseString(const char *str) {
    int length = strlen(str);
    char *reversed = malloc(length + 1);
    if (reversed == NULL) {
        return NULL;
    }
    for (int i = 0; i < length; i++) {
        reversed[i] = str[length - i - 1];
    }
    reversed[length] = '\0';
    return reversed;
}

char *toOctalNumber(int num) {
    char *res = malloc(20);
    int i = 0;
    do {
        res[i++] = num % 8 + '0';
        num /= 8;
    } while (num > 0);
    char *octal_number = reverseString(res);
    free(res);
    return octal_number;
}

char *createStringRepresentation(int num) {
    if (num == 0) {
        char *zero = malloc(2);
        zero[0] = '0';
        zero[1] = '\0';
        return zero;
    }
    char *string = malloc(20);
    int i = 0;

    if (num < 0) {
        num *= -1;
        while (num) {
            string[i++] = num % 10 + '0';
            num /= 10;
        }
        string[i++] = '-';
    } else {
        while (num) {
            string[i++] = num % 10 + '0';
            num /= 10;
        }
    }
    return string;
}

char *toString(int num) {
    char *string = createStringRepresentation(num);
    char *reversed = reverseString(string);
    free(string);
    return reversed;
}

int my_printf(const char *str, ...) {
    va_list list;
    va_start(list, str);
    int size = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == '%') {
            i++;
            if (str[i] == 'c') {
                char c = va_arg(list, int);
                size += my_putchar(c);
            } else if (str[i] == 's') {
                char *string = va_arg(list, char*);
                if (string == NULL) {
                    string = "(null)";
                }
                size += my_putstring(string);
            } else if (str[i] == 'd') {
                int num = va_arg(list, int);
                char *string = toString(num);
                size += my_putstring(string);
                free(string);
            } else if (str[i] == 'o') {
                int num = va_arg(list, int);
                char *string = toOctalNumber(num);
                size += my_putstring(string);
                free(string);
            } else if (str[i] == 'u') {
                int num = va_arg(list, int);
                char *string = toString(num);
                size += my_putstring(string);
                free(string);
            } else if (str[i] == 'x') {
                unsigned int num = va_arg(list, unsigned int);
                size += my_hexadecimal(num);
            } else if (str[i] == 'p') {
                void *ptr = va_arg(list, void*);
                size += my_putstring("0x") + my_hexadecimal((intptr_t) ptr);
            }
        } else {
            size += my_putchar(str[i]);
        }
    }
    va_end(list);
    return size;
}

int main(void) {
    int size = my_printf("%s!\n", "HELLO WORLD");
    printf("%d\n", size);
    return 0;
}