#include <iostream>

using std::cout, std::cin, std::endl; // need C++ or higher for this line, otherwise put each on separate line with semicolons at end

int main() {
    int num = 0;
    cin >> num;
    int cpy = num;
    int sum = 0;
    while (num > 0) {
        int digit = num%10;
        num /= 10; // num = num / 10;
        sum += digit;
    }
    cout << "The sum of digits of " << cpy << " is " << sum << endl;
}