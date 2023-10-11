#include <iostream>
#include <iomanip>

using std::cin, std::cout, std::endl;
using std::setw;

void printAry(const int nums[][], unsigned int rows, unsigned int cols);

int main() {
  cout << "How many row and columns for multiplication table? (Max 9)";
  unsigned int rows = 0, cols = 0;
  cin >> rows >> cols;
  if (rows == 0 || cols == 0) {
    cout << "You must have at least one row and one column." << endl;
    return 1; // empty array so nothing to read into
  }
  if (rows > 9 || cols > 9) {
    cout << "You can't have a row or column over nine." << endl;
    return 1; // empty array so nothing to read into
  }
  
//  printAry(, rows, cols);
  
}

void printAry(const int nums[][], unsigned int rows, unsigned int cols) {
  if (rows == 0 || cols == 0) {
    throw std::invalid_argument("Must have at least one row and one column");
  }
  for (unsigned int i=0; i<rows; ++i) { 
    for (unsigned int j=0; j<cols; ++j) {
      cout << setw(3) << nums[i][j];
    }
    cout << endl;
  }
}
