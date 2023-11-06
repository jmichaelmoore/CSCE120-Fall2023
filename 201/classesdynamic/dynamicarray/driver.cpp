#include <iostream>
#include "DynamicArray.h"

using namespace std;

template <typename T>
void printArray(const DynamicArray<T>& ary);

int main() {
  // declare/define int version
  DynamicArray<int> ary1;

  printArray(ary1);

  DynamicArray<string> ary2(5,"NA");

  printArray(ary2);

  ary2.at(0) = "other";

  printArray(ary2);


  // declare/define double version  
}

template <typename T>
void printArray(const DynamicArray<T>& ary) {
  cout << endl << "array: " << endl;
  if (ary.empty()) {
    cout << "Empty!" << endl;
  }
  else {
    for (size_t i=0; i<ary.size(); ++i) {
      cout << ary.at(i) << endl;
    }
  }
}