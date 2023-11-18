#include <iostream>
#include "StrLL.h"

using std::cout, std::endl;

int main() {
    StrLL s;
    s.print();
    s.printReverse();
    s.insertFront('a');
    s.insertBack('c');
    s.print();
    s.printReverse();
}