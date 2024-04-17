#include<iostream>
#define PI 3.14159
#define MIN(a, b) ((a) < (b) ? (a) : (b))
//Macro là một đoạn mã được định nghĩa trong tiền xử lý
int main() {
    double radius = 5.0;
    double area = PI * radius * radius;
    int minimum = MIN(10, 20);
    std::cout << minimum;
    return 0;
}
