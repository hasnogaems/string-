#include "header.h"
#include <stdarg.h>
int s21sprintf(char *str, const char *format, ...){
    
    va_list ptr;
    va_start(ptr, format); //в ptr записывается указатель на первый аргумент из ...
   
    va_end(ptr);
    
}
