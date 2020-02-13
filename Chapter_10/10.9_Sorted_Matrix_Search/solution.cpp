#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <cstddef>

using namespace std;

bool searchElement(vector<vector<int>> &matrix, int elem) {
    int row = 0;
    int col = (int)matrix[0].size() - 1;
    while (row < (int)matrix.size() && col >= 0) {
        if (matrix[row][col] == elem) {
            return true;
        } else if (matrix[row][col] < elem) {
            row++;
        } else {
            col--;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> matrix{{15, 20, 40, 85},
                               {20, 35, 80, 95},
                               {30, 55, 95, 105},
                               {40, 80, 100, 120}};
    cout << searchElement(matrix, 35) << endl; // true
    cout << searchElement(matrix, 25) << endl; // false
    return 0;
}