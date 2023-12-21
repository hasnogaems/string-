#include "header.h"
#include <stdarg.h>
#include <string.h>
int s21_sprintf(char *str, const char *format, ...){
    
    va_list arg;
    va_start(arg, format);
    char* tmp;
    flags Flags;
    while(*format!='\0'){
        printf("here?");

        if(*format=='%'){
           Flags=parser(format); // создаем зануляем и заполняем структуру флаги, идем от процента
           tmp=concat_type(Flags, arg);
           strcat(str, tmp);}
           
            

          
*str=*format;
format++;
str++;        
    
    }
    
     //в arg записывается указатель на первый аргумент из ...

// int x=va_arg(arg, int); //возвращает значение arg(текущий variable argument)
// int y=va_arg(arg, int); //при последующем вызове вернет следующий аргумент
// char* s=va_arg(arg, char*);
// // printf("x=%d", x);
// // printf("y=%d", y);
// // printf("s=%s", s);
   
    va_end(arg);
    
}




 char*  concat_type(flags Flags, va_list arg){
    char* add_this;
    if(Flags.integer==1){
       add_this=write_int(Flags, arg);
    }
    else if(Flags.string==1){
        add_this=write_string(Flags, arg);
    }
    return add_this; //мы допишем это в str вместо %d
   }

char* write_int(flags Flags, va_list arg){
    char* x=(char*)va_arg(arg, int);
return x;

}

char* write_string(flags Flags, va_list arg){
    char* x=va_arg(arg, char*);
return x;

}

    flags parser(const char *format){
        flags Flags={0};
        format++;
        while(*format!=' '){
            printf("here?:");
        switch(*format){
            
        case'd':
            Flags.integer=1;
            break;
        case's':
            Flags.string=1;
            break;  
        default:
            break;  }
            
            format++;
    }
    return Flags;


    }


