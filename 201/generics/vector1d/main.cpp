#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

template <typename T>
void printVector(vector<T> v) {
    for (size_t i = 0; i<v.size(); ++i) {
        cout << v.at(i) << endl;
    }
}

int main() {
    vector<int> v;
    cout << "v.size(): " << v.size() << endl;
    cout << "v.capacity(): " << v.capacity() << endl;
    for (size_t i=0; i<100; ++i) {
        v.push_back(i+1);
        cout << "i: " << i << endl;
        cout << "v.size(): " << v.size() << endl;
        cout << "v.capacity(): " << v.capacity() << endl;
    }

    printVector(v);

    vector<char> c;
    cout << "c.size(): " << c.size() << endl;
    cout << "c.capacity(): " << c.capacity() << endl;
    for (size_t i=0; i<100; ++i) {
        c.push_back(('A'+i)%'Z');
        cout << "i: " << i << endl;
        cout << "c.size(): " << c.size() << endl;
        cout << "c.capacity(): " << c.capacity() << endl;
    }

    printVector(c);

    vector<int*> z;

    for (size_t i=0; i<10; ++i) {
        z.push_back( new int(i) );
    }

    printVector(z);

    for (size_t i=0; i<z.size(); ++i) {
        delete z.at(i);
    }


}