#include <iostream>
#include "canvas.h"

using std::cin, std::cout, std::endl;

int main() {
  // constrain to fit on standard console
  //   so do not use doubling model, 
  //     just resize to the needed dimensions
  //       consequently size is always capacity

  unsigned int width = 0;
  unsigned int height = 0;
  char** art = nullptr;

  bool cont = true;
  while(cont) {
    char c = ' ';
    unsigned int row = 0;
    unsigned int col = 0;
    cout << "Enter character to add: ";
    cin >> c;
    cout << "Enter where to add (row and col): ";
    cin >> row >> col;

    try {
      addCharacter(c, row, col, art, width, height);
      printCanvas(art, width, height);
    }
    catch (std::exception& e) {
      cout << e.what() << endl;
    }
    
    // ask if we need to add another character
    cout << "Add another character? (y/n) ";
    char contChar = ' ';
    cin >> contChar;
    cont = tolower(contChar) == 'y';
  }
  releaseCanvas(art, width, height);
}