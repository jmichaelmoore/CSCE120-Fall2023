#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

void print2D(vector<vector<int>> v) {
    for (size_t row = 0; row<v.size(); ++row) {
        for (size_t col = 0; col<v.at(row).size(); ++col) {
            cout << v.at(row).at(col) << " ";
        }
        cout << endl;
    }
}

int main() {

    vector<vector<int>> v;

    for (size_t row=0; row<5; ++row) {
        vector<int> temp;
        v.push_back(temp);
        for (size_t col=0; col<4; ++col) {
            v.at(row).push_back(row+col+1);
        }
    }

    print2D(v);

    cout << endl;
    
    vector<vector<int>> z = {
        {1, 2, 3},
        {4, 5},
        {6, 7, 8, 9}
    };

    print2D(z);

}