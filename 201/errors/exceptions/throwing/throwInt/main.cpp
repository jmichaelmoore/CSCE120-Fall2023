#include <iostream>

using std::cin, std::cout, std::endl;

void errorMsg(int code) {
    cout << "start errorMsg" << endl;
    if (code%2 == 0) {
        cout << "even error" << endl;
    }
    else {
        cout << "odd error" << endl;
    }
}

void z() {
    cout << "start z" << endl;
    // just for fun (odd number)
    // throw int
    throw 7;
}

void y() {
    cout << "start y" << endl;
    // just for fun (even number)
    // throw int
    throw 6;
} 

int main() {
    cout << "start main" << endl;
    cout << "enter version a or b: ";
    char version = 'c';
    cin >> version;
    switch (tolower(version)) {
        case 'a':
            try {
                y();
                z();
            }
            catch (int e) { // we don't need & here
                errorMsg(e);
            }
            break;
        case 'b':
            try {
                y();
            }
            catch (int e) { // we don't need & here
                errorMsg(e);
            }
            try {
                z();
            }
            catch (int e) { // we don't need & here
                errorMsg(e);
            }
    }
    cout << "end main" << endl;
}