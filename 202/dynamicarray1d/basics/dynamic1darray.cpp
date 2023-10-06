#include <iostream>
#include <stdexcept>

using std::cout, std::cin, std::endl;

double max(double[], unsigned int);
void printAry(double[], unsigned int);

int main() {
  cout << "How many values will you enter?";
  unsigned int size = 0;
  cin >> size;
  if (size == 0) {
    cout << "You must enter at least one value." << endl;
    return 1; // empty array so nothing to read into
  }
  
  // define pointer to appropriate datatype (double)
  // allocate memory for the array with "new"
  // initialize
  // use the array - same as using an array on the heap
  cout << "The max is: " << max(ary, size) << endl; // add call to max
  cout << "Numbers: " << endl;
  printAry(ary, size);
  cout << endl;
  // release memory for the array with "delete[]"
}

double max(double nums[], unsigned int size) {
  if (size == 0) {
    throw std::invalid_argument("Cannot find max for an empty array");
  }
  double max = nums[0];
  for (unsigned int i=1; i<size; ++i) { // start at 1 since index 0 already addressed
    if (nums[i] > max) {
      max = nums[i];
    }
  }
  return max;
}

void printAry(double* nums, unsigned int size) {
  if (size == 0) {
    cout << endl;
    return;
  }
  for (unsigned int i=0; i<size; ++i) {
    cout << nums[i] << " ";
    if ((i+1)%5 == 0) {
      cout << endl;
    }
  }  
}
