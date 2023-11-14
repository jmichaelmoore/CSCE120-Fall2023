#include <iostream>
#include "DynamicInt.h"

using std::cout;
using std::endl;

int main() {
  DynamicInt i(11); // calls parameterized constructor
  
  DynamicInt j = i; // calls copy constructor
  
  j = 22;
  
  DynamicInt k(i); // calls copy constructor
  
  k = 33;
  
  DynamicInt m(44); // calls parameterized constructor
  
  m = i; // calls copy assignment
  
  m = 55;

  cout << "i: " << i << endl;
  cout << "j: " << j << endl;
  cout << "k: " << k << endl;
  cout << "m: " << m << endl;

  // move assignment

  i = std::move(j);
  cout << "move i = j" << endl;

  cout << "i: " << i << endl;
  cout << "j: " << j << endl;
  cout << "k: " << k << endl;
  cout << "m: " << m << endl;


  DynamicInt o = std::move(m);
  
  cout << "move DynamicInt o = m" << endl;
  cout << "i: " << i << endl;
  cout << "j: " << j << endl;
  cout << "k: " << k << endl;
  cout << "m: " << m << endl;
  cout << "o: " << o << endl;

}