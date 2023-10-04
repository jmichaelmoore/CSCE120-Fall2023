#include <iostream>

int getANumber() {
   int* z = new int(15);
   return *z;
}

int main() {
   int* k = new int(3);
   k = new int (7);
   int w = getANumber();
}
