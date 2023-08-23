#include <iostream>

// using namespace std;  // not preferred

using std::cout, std::cin, std::endl;

int main() {
    std::string name;
    cout << "What is your name? ";
    cin >> name;
    std::cout << "Gig Em " << name << "!" << std::endl;
}