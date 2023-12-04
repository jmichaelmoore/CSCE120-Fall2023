#include <iostream>

using std::cout, std::endl;

unsigned int fib(unsigned int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n-1) + fib(n-2);
}

int main() {
    unsigned int a = 50;
    cout << "fib(" << a << "): " << fib(a) << endl;
}