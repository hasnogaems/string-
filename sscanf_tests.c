#include <stdio.h>
#include <string.h>
int main(){
    int num;
    sscanf("112", "%i", &num);
    printf("Parsed number: %d\n", num);
    sscanf("0112", "%i", &num);
    printf("Parsed number: %d\n", num);
    sscanf("0x112", "%i", &num);
    printf("Parsed number: %d\n", num);
    sscanf("00112", "%i", &num);
    printf("Parsed number: %d\n", num);
}