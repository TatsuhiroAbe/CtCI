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
using namespace std;

void setZeroes(vector<vector<int>> &matrix) {
    int h = (int)matrix.size();
    int w = (int)matrix[0].size();
    vector<bool> row(h);
    vector<bool> col(w);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (matrix[i][j] == 0) {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    for (int i = 0; i < h; i++) {
        if (row[i]) {
            for (int j = 0; j < w; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    for (int j = 0; j < w; j++) {
        if (col[j]) {
            for (int i = 0; i < h; i++) {
                matrix[i][j] = 0;
            }
        }
    }
}

int main() {
    vector<vector<int>> matrix{{0, 1, 2, 0},
                               {3, 4, 5, 2},
                               {1, 3, 1, 5}};
    setZeroes(matrix);

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    /*
         0 0 0 0
         0 4 5 0
         0 3 1 0
    */

    return 0;
}