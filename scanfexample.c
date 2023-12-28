#include <stdio.h>
 
int main(void)
{
    char buff[50] = "F, 69, 123.45";
    char c;
    int n;
    double d;
    sscanf(buff, "%c, %d, %lf", &c, &n, &d);
    printf("Values: %c, %d, %.2lf\n", c, n, d);
    return 0;
}