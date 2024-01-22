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
    
    float y=44,z;
   int i=555;
    void* ptr;
    void* ptr21;
    char pointer_array[300];
    int ii=555, zz=77, zz1=88;
    char input[]="HELL10000";
    sprintf(pointer_array, "%p", &ptr21);
    //sscanf("777 test 1111 2 3 4 5", "%s%d%d", str, &i, &ii);
    sscanf("0x7fff2c40e104", "%p%s", &ptr, str);
    // 4
    // if(strncmp(source, format, 4)source +=4;    //s21sscanf("777  test  1111 2 3 4 5", "%s%d%d", str21, &y, &z);
   s21sscanf(pointer_array, "%p%s", &ptr21, str21);
    //             source                           va_list arg
    //s21sscanf("hello 1111 2 3 4 5", "%d",&y);
     //s21sscanf("hello 1111 2 3 4 5", "%+d%s", &y, str21);
    printf("\nmain printf string:%p %s\n",ptr21, str21 );
    printf("orig: %p %s\n",  ptr, str);
    // printf("s21 : %s %d\n", str21, y);
    return 0;
}


