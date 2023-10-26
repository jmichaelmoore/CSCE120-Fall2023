 // define a class complex number
 //   has a real part and an imaginary part (make them double)
 // constructors
 //  - default
 //  - real and imagingary parameters
 //  - real parameter
 //  - imaginary parameter (not possible)
 //  - if you have time

 class Complex {
    double real;
    double imag;
public:
    Complex() : real(0.0), imag(0.0) {}
    Complex(double real, double imaginary) : real(real), imag(imaginary) {}
    Complex(double real) : real(real), imag(0.0) {}
    Complex(const Complex& c) : real(c.real), imag(c.imag) {} // copy constructor
 }