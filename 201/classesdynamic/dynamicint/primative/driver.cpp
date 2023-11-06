#include <iostream>

using std::cout;
using std::endl;

int main() {
  int i(11); // calls parameterized constructor
  
  int j = i; // calls copy constructor
  
  j = 22;
  
  int k(i); // calls copy constructor
  
  k = 33;
  
  int m(44); // calls parameterized constructor
  
  m = i; // calls copy assignment
  
  m = 55;

  cout << "i: " << i << endl;
  cout << "j: " << j << endl;
  cout << "k: " << k << endl;
  cout << "m: " << m << endl;
  
}