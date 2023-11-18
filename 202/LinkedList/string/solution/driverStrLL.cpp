#include <iostream>
#include "StrLL.h"

using std::cout, std::endl;

int main() {
    StrLL s;
    cout << "-";
    s.print();
    cout << "-" << endl;
    cout << "-";
    s.printReverse();
    cout << "-" << endl;
    s.insertFront('b');
    s.insertBack('c');
    s.insertFront('a');
    cout << "-";
    s.print();
    cout << "-" << endl;
    cout << "-";
    s.printReverse();
    cout << "-" << endl;
}