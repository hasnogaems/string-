#include "header.h"
#include <stdarg.h>
typedef struct sscanFlags{
    int d;
} sscanFlags;
int s21sscanf(const char *str, const char *format, ...){
va_list args;
va_start(args, format);
flagscanf Flagscanf;
while(*format!='\0'){
    printf("here?\n");
    if(*format=='%'){
        Flagscanf=scanfparser(format);
        
    }
}
format++;

}