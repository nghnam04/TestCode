#include<stdio.h>
int main() {
	float x1=4, x2 = 128.5;
	char i;
    float *p=&x1;
    float *q=&x2;
	for(i=0;i<4;i++)
	   printf("%5d   %5d \n",*(p+i),*(q+i));
	return 0;
}