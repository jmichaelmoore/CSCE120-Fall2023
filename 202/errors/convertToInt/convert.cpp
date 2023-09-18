#include<iostream>
#include<string>

using std::cin, std::cout, std::endl, std::string;

int main() {
    string term; // constructor initialzies to empty string, we'll see this soon
    do {
        cout << "Enter term to convert: ";
        cin >> term;
        size_t sz = 0;
        int val = std::stoi(term, &sz);
        cout << term << " times 2 is " << (val*2) << endl;
    } while (term != ".");
}