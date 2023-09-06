#include <iostream>

using std::cin, std::cout, std::endl;

int main() {
    const unsigned int num = 3;
    //cin >> num;
    //int nums[num] = {}; // initialize all to zero
    // int nums[num] = {0};
    //int nums[num] = {1, 2, 3};
    //int nums[num] = {1}; // sets first element to 1 and rest to 0
    int a = 5;
    int b = 2;
    int nums[num];
    int k = 11;
    int j = 15;
    for (unsigned int i = 0; i < num; ++i) {
        nums[i] = i+1;
    }
    for (int i = 0; i <= num; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
}