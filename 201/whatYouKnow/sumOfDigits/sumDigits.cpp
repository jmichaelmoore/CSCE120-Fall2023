#include <iostream>

using std::cout, std::cin, std::endl; // need C++ or higher for this line, otherwise put each on separate line with semicolons at end

int main() {
    int num = 0;
    cin >> num;
    int cpy = num;
    int sum = 0;
    while (num > 0) {
        int digit = num%10; // get remainder with modulus
        sum += digit;
        num /= 10;
    }
    
    cout << "sum of Digits for " << cpy << " is " << sum << endl;
}