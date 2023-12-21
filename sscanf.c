#include <stdio.h>
#include <stdarg.h>
typedef unsigned long s21_size_t;

int sscanf21(const char *str, const char *format, ...){
va_list args;
va_start(args, format);
va_args


}

int main(){
    char date[] = "24 June 2021";
    int day, year;
    char month[9];

    sscanf( date, "%i %s %i", &day, month, &year);

    printf("The day is: %i", day );
    printf("The month is: %s", month);
    printf("The year is: %i", year);

}