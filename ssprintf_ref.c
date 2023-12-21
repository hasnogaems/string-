#include "header.h"
#include <stdarg.h>
int s21_sprintf(char *str, const char *format, ...){
    
    va_list arg;
    va_start(arg, format);
    char* tmp;
    while(*format!='\0'){
        if(*format=='%'){
            parser(format); \\ создаем и зануляем структуру флаги, идем от процента
           tmp= type(my_struct, va_list);

            s21_strcat(str, tmp);
            

            if
        //     printf("");
       // flag.percent=1;}
        // }
        // else{
*str=*format;
format++;
str++;        
    }
    
     //в arg записывается указатель на первый аргумент из ...

int x=va_arg(arg, int); //возвращает значение arg(текущий variable argument)
int y=va_arg(arg, int); //при последующем вызове вернет следующий аргумент
char* s=va_arg(arg, char*);
// printf("x=%d", x);
// printf("y=%d", y);
// printf("s=%s", s);
   
    va_end(arg);
    
}
}

void parser_flags(format){
    while(*format==+||*format==-){
        switch(*format){
            
        case'+':
            struct.plus=1;
        case'-':
            struct.minus=1;  
        default:
            break;  }
            
            format++;
    }
    
   }

 char*  type(){
    char* x;
    if(my_struct.int==1){
       x= print_int(my_struct, va_list);
    }
    else if(my_struct.string==1){
        x=printf_string()
    }
    return x;
   }

char* printf_int(arg){
    char* x=(char*)va_arg(arg, int);
return x;

}

    flags parser(*format){
        flags My_flags={0};
        parser_flags(format, struct);
        while(((*format=='d')||(*format=='s'))&&(*format!=' ')){
        switch(*format){
            
        case'+':
            flags=1;
        case'-':
            struct.minus=1;  
        default:
            break;  }
            
            format++;
    }


    }

int main(){
    // char date[] = "21 june 2021";
    // int day, year;
    // char month[9];

    // sscanf( date, "%i %s %i", &day, month, &year);
    // printf("The day is %i , the month is %s, the year is %i ", day, month, year);

    char stdout[100];
    char s[]="string";
    s21_sprintf(stdout, "hello%d hello%d %s\n", 1, 2, s);
    
    printf("%s", stdout);


    }
