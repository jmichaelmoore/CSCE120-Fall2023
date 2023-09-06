#include <iostream>
#include "arrayFunctions.h" 
// only include header file, NOT the cpp file

using std::cin, std::cout, std::endl;
using std::out_of_range;

void printMenu();

// It would be good to break main into more functions...
//   However, we'll need to learn more about pass by reference
//     before we can do that.
int main() {
  srand(time(NULL));
  
  int ary[CAPACITY] = {0};
  unsigned int size = 0;
  
  char menuChoice = ' ';
  
  while ('Q' != toupper(menuChoice)) {
  
    printMenu();
    
    cout << endl << "Please enter choice: ";
    cin >> menuChoice;

  int num = 0;
  unsigned int index = 0;
    
  switch (toupper(menuChoice)) {
    case 'L':
      cout << "Input number of random values to load: ";
      cin >> size;
      loadRandom(ary, size);
      break;
    case 'I':
      cout << "Input value to insert: ";
      cin >> num;
      cout << "Input index to insert: ";
      cin >> index;
      try {
        insert(num, index, ary, size);
        size++;
      }
      catch (out_of_range &e) {
        cout << e.what() << endl;
      }
      // we'll let the function update size later when we learn more about pass by reference!
      break;
    case 'R':
      cout << "Input index to delete: ";
      cin >> index;
      try {
        removeAtIndex(index, ary, size);
        size--;
      }
      catch (out_of_range &e) {
        cout << e.what() << endl;
      }
      break;
    case 'F':
      cout << "Input value to delete: ";
      cin >> num;
      try {
        removeFirstOf(num, ary, size);
        size--;
      }
      catch (out_of_range &e) {
        cout << e.what() << endl;
      }
      break;
    case 'X':
      cout << "Max: " << getMax(ary, size);
      cout << endl;
      size++;
      break;
    case 'N':
      cout << "Min: " << getMin(ary, size);
      cout << endl;
      size++;
      break;
    case 'C':
      cout << "Input value to delete: ";
      cin >> num;
      try {
        cout << num << " appears " << countVal(num, ary, size);
        cout << " times" << endl;
        size++;
      }
      catch (out_of_range &e) {
        cout << e.what() << endl;
      }
      break;
    case 'P':
      print(ary, size);
      break;
    case 'S':
      cout << "Size: " << size << endl;
      break;
  }
  
  
  }
  
  cout << endl << "Goodbye!" << endl;
  
}

void printMenu() {
  cout << "'L' - Load random values" << endl;
  cout << "'I' - Insert number at index" << endl;
  cout << "'R' - Remove number at index" << endl;
  cout << "'F' - Remove first instance of value" << endl;
  cout << "'X' - Get maximum value" << endl;
  cout << "'N' - Get miniumum value" << endl;
  cout << "'C' - Count instances of number" << endl;
  cout << "'P' - Print values" << endl;
  cout << "'S' - Size" << endl;
  cout << "'Q' - Quit" << endl;
}