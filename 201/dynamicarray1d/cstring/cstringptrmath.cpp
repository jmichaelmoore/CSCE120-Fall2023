#include <iostream>

using namespace std; // don't do this

int main() {
    char* str = new char[3];
    str[0] = 'H';
    str[1] = 'i';
    str[2] = '\0';
    // count characters
    unsigned int cnt = 0;
    char* iter = str;
    while(*iter != '\0') {
        cnt++;
        iter++;
    }
    cout << "cnt: " << cnt << endl;
    delete[] str;
}