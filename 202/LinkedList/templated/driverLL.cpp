#include <iostream>
#include <iomanip>
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
  ll1.insertAfter(1, 3);
  cout << "ll1: " << endl;
  ll1.print();
  ll1.insertAfter(5, 9);
  cout << "ll1: " << endl;
  ll1.print();
  ll1.insertAfter(25, 4);
  cout << "ll1: " << endl;
  ll1.print();
  ll1.insertBefore(7, 2);
  cout << "ll1: " << endl;
  ll1.print();
  ll1.insertBefore(1, 6);
  cout << "ll1: " << endl;
  ll1.print();
  ll1.insertBefore(25,8);
  cout << "ll1: " << endl;
  ll1.print();

  cout << "ll1 hasValue 7: " << std::boolalpha << ll1.hasValue(7) << endl;
  cout << "ll1 hasValue 8: " << std::boolalpha << ll1.hasValue(8) << endl;
  cout << "ll1 hasValue 4: " << std::boolalpha << ll1.hasValue(4) << endl;
  cout << "ll1 hasValue 25: " << std::boolalpha << ll1.hasValue(25) << endl;

  ll1.remove(1);
  cout << "ll1: " << endl;
  ll1.print();
  ll1.remove(8);
  cout << "ll1: " << endl;
  ll1.print();
  ll1.remove(4);
  cout << "ll1: " << endl;
  ll1.print();
  ll1.remove(25);
  cout << "ll1: " << endl;
  ll1.print();
  ll2.remove(9);
  cout << "ll2: " << endl;
  ll2.print();
}