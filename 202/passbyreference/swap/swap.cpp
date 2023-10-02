#include <iostream>

using std::cout, std::endl;

void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 11;
    int y = 7;
    
    cout << "before swap: " << endl;
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;

    swap (x, y);

    cout << "after swap: " << endl;
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
}