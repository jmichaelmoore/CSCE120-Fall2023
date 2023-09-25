#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    int z = -99;
    iss >> z;
    cout << "z: " << z << endl;
    cout << "iss.good(): " << boolalpha << iss.good() << endl;
    cout << "iss.eof(): " << boolalpha << iss.eof() << endl;
    cout << "iss.bad(): " << boolalpha << iss.bad() << endl;
    cout << "iss.fail(): " << boolalpha << iss.fail() << endl; 
    double y = 0;
    iss >> y;
    cout << "y: " << y << endl; 
}