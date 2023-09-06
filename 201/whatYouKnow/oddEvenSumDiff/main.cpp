#include <iostream>

using std::cout, std::cin, std::endl; // need C++ or higher for this line, otherwise put each on separate line with semicolons at end

int main() {
    int num = 0;
    cin >> num;
    int cpy = num;
    int sum = 0;
    int rightDigit = 0;
    while (num > 0) {
        int leftDigit = num%10; // get remainder with modulus
        if (leftDigit%2 == 0) {
            sum += rightDigit;
        }
        else {
            sum -= rightDigit;
        }
        num /= 10;
        rightDigit = leftDigit;
    }
    sum += rightDigit;
    
    cout << "sum of Digits for " << cpy << " is " << sum << endl;
}