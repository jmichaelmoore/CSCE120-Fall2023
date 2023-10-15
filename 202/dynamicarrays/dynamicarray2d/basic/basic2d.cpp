#include <iostream>

using std::cin, std::cout, std::endl;

// using column major ordering

void loadary(char** ary, unsigned int rows, unsigned int cols);
void printary(const char*const* ary, unsigned int rows, unsigned int cols);

int main() {
  srand(time(NULL));

  // could read in rows and columns, but I'll hard code for this example
  unsigned int rows = 4;
  unsigned int cols = 3;

  // define a pointer to a pointer (char for this example)
  // allocate an array of pointers (column major)
  char** letters = new char*[cols];
  for (unsigned int col=0; col<cols; ++col) {
    letters[col] = new char[rows];
  }
  
  // initialize
  loadary(letters, rows, cols);

  // use
  printary(letters, rows, cols);

  // release memory
  for (unsigned int col=0; col<cols; ++col) {
    delete [] letters[col];
    letters[col] = nullptr;
  }
  delete [] letters;
  letters = nullptr;
  rows = 0;
  cols = 0;
}

void loadary(char** ary, unsigned int rows, unsigned int cols) {
  // can have col or row be the outer loop, it doesn't matter
  for (unsigned int col=0; col<cols; col++) {
    for (unsigned int row=0; row<rows; row++) {
      char val;
      if (rand()%2) { // uppercase
        val = rand()%26 + 'a';
      }
      else { // lowercase
        val = rand()%26 + 'A';
      }
      ary[col][row] = val;
    }
    cout << endl;
  }
}

void printary(const char*const* ary, unsigned int rows, unsigned int cols) {
  // must print with row in outer loop to match our mental model
  for (unsigned int row=0; row<rows; row++) {
    for (unsigned int col=0; col<cols; col++) {
      cout << ary[col][row] << " ";
    }
    cout << endl;
  }
}