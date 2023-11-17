#include <iostream>
#include "LL.h"

using std::cout, std::endl;

int main() {
  LL<int> ll1;
  cout << "ll1: " << endl;
  ll1.print();
  ll1.insertFront(7);
  ll1.insertBack(5);
  ll1.insertFront(1);
  cout << "ll1: " << endl;
  ll1.print();
  LL<int> ll2(9);
  cout << "ll2: " << endl;
  ll2.print();
}