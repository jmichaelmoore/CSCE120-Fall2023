#include <iostream>

class Complex {
    double real;
    double imag;
public:
    Complex() : real(0.0), imag(0.0) {}
    Complex(double real, double imaginary) : real(real), imag(imaginary) {}
    Complex(double real) : real(real), imag(0.0) {}
    Complex(const Complex& c) : real(c.real), imag(c.imag) {} // copy constructor
    // add getReal and getImaginary methods that return a double
    // add setReal and setImaginary methods that take in a double
};

int main() {
    // call constructors and output values
    Complex a;
    cout << "a.real: " << a.getReal() << endl;
    cout << "a.imag: " << a.getImaginary() << endl;

    Complex b(2.5, 3.8);
    cout << "b.real: " << b.getReal() << endl;
    cout << "b.imag: " << b.getImaginary() << endl;

    Complex c(5.7);
    cout << "c.real: " << c.getReal() << endl;
    cout << "c.imag: " << c.getImaginary() << endl;

    Complex d(b);
    cout << "d.real: " << d.getReal() << endl;
    cout << "d.imag: " << d.getImaginary() << endl;

    // change values and output
    a.setReal(9.2);
    a.setImaginary(2.4);
    cout << "a.real: " << a.getReal() << endl;
    cout << "a.imag: " << a.getImaginary() << endl;
}