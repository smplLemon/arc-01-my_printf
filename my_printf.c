#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#define TRUE  1
#define FALSE 0
typedef char bool;

int my_putchar(char c) {
  return write(1, &c, 1);
}

int my_putstr(char *str) {
  int index = 0;
  
  while (str[index] != '\0') {
    my_putchar(str[index]);
    index += 1;
  }
  return index;
}

int proceed_flag(va_list *arg, char flag) {
  int   sum = 0;
  char  c;
  char  *str;
//it needs some more arguments like %d,%o and %x
  if (flag == 's') {
    str = va_arg(*arg, char *);
    if (str) {
      sum += my_putstr(str);
    }
  }
  else if (flag == 'c') {
    c = va_arg(*arg, int);
    sum += my_putchar(c);    
  }
  //it will be better if there is argument like %p for pointer
  return sum;
}

int my_printf(char* format, ...) {
  va_list arg;
  int     index         = 0;
  bool    flag_spotted  = FALSE;
  int     sum           = 0;

  va_start(arg, format); 
  while (format[index] != 0)
  {
    if (flag_spotted) {
      sum += proceed_flag(&arg, format[index]);
      flag_spotted = FALSE;
    }
    else if (format[index] == '%') {
      flag_spotted = TRUE;
    }
    else {
      sum += my_putchar(format[index]);
    }
    //Want to increase the efficiency?
    index += 1;
  }
  va_end(arg);
  return sum;
}

int main() {
    my_printf("Hello, everybody");
    my_printf("Hello world! this is five: %d\n", 5);
    my_printf("%c\n", 'H');
    my_printf("%c%c%c%c%c!\n", 'H', 'e', 'l', 'l', 'o');
    my_printf("%d!\n", 1337);
    
}