#include "header.h"

int main(){
    // char date[] = "21 june 2021";
    // int day, year;
    // char month[9];

    // sscanf( date, "%i %s %i", &day, month, &year);
    // printf("The day is %i , the month is %s, the year is %i ", day, month, year);

     char stdout[100];
    // char string[]="STRING";
    char stdout2[100];
    // s21_sprintf(stdout, "o%s hello%djjjj\n", string, 0);
    
    // printf("s21: %s", stdout);
     printf("ori: %s", stdout2);

    char str[80], sstr[80];
    char str21[]="HEYHEYHEY";//ставим сюда значение массива оно отрабатывает нормально, указываем просто размер и оно пишет не то, с размером работает 6 работает 7 не работает а на убунте работает не взирая на это
    
    int y,z, i=5;
    y=5;
    int ii, zz, zz1;
    
    //sscanf("777 test 1111 2 3 4 5", "%s%d%d", str, &i, &ii);
    sscanf("777  1111 2 3 4 5", "%+s%d%d%d", str, &i, &ii, &zz);
    //s21sscanf("777  test  1111 2 3 4 5", "%s%d%d", str21, &y, &z);
    s21sscanf("777   1111 2 3 4 5", "%s%d%d%d", str21, &y, &z, &zz1);
    //             source                           va_list arg
    //s21sscanf("hello 1111 2 3 4 5", "%d",&y);
     //s21sscanf("hello 1111 2 3 4 5", "%+d%s", &y, str21);
    printf("\nmain printf string:%s %d %d %d\n", str21, y, z, zz1);
   
    
    
    printf("orig: %s %d %d %d\n", str, i, ii, zz);
    // printf("s21 : %s %d\n", str21, y);
    return 0;
}


