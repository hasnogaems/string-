#include "header.h"
#include <stdarg.h>
typedef struct sscanFlags{
    int d;
} sscanFlags;
int s21sscanf(const char *str, const char *format, ...){
va_list args;
va_start(args, format);
sscanFlags sscan_Flags;
while(*format!='\0'){
    if(*format=='%'){
        sscan_Flags=scanfparser(format);
    }
}


}