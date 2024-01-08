#include <stdio.h>
#include <stdlib.h>
int main(){
    int* matr;
    int counter=0;
    int input;
    matr=malloc(counter*sizeof(int));
    while(scanf("%d", &input)){
        if(input==-1)break;
        matr[counter]=input;
        
    counter++;
    int* temp = realloc(matr, counter*sizeof(int));
    
    
    matr=temp;
    }

    for(int i=0; i<counter; i++)
    printf("%d", matr[i]);
    
    
}