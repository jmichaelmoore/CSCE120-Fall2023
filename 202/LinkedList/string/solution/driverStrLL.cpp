#include <iostream>
#include <iomanip>
#include "StrLL.h"

using std::cout, std::endl;

int main() {
    StrLL s;
    cout << "-";
    s.print();
    cout << "-" << endl;
    cout << "-";
    s.printReverse();
    cout << "-" << endl << endl;

    s.insertFront('b');
    s.insertBack('c');
    s.insertFront('a');
    cout << "-";
    s.print();
    cout << "-" << endl;
    cout << "-";
    s.printReverse();
    cout << "-" << endl << endl;

    s.insertAfter('b', 'z');
    cout << "-";
    s.print();
    cout << "-" << endl;
    cout << "-";
    s.printReverse();
    cout << "-" << endl << endl;

    s.insertAfter('c', 'w');
    cout << "-";
    s.print();
    cout << "-" << endl;
    cout << "-";
    s.printReverse();
    cout << "-" << endl << endl;

    s.insertAfter('k', 'm');
    cout << "-";
    s.print();
    cout << "-" << endl;
    cout << "-";
    s.printReverse();
    cout << "-" << endl << endl;

    s.insertBefore('z', 'k');
    cout << "-";
    s.print();
    cout << "-" << endl;
    cout << "-";
    s.printReverse();
    cout << "-" << endl << endl;

    s.insertBefore('t', 'q');
    cout << "-";
    s.print();
    cout << "-" << endl;
    cout << "-";
    s.printReverse();
    cout << "-" << endl << endl;

    s.insertBefore('m', 'f');
    cout << "-";
    s.print();
    cout << "-" << endl;
    cout << "-";
    s.printReverse();
    cout << "-" << endl << endl;

    s.insertBefore('q', 't');
    cout << "-";
    s.print();
    cout << "-" << endl;
    cout << "-";
    s.printReverse();
    cout << "-" << endl << endl;

    cout << "s hasChar z: " << std::boolalpha << s.hasChar('z') << endl;
    cout << "s hasChar t: " << std::boolalpha << s.hasChar('t') << endl;
    cout << "s hasChar m: " << std::boolalpha << s.hasChar('m') << endl;
    cout << "s hasChar o: " << std::boolalpha << s.hasChar('o') << endl;

    s.remove('k');
    cout << "-";
    s.print();
    cout << "-" << endl;
    cout << "-";
    s.printReverse();
    cout << "-" << endl << endl;

    s.remove('t');
    cout << "-";
    s.print();
    cout << "-" << endl;
    cout << "-";
    s.printReverse();
    cout << "-" << endl << endl;

    s.remove('m');
    cout << "-";
    s.print();
    cout << "-" << endl;
    cout << "-";
    s.printReverse();
    cout << "-" << endl << endl;

    s.remove('o');
    cout << "-";
    s.print();
    cout << "-" << endl;
    cout << "-";
    s.printReverse();
    cout << "-" << endl << endl;

    StrLL s2;
    s2.insertFront('x');
    cout << "-";
    s2.print();
    cout << "-" << endl;
    cout << "-";
    s2.printReverse();
    cout << "-" << endl << endl;
    s2.remove('x');
    cout << "-";
    s2.print();
    cout << "-" << endl;
    cout << "-";
    s2.printReverse();
    cout << "-" << endl << endl;

    StrLL s3("Hello");
    cout << "-";
    s3.print();
    cout << "-" << endl;
    cout << "-";
    s3.printReverse();
    cout << "-" << endl << endl;

    StrLL s4 = s3;
    cout << "-";
    s4.print();
    cout << "-" << endl;
    cout << "-";
    s4.printReverse();
    cout << "-" << endl << endl;

}