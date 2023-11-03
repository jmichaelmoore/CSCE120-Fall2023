#include <iostream>
#include "Pixel.h"

using std::cout, std::endl, std::string;

void printPixel(string identifier, const Pixel& p ) {
    cout << identifier << " (red): " << p.getRed() << endl;
    cout << identifier << " (green): " << p.getGreen() << endl;
    cout << identifier << " (blue): " << p.getBlue() << endl;
}

int main() {
    cout << "default constructor" << endl;
    Pixel a;
    printPixel("a", a);

    cout << "constructor passed 10, 20, 30" << endl;
    Pixel b(10, 20, 30);
    printPixel("b", b);

    cout << "copy constructor passed b" << endl;
    Pixel c = b; // equivalent to Pixel c(b);
    printPixel("c", c);

    cout << "setters called for a with 200, 150, 100" << endl;
    a.setRed(200);
    a.setBlue(150);
    a.setGreen(100);
    printPixel("a", a);

    cout << "Pixel d = a";
    Pixel d = a;
    printPixel("d", d);

    cout << "set a to red only and b to green only" << endl;
    a.setRed(255);
    a.setGreen(0);
    a.setBlue(0);
    printPixel("a", a);
    b.setRed(0);
    b.setGreen(0);
    b.setBlue(255);
    printPixel("b", b);

    cout << "d = a + b;" << endl;
    d = a + b;
    printPixel("d", d);

    cout << "-d;" << endl;
    -d;
    printPixel("d", d);
    printPixel("c", c);
    cout << "c == d: " << std::boolalpha << (c==d) << endl;

    cout << "c = d;" << endl;
    c = d; // note we did not have to implement this
    printPixel("d", d);
    printPixel("c", c);
    cout << "c == d: " << std::boolalpha << (c==d) << endl;

    cout << "c: " << c << endl;
}