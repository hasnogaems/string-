#include <stdio.h>
int s21_strlen(char * str){
    int count=0;
    for(;*(str+count);count++);
    return count;
}