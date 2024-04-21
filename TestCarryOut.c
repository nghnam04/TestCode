#include<stdio.h>
int main(){
    short x=32767;
    short y=5;
    short sum=x+y; //Kiểu short được biểu diễn bằng 15 bit nên có khoảng giá trị [-32768; 32767]
    printf("sum = %d\n", sum); //Trường hợp số nguyên có dấu
    unsigned short sum1 =x+y;
    printf("sum1 = %d\n", sum1); // Trường hợp số nguyên không dấu
    return 0;
}