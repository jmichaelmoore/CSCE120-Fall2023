#include <iostream>

using std::cout, std::endl;

int main() {
    int i = 7; // put item on the stack
    int* j = nullptr;
    j = new int(11); // put item on the heap
    cout << “Value in i: " << i << endl;
    cout << "Address of i: " << &i << endl;
    cout << “Value in j: " << j << endl;
    cout << "Address of j: " << &j << endl;
    cout << "*j (value at address pointed to in j): " << *j << endl; 
    delete j; // remove item from the heap
    // j still points to the memory in the heap (dangling pointer)
    // that can be a problem
}