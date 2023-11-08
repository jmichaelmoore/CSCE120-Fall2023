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

  ary4 = ary1; // calls copy assignment

  printArray(ary4);




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