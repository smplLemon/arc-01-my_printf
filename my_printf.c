#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

int write_char(char c)
{
    return write(1, &c, 1);
}

int my_strlen(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int write_string(const char *str)
{
    return write(1, str, my_strlen(str));
}

int print_hex(long int number)
{

    int len = 0;
    if (number > 15)
        len += print_hex(number / 16);
    if (number % 16 < 10)
        return (len + write_char(number % 16 + '0'));
    else
        return (len + write_char(number % 16 + 'a' - 10));
}

char *convert_to_octal(int num)
{
    char *str = calloc(sizeof(char), 11);
    char *res = calloc(sizeof(char), 11);
    int i = 0;
    while (num)
    {
        str[i++] = (num % 8) + 48;
        num /= 8;
    }
    if (i == 0) 
        str[i++] = '0';
    i = 0;
    for (int j = my_strlen(str) - 1; j >= 0; j--)
    {
        res[i++] = str[j];
    }
    free(str); 
    return res;
}

char *convert_to_string(int num)
{
    char *string = calloc(sizeof(char), 11);
    char *reverse;
    int i = 0;
    if (num < 0)
    {
        num *= -1;
        while (num)
        {
            string[i++] = num % 10 + '0';
            num /= 10;
        }
        string[i++] = '-';
    }
    else
    {
        while (num)
        {
            string[i++] = num % 10 + '0';
            num /= 10;
        }
    }
    if (i == 0) 
        string[i++] = '0';
    string[i] = '\0';
    reverse = malloc(my_strlen(string) + 1);
    for (int j = my_strlen(string) - 1, k = 0; j >= 0; j--, k++)
    {
        reverse[k] = string[j];
    }
    reverse[my_strlen(string)] = '\0';
    free(string); 
    return reverse;
}

char* my_reverse(char* str)
{

    char* arr = calloc(sizeof(char), my_strlen(str) + 1);
    int j = 0;
    for (int i = my_strlen(str) - 1; i >= 0; i--)
    {
        arr[j] = str[i];
        j++;
    }
    
    return arr;
}

char* unsigned_str(int num)
{

    long int u = 0;
    if (num < 0)
    {
        u = 4294967296 + num;
    } else{
        u = num;
    }
    char* str = (char*)calloc(sizeof(char), 22);
    int i = 0;
    while( u > 0){

        str[i++] = u % 10 + 48;
        u /= 10;
    }
    return my_reverse(str);
}

int my_printf(char *str, ...)
{
    int num;
    long int x;
    char c;
    int size = 0;
    char *string;
    va_list list;
    va_start(list, str);

    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '%')
        {
            i++;
            switch (str[i])
            {
            case 'c':
                c = va_arg(list, int);
                size += write_char(c);
                break;

            case 's':
                string = va_arg(list, char *);
                if (string == NULL)
                {
                    string = "(null)";
                }
                size += write_string(string);
                break;

            case 'd':
                num = va_arg(list, int);
                string = convert_to_string(num);
                size += write_string(string);
                free(string);
                break;

            case 'u':
                num = va_arg(list, int);
                string = unsigned_str(num);
                size += write_string(string);
                free(string); 
                break;

            case 'o':
                num = va_arg(list, int);
                string = convert_to_octal(num);
                size += write_string(string);
                free(string); 
                break;

            case 'x':
                x = va_arg(list, intptr_t);
                size += print_hex(x);
                break;

            case 'p':
                x = va_arg(list, intptr_t);
                write_string("0x");
                size += print_hex(x);
                break;
            }
        }
        else
        {
            size += write_char(str[i]);
        }
    }

    va_end(list);
    return size;
}

int main(void)
{
    my_printf("Hello %s\n", "World");
    printf("Hello %s\n", "World");
    printf("---------------------\n");
    
    my_printf("character is %c\n", 'C');
    printf("character is %c\n", 'C');
    printf("---------------------\n");

    my_printf("number is %d\n", 42);
    printf("number is %d\n", 42);
    printf("---------------------\n");

    my_printf("pointer is %p\n", (void *)1234);
    printf("pointer is %p\n", (void *)1234);
    printf("---------------------\n");

    my_printf("hex is Ox%x\n", 255);
    printf("hex is Ox%x\n", 255);
    printf("---------------------\n");

    my_printf("unsigned is %u\n", -128); 
    printf("unsigned is %u\n", -128);
    printf("---------------------\n");

    my_printf("octal is %o\n", 61);
    printf("octal is %o\n", 61);
    return 0;
}
