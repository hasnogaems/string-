#include <stdio.h>
int dec_to_hex(int input){
    int pow=0;
    int dec=0;
    while(input>10){
    dec=dec+(input%10)*(16^pow);
    input=input/10;
    pow++;}
    printf("%d", dec);
}
int main(){
    dec_to_hex(112);
}