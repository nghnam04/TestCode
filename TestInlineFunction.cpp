#include<iostream>
#include<cmath>
using namespace std;
/*
Test hàm nội tuyến (Inline Function)
Inline Function sẽ chèn trực tiếp đoạnc code của hàm tại vị trí mà hàm đó được gọi
*/
inline double hypothenus(double a, double b){
    return sqrt(a*a+b*b);
}

int main(){
    double k=6, m=9;
    //2 dòng sau thực hiện như nhau
    cout << hypothenus(k, m) << endl;
    cout << sqrt(k*k+m*m) << endl;
    return 0;
}