#include <iostream>
#include <cmath>

using std::cout, std::cin, std::endl; 

void outputEqation(double a, double b, double c);
void processLinear(double b, double c);
void processQuadratic(double a, double b, double c);
void processImaginary(double disc, double a, double b, double c);
void processReal(double disc, double a, double b, double c);
bool isSolution(double a, double b, double c, double xReal, double XImag);
/*
Output prompt
Output prompt
Input coefficients (a, b, c)
Output equation (a, b, c)
If a=0 // linear equation
processLinear (b, c)
Else 
processQuadratic (a, b, c)
*/
int main() {
  cout << "input coefficients a, b and c: " << endl;
  double a=0, b=0, c=0;
  cin >> a >> b >> c;
  outputEqation(a, b, c);
  if (a == 0) {
    processLinear(b, c);
  }
  else {
    processQuadratic(a, b, c);
  }
}

/*
Output a”x^2 + “b”x + “c” = 0”
*/
void outputEqation(double a, double b, double c) {
    cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
}

/*
If b = 0 // not linear
Output “unable to determine roots”
Else
x <- -c/b
Output “x = “x
*/
void processLinear(double b, double c) {
    if (b == 0) {
        cout << "Unable to determine roots" << endl;
    }
    else {
        cout << -c/b << endl;
    }

}

/*
Parameters a, b, c
Disc <- b^2 - 4ac
If disc is negative
processImagninary
Else
processReal
*/
void processQuadratic(double a, double b, double c) {
    double disc = b*b - 4*a*c;
    if (disc < 0) { // is negative
        processImaginary(disc, a, b, c);
    }
    else {
        processReal(disc, a, b, c);
    }

}

/*
Disc <- Disc*-1
realPart <- -b/2a
imagPart1 <- sqrt(disc)/2a (note disc made positive above)
imagPart2 <- -sqrt(disc)/2a
Output “x = “realPart” + “imagPart1”i”
Output “x = “realPart” + “imagPart2”i”
*/
void processImaginary(double disc, double a, double b, double c) {
    disc *= -1;
    double realPart = -1*b/(2*a);
    double imagPart1 = sqrt(disc)/(2*a);
    double imagPart2 = -1*sqrt(disc)/(2*a);
    //imagPart2 = 7;
    if (!isSolution(a, b, c, realPart, imagPart1)) {
        cout << "Problem with imaginary part 1";
    }
    if (!isSolution(a, b, c, realPart, imagPart2)) {
        cout << "Problem with imaginary part 2";
    }
    cout << "x = " << realPart << " + " << imagPart1 << "i" << endl;
    cout << "x = " << realPart << " + " << imagPart2 << "i" << endl;
}

void processReal(double disc, double a, double b, double c) {

}

bool isSolution(double a, double b, double c, double xReal, double xImag) {
    double realTerm = a*xReal*xReal - a*xImag*xImag + b*xReal + c;
    double imagTerm = -2*a*xReal*xImag - b*xImag;
    double sum = realTerm + imagTerm;
    return (fabs(sum) <= 0.0000000001);
}
