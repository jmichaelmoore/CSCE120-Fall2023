#include <iostream>

using std::cout, std::endl, std::string;

int main() {
    int i = 7; // put item on the stack
    int* j = nullptr; // int *j = nullptr;
    j = new int(11); // put item on the heap
    cout << "Value in i: " << i << endl;
    cout << "Address of i: " << &i << endl;
    cout << "Value in j: " << j << endl;
    cout << "Address of j: " << &j << endl;
    cout << "*j (value at address pointed to in j): " << *j << endl; 
    delete j; // remove item from the heap
    // j still points to the memory in the heap (dangling pointer)
    // that can be a problem
    cout << "dereference dangling pointer (*j): " << *j << endl;
    string* s = new string("Hello");
    cout << "string size: " << s->size() << endl; 
    cout << "first character: " << s->at(0) << endl;
}