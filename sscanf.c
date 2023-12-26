#include "header.h"
#include <stdarg.h>
typedef struct sscanFlags{
    int d;
} sscanFlags;

int s21sscanf(const char *str, const char *format, ...){
va_list args;
int move_str;
va_start(args, format);
char tmp[100];
char* tmp_pointer=&tmp;
flagscanf Flagscanf;
while(*format!='\0'){
    printf("here?\n");
    if(*format=='%'){
        Flagscanf=scanfparser(format);
        tmp_pointer=scanf_concat_type(Flagscanf, args);
        strcat(str, tmp);
        move_str=strlen(tmp);

        
    }
    format++;


}
}

flagscanf scanfparser(const char *format){
        flagscanf sscan_Flags={{0}, NULL};
        format++;
        while(*format!=' '&&*format!='\0'){
           // printf("here?:");
        switch(*format){
            case'[':
                // logic parsing regular
                sscan_Flags.regular == NULL;
                break;
            default:
                sscan_Flags.base = parser(format); 
        }
    return sscan_Flags;


    }
       }
 
char* scanf_write_int(flagscanf Flags, va_list arg){
    int i=va_arg(arg, int);
    char x[100];
    //x=itoa(va_arg(arg, int), x, 10);
    itoa(i, x, 10);
return x;

}

char* scanf_write_string(flagscanf Flags, va_list arg){
    char s[100];
    char* point;
    s[0]=va_arg(arg, char*);
return s;

}

   char*  scanf_concat_type(flagscanf Flags, va_list arg){
    char* add_this;
    if(Flags.base.integer==1){
       add_this=scanf_write_int(Flags, arg);
    }
    else if(Flags.base.string==1){
        add_this=scanf_write_string(Flags, arg);
    }
    return add_this; //мы допишем это в str вместо %d
   }

