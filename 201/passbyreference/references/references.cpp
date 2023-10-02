#include <iostream>

using std::cout, std::endl;

int main() {
    int i = 100;
    int& k = 50; // make into a reference
    cout << "original values" << endl;
    cout << "i: " << i << endl;
    cout << "k: " << k << endl;
    i *= 2;
    cout << "values after modifying i" << endl;
    cout << "i: " << i << endl;
    cout << "k: " << k << endl;
    k += 5;
    cout << "values after modifying k" << endl;
    cout << "i: " << i << endl;
    cout << "k: " << k << endl;
}