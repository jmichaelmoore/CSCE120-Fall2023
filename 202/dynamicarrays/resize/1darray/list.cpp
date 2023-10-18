#include <iostream>

using std::cin, std::cout, std::endl;

void printAry(const int* values, unsigned int size);

int main() {
  int val = -1;
  cout << "Enter numbers. Enter zero to stop." << endl;
  int* nums = nullptr;
  unsigned int capacity = 0;
  unsigned int size = 0;
  while (val != 0) {
    cin >> val;
    cout << "adding " << val << endl;
    // add values (except for 0) to the array
    // use doubling model for resizing
  }
  printAry(nums, size);
  delete[] nums;
}

void printAry(const int* values, unsigned int size) {
  cout << "numbers: " << endl;
  for (unsigned int i=0; i<size; ++i) {
    cout << values[size-1-i] << endl;
  }
}
