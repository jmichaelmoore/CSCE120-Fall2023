#include <iostream>
#include <stdexcept>
#include <sstream>
#include "canvas.h"

using std::cin, std::cout, std::endl;

void addCharacter(char c, unsigned int row, unsigned int col, char**& canvas, unsigned int& width, unsigned int& height) {
  cout << "addCharacter" << endl;
  if (!isprint(c)) {
    throw std::invalid_argument("Character must be printable");
  }
  if (row >= MAX_HEIGHT) {
    std::ostringstream oss;
    oss << "row must be less than " << MAX_HEIGHT <<", you entered " << row;
    throw std::invalid_argument(oss.str());
  }
  if (col >= MAX_WIDTH) {
    std::ostringstream oss;
    oss << "col must be less than " << MAX_WIDTH <<", you entered " << col;
    throw std::invalid_argument(oss.str());
  }
  // if we make it this far we know that row and col are valid values and c is printable

  // check if location is available in current size
  // if it isn't resize
  // regardless, add the character to the correct location.
}

char** makeCanvas(unsigned int width, unsigned int height) {
  // allocate on heap and initialize with ' ' spaces
  // row major
  cout << "makeCanvas" << endl;
  char** canvas = nullptr;
  return canvas;
}

void resizeCanvas(char**& canvas, unsigned int& width,  unsigned int& height, unsigned int newWidth, unsigned int newHeight) {
  cout << "resizeCanvas" << endl;
  // make new array
  // copy
  // delete old memory
  // update
}

void releaseCanvas(char**& canvas, unsigned int& width, unsigned int& height) { 
  cout << "releaseCanvas" << endl;
  // row major
}

void printCanvas(const char*const* canvas, unsigned int width, unsigned int height) {
  cout << "printCanvas" << endl;
  for (unsigned int row=0; row<height; ++row) {
    for (unsigned int col=0; col<width; ++col) {
      cout << canvas[row][col];
    }
    cout << endl;
  }
}