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

const int GRID_SIZE = 8;

bool checkValid(vector<int> &columns, int row1, int col1) {
    for (int row2 = 0; row2 < row1; row2++) {
        int col2 = columns[row2];

        // Check if rows have a queen in the same column
        if (col1 == col2) {
            return false;
        }

        // Check diagonals
        int colDistance = abs(col2 - col1);
        int rowDistance = row1 - row2;
        if (colDistance == rowDistance) {
            return false;
        }
    }
    return true;
}

void placeQueens(int row, vector<int> &columns, vector<vector<int>> &results) {
    if (row == GRID_SIZE) {
        results.push_back(columns);
    }

    for (int col = 0; col < GRID_SIZE; col++) {
        if (checkValid(columns, row, col)) {
            columns[row] = col;
            placeQueens(row + 1, columns, results);
        }
    }
}

int main() {
    vector<vector<int>> results;
    vector<int> columns(GRID_SIZE, -1);
    placeQueens(0, columns, results);

    cout << "There are " << results.size() << " solved boards." << endl;
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (j == results[0][i]) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    return 0;
}