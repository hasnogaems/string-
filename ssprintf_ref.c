#include "header.h"
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define _OPEN_SYS_ITOA_EXT
int s21_sprintf(char *str, const char *format, ...){
    int move_str;
    
    va_list arg;
    va_start(arg, format);
    char* tmp=(char*)malloc(sizeof(char)*100);
    flags Flags;
    while(*format!='\0'){
        //printf("here?");

        if(*format=='%'){
           Flags=parser(&format, Flags); // создаем зануляем и заполняем структуру флаги, идем от процента
           tmp=concat_type(Flags, arg);//считываем флаги и пишем в строку
           
           strcat(str, tmp);
           move_str=strlen(tmp);
           format=format+Flags.move_format;
           //format++;format++;format++;format++;
           str=str+move_str;//str++;str++;
        }
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
void s21_reverse(char *str, int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}
//itoa from the net
// char* itoa(int num, char* buffer, int base)   
// {  
// int current = 0;  
// if (num == 0) {  
// buffer[current++] = '0';  
// buffer[current] = '\0';  
// return buffer;  
// }  
// int num_digits = 0;  
// if (num < 0) {  
// if (base == 10) {  
// num_digits ++;  
// buffer[current] = '-';  
// current ++;  
// num *= -1;  
// }  
// else  
// return NULL;  
// }  
// num_digits += (int)floor(log(num) / log(base)) + 1;  
// while (current < num_digits)   
// {  
// int base_val = (int) pow(base, num_digits-1-current);  
// int num_val = num / base_val;  
//  char value = num_val + '0';  
// buffer[current] = value;  
// current ++;  
// num -= base_val * num_val;  
// }  
// buffer[current] = '\0';  
// return buffer;  
// }  


int itoa(int num, char *str, int base) {
    int i = 0;
    int isNegative = 0;

    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return i;
    }

    if (num < 0 && base == 10) {
        isNegative = 1;
        num = -num;
    }

    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    if (isNegative) {
        str[i++] = '-';
    }

    str[i] = '\0';

    s21_reverse(str, i);

    return i;
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
    int i=va_arg(arg, int);
    char* x=malloc(sizeof(char)*100);
    //x=itoa(va_arg(arg, int), x, 10);
    itoa(i, x, 10);
return x;

}



char* write_string(flags Flags, va_list arg){
    char* s=malloc(sizeof(char)*100);
    s=va_arg(arg, char*);
return s;

}

flags    parser(const char **format, flags Flags){
        //flags Flags={0};
        //(*format)++;
        while(**format=='d'||**format=='s'||**format=='i'||**format=='e'||**format=='o'||**format=='E'||**format=='g'||**format=='G'||**format=='f'){
           printf("here?:parser163");
    //           case 'e':
    // case 'E':
    // case 'g':
    // case 'G':
    // case 'f':
        switch(**format){
            
        case 'd':
            Flags.integer=1;
            Flags.move_format=2;
            break;
        case 's':
            Flags.string=1;
            Flags.move_format=2;
            break;  
        case 'i':
            Flags.decimal_octal_hex=1;
            break;   
        case 'e':
        case 'E':
        case 'g':
        case 'G':
        case 'f':
            Flags.e=1;
            break; 
        case 'o':
            Flags.o=1;        
        default:
            break;  }
            
            (*format)++;
    }
    return Flags;


    }

    int convert_to_dec(int input, int base, int minus){
    int power=0;
    int dec=0;
    
    while(input>0){
    dec=dec+(input%10)*pow(base, power);
    input=input/10;
    power++;}
    return minus ? dec*-1.0:dec;
}

   float scientific_to_float(char* string){
    char pre_dot[1000000];
    float pre_dot_float;
    char post_dot[1000000]="000000";
    float post_dot_float;
    char exponent[1000000];
    int count=0;
    while(*string!='.'){
        pre_dot[count]=*(string);
        string++;
        count++;

    }
    pre_dot[count]='\0';
    count=0;
    string++;
    while(*string!='e'&&*string!='E'){
        post_dot[count]=*string;
        string++;count++;
    }
    post_dot[count]='\0';
    count=0;
    while(*string!='+'&&*string!='-'){
        *(string++);
    }

    while(*string!=' '){
        exponent[count]=*(string);
        count++;string++;
    }
    exponent[count]='\0';
 int i=0; //количество знаков, заводим для знака после точки
 pre_dot_float=(float)char_to_dec(&i, pre_dot);
 i=0;
 post_dot_float=(float)char_to_dec(&i, post_dot);
 while(i>0){
    post_dot_float /=10;
    i--;

 }
 float return_this=pre_dot_float+post_dot_float;
 return_this=exponent_f(exponent, return_this);


    

    printf("\n\n post_dot_float=%f", pre_dot_float);
    printf("\n\n post_dot_float=%f", post_dot_float);
    printf("\n\npredot=%s\n\n", pre_dot);
    printf("\n\npostdot=%s\n\n", post_dot);
    printf("\n\nexponent=%s\n\n", exponent);
    return return_this;

   }

  long double char_to_dec(int* i, char str[]){
    long double result = 0.0;
    while(*str>=48&&*str<=57) {//0 to 9
    (*i)++;
    result *= 10;
    result += *str-'0';
    str++;
      }
       return result;
  }

  long double exponent_f(char exp[], float pre_plus_post){
    int is_negative=0; 
    float return_this;
    if(*exp=='-'){
            is_negative=1; }  
            exp++;
    
if(!is_negative){
return_this=pre_plus_post*pow(10, (float)atoi(exp));

};
printf("\n\nEXPONENTED=%f\n\n", return_this);
return return_this;
  }

 long long int hex_to_dex(char str[], int base, flagscanf *param, int minus) {
  long long int result = 0x0;
 // param->failed = 1;
  char *start_str = str;
  long long int sign = minus ? -1.0:1;
  
    //  base = 16;
  
  


    
  

  while (((*str >= 48 && *str <= 57) || (*str >= 65 && *str <= 70) ||
          (*str >= 97 && *str <= 102)) ) {
    if (*str >= 48 && *str <= 55) {
      result = (*str - '0') + result * base;
      str++;
      
    } else if ((*str >= 56 && *str <= 57) && (base != 8)) {
      result = (*str - '0') + result * base;
      str++;
     
    } else if ((*str >= 65 && *str <= 70) && (base != 8) && (base != 10)) {
      result = (*str - 55) + result * base;
      str++;
      
    } else if ((*str >= 97 && *str <= 102) && (base != 8) && (base != 10)) {
      result = (*str - 87) + result * base;
      str++;
     
    }
   // param->failed = 0;
  }
//   if (param->failed == 1) *str = *start_str;
  return result * sign;
} 

 

 long int set_sign(char **str, flagscanf *param) {
  long int sign = 1;
  if (**str == '+') {
    (*str)++;
  } else if (**str == '-') {
    sign = -1.0;
    (*str)++;
    
  }
  return sign;
}

  
   

       


