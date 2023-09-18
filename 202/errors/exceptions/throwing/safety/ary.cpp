#include <iostream>

using std::cin, std::cout, std::endl;

void doubleVal(unsigned int ary[], unsigned int size, unsigned int max) {
    // throw an exception if any value becomes larger than max
    for (unsigned int i = 0; i < size; ++i) {
        if (ary[i]*2 > max) {
            // throw exception
            std::string errMsg;
            errMsg = "Created value (" + std::to_string(ary[i]*2) + ") which is greater than the max of " + std::to_string(max);
            throw std::runtime_error(errMsg);
        }
    }
    for (unsigned int i = 0; i < size; ++i) {
        ary[i] *= 2;
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
    try {
        doubleVal(ary, size, 6);
    }
    catch (std::runtime_error &e) {
        cout << e.what() << endl;
    }
    cout << "ary after doubleVal: " << endl;
    printAry(ary, size);
}