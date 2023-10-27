#include <iostream>
#include "Pixel.h"

using std::cout, std::endl;

int main() {
    Pixel a;
    cout << "a (red): " << a.getRed() << endl;
    cout << "a (green): " << a.getGreen() << endl;
    cout << "a (blue): " << a.getBlue() << endl;
}