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
    // is nums big enough, if not resize
    if (size >= capacity) {
      cout << "resizing" << endl;
      cout << "size: " << size << endl;
      cout << "capacity: " << capacity << endl;
      // new capacity that is double
      unsigned int newCapacity = 2 * capacity;
      if (newCapacity == 0) {
        newCapacity = 1;
      }
      // allocate memory on heap for new array
      int* temp = new int[newCapacity];
      // copy values
      for (unsigned int i=0; i<size; i++) {
        temp[i] = nums[i];
      }
      // delete old memory
      delete [] nums;
      // updates
      nums = temp;
      capacity = newCapacity;
    }
    // add value
    nums[size] = val;
    size++;
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
