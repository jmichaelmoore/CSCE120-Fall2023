#include <iostream>

using std::cout;
using std::endl;

int main() {
  int i(11);
  
  int j = i;
  
  j = 22;
  
  int k(i);
  
  k = 33;
  
  int m = 44;
  
  m = i;
  
  m = 55;

  cout << "i: " << i << endl;
  cout << "j: " << j << endl;
  cout << "k: " << k << endl;
  cout << "m: " << m << endl;
  
}