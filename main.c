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
     //printf("ori: %s", stdout2);

    char str[80]="HEEHEEHEE";
    char str21[]="HEYHEYHEY";//ставим сюда значение массива оно отрабатывает нормально, указываем просто размер и оно пишет не то, с размером работает 6 работает 7 не работает а на убунте работает не взирая на это
    
    float y=44,z=55;
  int i=555, d;
    void* ptr;
    void* ptr21;
    char pointer_array[300];
   long  ii=555, zz=77, zz1=88;
    char input[]="HELL10000";
    int count_scanf, count_s21_scanf;
    sprintf(pointer_array, "%p", &ptr21);
    //sscanf("777 test 1111 2 3 4 5", "%s%d%d", str, &i, &ii);
    count_scanf=sscanf("45450.01976582", "%4d", &d);
    // 4
    // if(strncmp(source, format, 4)source +=4;    //s21sscanf("777  test  1111 2 3 4 5", "%s%d%d", str21, &y, &z);
   count_s21_scanf=s21sscanf("45450.01976582", "%4d", &i);
    //             source                           va_list arg
    //s21sscanf("hello 1111 2 3 4 5", "%d",&y);
     //s21sscanf("hello 1111 2 3 4 5", "%+d%s", &y, str21);
    printf("\nmain printf string:%d %s\ns21 count=%d\n",i, input, count_s21_scanf );
    printf("orig: %d %s\norig count=%d\n",  d, str, count_scanf);
    
    // printf("s21 : %s %d\n", str21, y);
    return 0;
}


