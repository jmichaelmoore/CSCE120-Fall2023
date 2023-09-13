#include <iostream>

using std::cin, std::cout, std::endl;

void doubleVal(unsigned int ary[], unsigned int size, unsigned int max) {
    // throw an exception if any value becomes larger than max
    for (unsigned int i = 0; i < size; ++i) {
        ary[i] *= 2;
        if (ary[i] > max) {
            // throw exception
        }
    }
}

void printAry(unsigned int ary[], unsigned int size) {
    for (unsigned int i = 0; i < size; ++i) {
        cout << ary[i] << " ";
    }
    cout << endl;
}

int main() {
    const int size = 5;
    unsigned int ary[size] = {1, 2, 3, 4, 5};
    cout << "ary before doubleVal: " << endl;
    printAry(ary, size);
    doubleVal(ary, size, 6);
    cout << "ary after doubleVal: " << endl;
    printAry(ary, size);
}