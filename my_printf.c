#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#define TRUE  1
#define FALSE 0
typedef char bool;

int my_putchar(char c) 
{
  return write(1, &c, 1);
}

int my_putstr(char *str) {
  int index = 0;
  
  do {
    my_putchar(str[index]);
    index += 1;
  } while (str[index] != '\0');
  
  return index;
}

int proceed_flag(va_list *arg, char flag) 
{
  int   result = 0;
  char  c;
  char  *str;

  if (flag == 's') 
  {
    str = va_arg(*arg, char *);
    if (str) 
    {
      result += my_putstr(str);
    }
  }
  else if (flag == 'c') 
  {
    c = va_arg(*arg, int);
    result += my_putchar(c);    
  }

  return result ;
}

int my_printf(char* format, ...) {
  va_list arg;
  int index = 0;
  bool flag_spotted = FALSE;
  int result = 0;

  va_start(arg, format);
  do {
    if (flag_spotted) {
      result += proceed_flag(&arg, format[index]);
      flag_spotted = FALSE;
    } else if (format[index] == '%') {
      flag_spotted = TRUE;
    } else {
      result += my_putchar(format[index]);
    }

    index += 1;
  } while (format[index] != '\0');
  
  va_end(arg);
  return result;
}

int main() 
{
    my_printf("Hello, everybody");
    my_printf("Hello world! this is five: %d\n", 5);
    my_printf("%c\n", 'H');
    my_printf("%c%c%c%c%c!\n", 'H', 'e', 'l', 'l', 'o');
    my_printf("%d!\n", 1337);
}