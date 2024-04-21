#include<stdio.h>
int main(){
    short x=32767;
    short y=5;
    short sum=x+y;
    printf("sum = %d\n", sum);
    unsigned short sum1 =x+y;
    printf("sum1 = %d\n", sum1);
    return 0;
}