#include <stdio.h>
#include <string.h>

//Test hàm nối chuỗi strcat
int main() {
    char dest[20] = "Hello, ";
    char src[10] = "World!";
    
    strcat(dest, src);
    printf("Kết quả sau khi nối: %s\n", dest);
    return 0;
}
