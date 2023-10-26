// write complex number class call it "Complex"
// data members - real part imaginary part (use double)
// write constructors
//  - default constructor
//  - real and imaginary parameters
//  - real parameter
//  - imaginary parameter (impossible
//  - Complex i.e. copy consstructor

class Complex {
    double real;
    double imag;
public:
    Complex() : real(0.0), imag(0.0) {} // default constructor
    Complex(double real, double imaginary) : real(real), imag(imaginary) {}
    Complex(double real) : real(real), imag(0.0) {}
    Complex(const Complex& c) : real(c.real), imag(c.imag) {} // copy constructor
};

int main() {
    Complex c(1,2);
}