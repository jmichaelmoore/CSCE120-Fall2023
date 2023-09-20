#include <iostream>
#include <cmath>

using std::cout, std::cin, std::endl; 

void outputEquation(double a, double b, double c);
void processLinear(double b, double c);
void processQuadratic(double a, double b, double c);
void processImaginary(double disc, double a, double b, double c);
void processReal(double disc, double a, double b, double c);
bool isSolution(double a, double b, double c, double xReal, double xImag);

/**
Output prompt
Input coefficients (a, b, c)
Output equation (a, b, c)
If (a = 0 and b = 0)
Output “Unable to determine roots”
Else
If a = 0
processLinear
Else
processQuadratic

*/
int main() {
    cout << "Input coefficients a, b, and c: ";
    double a=0, b=0, c=0;
    cin >> a >> b >> c;
    outputEquation(a, b, c);
    if (a == 0 && b == 0) {
        cout << "Unable to determine roots" << endl;
    }
    else if (a==0) {
        processLinear(b, c);
    }
    else {
        processQuadratic(a, b, c);
    }

  
}

/*Output a”x^2 + “b”x + “c” = 0”*/
void outputEquation(double a, double b, double c) {
    cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
}

/*
b & c passed as parameters
If b = 0 throw exception
x <- -c/b
Output “x = “x
*/
void processLinear(double b, double c) {
    if (b == 0) throw std::invalid_argument("b cannot be 0");
    cout << "x = " << -c/b << endl;
}

/*
disc <- b^2 - 4ac
If disc is neg
processImaginary
Else
processReal

*/
void processQuadratic(double a, double b, double c) {
    double disc = b*b - 4*a*c;
    if (disc < 0) { // disc is negative
        processImaginary(disc, a, b, c);
    }
    else {
        processReal(disc, a, b, c);
    }
}

/*
ImagPart1 < sqrt(-((disc)/2a) // implicit i here
ImagPart2 < -sqrt(-((disc/2a) // implicit i here
RealPart <- -b/2a
Output “x = “RealPart” + “ImagPart1”i”
Output “x = “RealPart” + “ImagPart2”i”

*/
void processImaginary(double disc, double a, double b, double c) {
    //cout << "start imaginary" << endl;
    double realPart = -1*b/(2*a);
    double ImagPart1 = sqrt(-1*disc)/(2*a);
    double ImagPart2 = -1*sqrt(-1*disc)/(2*a);
    //ImagPart1 =200;
    cout << "will call isSoution" << endl;
    if (!isSolution(a,b,c,realPart,ImagPart1)) {
        cout << "problem with calcuation of imaginary part 1" <<endl;
    }
    if (!isSolution(a,b,c,realPart,ImagPart2)) {
        cout << "problem with calcuation of imaginary part 2" << endl;
    }
    cout << "x = " << realPart << " + " << ImagPart1 << "i" << endl;
    cout << "x = " << realPart << " + " << ImagPart2 << "i" << endl;
}
/*
axr2- axi2+bxr+ c
*/

void processReal(double disc, double a, double b, double c) {

}

bool isSolution(double a, double b, double c, double xReal, double xImag) {
    double realTerm = a*xReal*xReal - a*xImag*xImag + b*xReal + c;
    double imagTerm = -1*2*a*xReal*xImag - b*xImag;
    double sum = realTerm + imagTerm;
    //cout << "sum: " << sum << endl;
    return(fabs(sum) <= 0.00000000001);
}