#include <iostream>

using namespace std;

double largestNum(double, double, double); // note no var names

int main() {
    double val1 = 0;
    double val2 = 0;
    double val3 = 0;
    cin >> val1 >> val2 >> val3;
    cout << "Largest: ";
    cout << largestNum(val1, val2, val3);
    cout << endl;
}

double largestNum(double a, double b, double c) {
  if ( a > b && a > c) {
        return a;
    } else if (b > c) {
        return b;
    }
    // else
    return c;
}