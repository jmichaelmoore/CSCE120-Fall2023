#include <iostream>

using std::cin, std::cout, std::endl, std::string;

void D() {
    cout  << "D: start" << endl;
    if (true) {
        cout  << "D: call function that throws an exception" << endl;
        string s = "hi";
        s.at(3);
    }
    cout << "D: end" << endl;
}

void C() {
    cout << "C: start" << endl;
    D();
    cout << "C: end" << endl;
}

void B() {
    cout << "B: start" << endl;
    try {
        C();
    } catch (...) {
        cout << "B: caught an exception from C" << endl;
    }
    cout  << "B: end" << endl;
}

void A() {
    cout  << "A: start" << endl;
    B();
    cout  << "A: end" << endl;
}

int main() {
    A();
}
