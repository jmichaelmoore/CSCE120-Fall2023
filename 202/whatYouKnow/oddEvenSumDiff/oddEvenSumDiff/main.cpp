#include <iostream>

using std::cout, std::cin, std::endl; // need C++ or higher for this line, otherwise put each on separate line with semicolons at end

int main() {
    int num = 0;
    cin >> num;
    int cpy = num;
    int sum = 0;
    int rightdigit = 0;
    int leftdigit = 0;
    while (num > 0) {
        leftdigit = num%10;
        if (leftdigit%2 == 0) {
            sum += rightdigit;
        }
        else {
            sum -= rightdigit;
        }
        rightdigit = leftdigit;
        num /= 10; // num = num / 10;
    }
    sum += rightdigit;
    cout << "The sum of digits of " << cpy << " is " << sum << endl;
}