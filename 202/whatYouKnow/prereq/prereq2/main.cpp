#include <iostream>

using std::cout, std::cin, std::endl; // need C++ or higher for this line, otherwise put each on separate line with semicolons at end

int main() {
    double sum = 0;
    double numCnt = 0;
    double num = 0;
    do {
        cin >> num;
        if (num >= 0) {
            sum += num; // sum = sum + 1;
            numCnt++;
        }
    } while (num != -1);
    
    cout << "average: ";
    if (numCnt == 0) {
        cout << "Empty list";
    } else {
        cout << sum/numCnt;
    }
    cout << endl;
}