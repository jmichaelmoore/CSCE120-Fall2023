#include <iostream>

using std::cin, std::cout, std::endl, std::string;

int main() {
    string paragraph; // constructor initialzies to empty string, we'll see this soon
    cout << "Enter paragraph: ";
    getline(cin,paragraph);
    string strToFind;
    do {
        cout << "Enter string to find: ";
        cin >> strToFind;
        size_t location = 0; // size_t is an alias for unsigned int
        location = paragraph.find(strToFind);
        // use find function
        // update to give meaningful message when not found
        if (location == string::npos) {
            cout << strToFind << " is not in the paragraph" << endl;
        }
        else {
            cout << strToFind << " starts at index " << location << endl;
        }
    } while (strToFind != ".");
}