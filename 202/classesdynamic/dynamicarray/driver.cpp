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

  DynamicArray<int> ary3 = ary1; // copy constructor

  printArray(ary1);

  DynamicArray<int> ary4;
  ary4 = ary1; // copy assignment
  printArray(ary4);

  cout << "swap before" << endl;

  DynamicArray<int> ary5(3,7);
  cout << "ary4" << endl;
  printArray(ary4);
  cout << "ary5" << endl;
  printArray(ary5);
  ary4.swap(ary5);
  cout << "swap after" << endl;
  cout << "ary4" << endl;
  printArray(ary4);
  cout << "ary5" << endl;
  printArray(ary5);

  cout << "move assignment 4 & 5" << endl;
  ary4 = std::move(ary5);
  cout << "ary4" << endl;
  printArray(ary4);
  cout << "ary5" << endl;
  printArray(ary5);

 cout << "move constructor ary6 = ary4" << endl;

  DynamicArray<int> ary6 = std::move(ary4);
  cout << "ary4" << endl;
  printArray(ary4);
  cout << "ary6" << endl;
  printArray(ary6);

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