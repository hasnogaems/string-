#include "header.h"
int main(){
    // char date[] = "21 june 2021";
    // int day, year;
    // char month[9];

    // sscanf( date, "%i %s %i", &day, month, &year);
    // printf("The day is %i , the month is %s, the year is %i ", day, month, year);

    char stdout[100];
    s21sprintf(stdout, "hello%d hello%d\n", 1, 2);
    s21sprintf(stdout, "hello2%d hello%d\n", 1, 2);
    printf("%s", stdout);


    }