#include <iostream>

using std::cout, std::endl;

int em(int a, int b) {
   int k = 3;
   int whoop = a + b + k;
   return whoop;
}

int gig(int rev) {
   int howdy = 4;
   return em(rev, howdy);
}

int main() {
   int b = gig(em(1, 6));
   cout << "b: " << b << endl;
}