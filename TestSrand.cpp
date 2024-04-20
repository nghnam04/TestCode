#include <iostream>
#include <cstdlib>  // Thư viện chứa hàm rand()
#include <ctime>    // Thư viện chứa hàm time()

int main() {
    // Khởi tạo bộ sinh số ngẫu nhiên
    srand(time(0));  // seed random number generator based on current time

    // Tạo một số ngẫu nhiên
    int random_number = rand();

    // In số ngẫu nhiên ra màn hình
    std::cout << "Random Number: " << random_number << std::endl;

    // Tạo số ngẫu nhiên trong một khoảng cụ thể, ví dụ: từ 0 đến 99
    int bounded_random = rand() % 100;
    std::cout << "Bounded Random Number (0-99): " << bounded_random << std::endl;

    return 0;
}
