#include <iostream>
#include "DynamicArray.h"

using namespace std;

template <typename T>
void printArray(const DynamicArray<T>& ary);

int main() {
  DynamicArray<int> ary1;

  printArray(ary1);

  ary1.push_back(7);
  ary1.push_back(8);

  printArray(ary1);

  DynamicArray<string> ary2(5, "NA");

  printArray(ary2);

  ary2.at(0) = "other";

  printArray(ary2);

  ary2.push_back("wow");

  printArray(ary2);
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