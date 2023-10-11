#include <iostream>
#include "arrayFunctions.h"

using std::cin, std::cout, std::endl;

using std::out_of_range;

// always throw an out_of_range exception for any invalid index

void loadRandom(int ary[], int size, int capacity) {
  if (size == 0) {
    throw std::invalid_argument("array size cannot be zero");
  }
  if (size > capacity) {
    throw std::invalid_argument("array size cannot be greater than capacity");
  }
  for (int i=0; i<size; ++i) {
    ary[i] = rand()%1000;
  }
}

void insert(int val, unsigned int index, 
          int ary[], unsigned int size) {
  // assume size index <= size
  if (size == 0) {
    throw std::invalid_argument("array size cannot be zero");
  }
  if (index > size) {
    throw std::out_of_range("index is too big"); // we'll make this not necessary later
  }
  // assume size < capacity
  if (size >= CAPACITY) {
    throw std::invalid_argument("no space for a new value");
  }
  // slide values over
  for (unsigned int i = 0; i < size-index; ++i) {
    // slide number
    ary[size-i] = ary[size-i-1];
  }
  ary[index] = val;
}

void removeAtIndex(unsigned int index, 
          int ary[], unsigned int size) {
  if (size == 0) {
    throw std::invalid_argument("array size cannot be zero");
  }
  if (index >= size) {
    throw std::out_of_range("index must be less than size");
  }
  for (unsigned int i=index; i<size-1; ++i) {
    ary[i] = ary[i+1];
  }
}

void removeFirstOf(int val, 
          int ary[], unsigned int size) {
  // do on your own
}

int getMax(const int ary[], unsigned int size) {
  if (size == 0) {
    throw std::invalid_argument("array size cannot be zero");
  }
  int max = ary[0];
  for (unsigned int i=0; i<size; ++i) {
    if (ary[i] > max) {
      max = ary[i];
    }
  }
  return max;
}

int getMin(const int ary[], unsigned int size) {
  // do on your own
  return 0;
}

unsigned int countVal(int val, const int ary[], unsigned int size) {
  // do on your own
  return 0;
}

// print including empty
void print(const int ary[], unsigned int size) {
  if (size == 0) {
    cout << "Empty list" << endl;
  } else {
    for (unsigned int i=0; i<size; ++i) {
      cout << ary[i] << endl;
    }
  }
}
