#include <iostream>

using std::cin, std::cout, std::endl;

int main() {
    const unsigned int num = 3;
    //cin >> num;
    int ary[num];
    //int ary[num] = {}; // initialize all to 0
    //int ary[num] = {1, 2, 3};
    //int ary[] = {1, 2, 3}; // not useful
    for (unsigned int i = 0; i < num; ++i) {
        ary[i] = i + 1;
    }
    for (int i = 0; i <= num; ++i) {
        cout << ary[i] << " ";
    } 
    cout << endl;
}