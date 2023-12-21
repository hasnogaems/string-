#include "header.h"
int main(){
    // char date[] = "21 june 2021";
    // int day, year;
    // char month[9];

    // sscanf( date, "%i %s %i", &day, month, &year);
    // printf("The day is %i , the month is %s, the year is %i ", day, month, year);

    char stdout[100];
    s21_sprintf(stdout, "hello%d hello%d\n", 1, 2);
    s21_sprintf(stdout, "hello2%d hello%-d ghgftrdd\n", 1, 2);
    printf("%s", stdout);

    printf("%mmmm");


    }
//    void parser_flags(format){
//     while(*format==+||*format==-){
//         switch(*format){
            
//         case'+':
//             struct.plus=1;
//         case'-':
//             struct.minus=1;  
//         default:
//             break;  }
            
//             format++;
//     }
    
//    }

//  char*  type(){
//     char* x;
//     if(my_struct.int==1){
//        x= print_int(my_struct, va_list);
//     }
//     else if(my_struct.string==1){
//         x=printf_string()
//     }
//     return x;
//    }

// char* printf_int(arg){
//     char* x=(char*)va_arg(arg, int);
// return x;

// }

//     flags parser(*format){
//         flags My_flags={0};
//         parser_flags(format, struct);


//     }