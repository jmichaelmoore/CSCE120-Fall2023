#include <iostream>
#include "DynamicArray.h"

using namespace std;

template <typename T>
void printArray(const DynamicArray<T>& ary);

int main() {
  // declare/define int version
  DynamicArray<int> ary1;

  printArray(ary1);

  for (size_t i=0; i<10; ++i) {
    ary1.push_back(i+1);
  }

  printArray(ary1);

  DynamicArray<string> ary2(5,"NA");

  printArray(ary2);

  ary2.at(0) = "other";

  printArray(ary2); // calls copy constructor

  DynamicArray<int> ary3(ary1);
  
  printArray(ary3);

  DynamicArray<int> ary4;

  printArray(ary4);

  cout << "copy assignment" << endl;
  ary4 = ary1; // calls copy assignment

  printArray(ary4);

  DynamicArray<int> ary5;
  ary5.push_back(3);
  ary5.push_back(5);
  ary5.push_back(7);

 cout << "swap before" << endl;

  cout << "ary4" << endl;
  printArray(ary4);
  cout << "ary5" << endl;
  printArray(ary5);

  ary5.swap(ary4);
  cout << "swap after" << endl;

  cout << "ary4" << endl;
  printArray(ary4);
  cout << "ary5" << endl;
  printArray(ary5);

  DynamicArray<int> ary6 = std::move(ary5);
  cout << "ary5" << endl;
  printArray(ary5);
  cout << "ary6" << endl;
  printArray(ary6);

  ary6 = std::move(ary4);
  cout << "move assignment" << endl;
cout << "ary4" << endl;
  printArray(ary4);
  cout << "ary6" << endl;
  printArray(ary6);

  // declare/define double version  
}

template <typename T>
void printArray(const DynamicArray<T>& ary) {
  cout << endl << "array: " << endl;
  cout << "   size: " << ary.size() << endl;
  cout << "   capacity: " << ary.capacity() << endl;
  if (ary.empty()) {
    cout << "Empty!" << endl;
  }
  else {
    for (size_t i=0; i<ary.size(); ++i) {
      cout << ary.at(i) << endl;
    }
  }
}