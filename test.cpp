#include <iostream>
using namespace std;

bool isPalindrome(int number) {
    if (number < 0) {
        // Số âm không được coi là palindrome
        return false;
    }
    
    int reversed = 0, original = number, remainder;
    while (number != 0) {
        remainder = number % 10;
        reversed = reversed * 10 + remainder;
        number /= 10;
    }
    
    return original == reversed;
}

int main() {
    int testNumber;
    cout << "Enter a number to check if it is a palindrome: ";
    cin >> testNumber;
    
    if (isPalindrome(testNumber)) {
        cout << testNumber << " is a palindrome." << endl;
    } else {
        cout << testNumber << " is not a palindrome." << endl;
    }
    
    return 0;
}
