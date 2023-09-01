#include <iostream>
#include "arrayFunctions.h"

using std::cin, std::cout, std::endl;

using std::out_of_range;

// always throw an out_of_range exception for any invalid index

void loadRandom(int ary[], unsigned int size) {
  for (unsigned int i=0; i<size; ++i) {
    ary[i] = rand()%1000;
  }
}

void insert(int val, unsigned int index, 
          int ary[], unsigned int size) {
  // assume index <= size
  // assume size < capacity
  for (unsigned int i=0; i<(size-index); ++i) {
    ary[size-i] = ary[size-i-1];
  }
  ary[index] = val;
}

void removeAtIndex(unsigned int index, 
          int ary[], unsigned int size) {
}

void removeFirstOf(int val, 
          int ary[], unsigned int size) {
}

int getMax(const int ary[], unsigned int size) {
  return 0;
}

int getMin(const int ary[], unsigned int size) {
  return 0;
}

unsigned int countVal(int val, const int ary[], unsigned int size) {
  return 0;
}

// print including empty
void print(const int ary[], unsigned int size) {
  if (size == 0) {
    cout << "Empty array" << endl;
  }
  else {
    for (unsigned int i = 0; i < size; ++i) {
      cout << ary[i] << endl;
    }
  }
}
