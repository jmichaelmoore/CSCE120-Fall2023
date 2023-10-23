#include <iostream>
#include <stdexcept>
#include <sstream>
#include "canvas.h"

using std::cin, std::cout, std::endl;

void addCharacter(char c, unsigned int row, unsigned int col, char**& canvas, unsigned int& width, unsigned int& height) {
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
  
  // check if location is available in current size
  if (row >= height || col >= width) { // need to resize
    unsigned int newWidth = width;
    if (col >= width) newWidth = col+1;
    unsigned int newHeight = height;
    if (row >= height) newHeight = row+1;
    resizeCanvas(canvas, width, height, newWidth, newHeight);
  }
  // if it isn't resize
  // regardless, add the character to the correct location.
  canvas[row][col] = c;
}

char** makeCanvas(unsigned int width, unsigned int height) {
  // initialize with ' ' spaces
  cout << "makeCanvas" << endl;
  char** canvas = new char*[height];
  for (unsigned int row=0; row<height; ++row) {
    canvas[row] = new char[width];
    for (unsigned int col=0; col<width; ++col) {
      canvas[row][col] = ' ';
    }
  }
  return canvas;
}

void resizeCanvas(char**& canvas, unsigned int& width,  unsigned int& height, unsigned int newWidth, unsigned int newHeight) {
  // make new array
  cout << "resize" << endl;
  char** temp = makeCanvas(newWidth, newHeight);
  // copy
  for (unsigned int row=0; row<height; ++row) {
    for (unsigned int col=0; col<width; ++col) {
      temp[row][col] = canvas[row][col];
    }
  }
  // delete old memory
  releaseCanvas(canvas, width, height);
  // update
  canvas = temp;
  width = newWidth;
  height = newHeight;
}

void releaseCanvas(char**& canvas, unsigned int& width, unsigned int& height) {
  for (unsigned int row=0; row<height; ++row) {
    delete [] canvas[row];
  }
  delete [] canvas;
  canvas = nullptr;
  width = 0;
  height = 0;
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