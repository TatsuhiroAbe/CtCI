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


typedef pair<int, int> P;

class Ant {
public:
    P position;
    // 0: right, 1: down, 2: left, 3: up
    int orientation;

    Ant() {
        position = make_pair(0, 0);
        orientation = 0;
    }

    void turn(bool clockWise) {
        if (orientation == 0) {
            orientation = clockWise ? 1 : 3;
        } else if (orientation == 1) {
            orientation = clockWise ? 2 : 0;
        } else if (orientation == 2) {
            orientation = clockWise ? 3 : 1;
        } else {
            orientation = clockWise ? 0 : 2;
        }
    }

    void move() {
        if (orientation == 0) {
            position.second++;
        } else if (orientation == 1) {
            position.first++;
        } else if (orientation == 2) {
            position.second--;
        } else {
            position.first--;
        }
    }

    void adjustPosition(int shiftRow, int shiftCol) {
        position.first += shiftRow;
        position.second += shiftCol;
    }

};

class Grid {
public:
    // false: white, true: black
    vector<vector<bool>> grid;
    Ant ant;

    Grid() {
        grid.emplace_back(vector<bool>(1, false));
        ant = Ant();
    }

    void copyWithShift(
            vector<vector<bool>> &oldGrid,
            vector<vector<bool>> &newGrid,
            int shiftRow, int shiftCol) {
        for (int i = 0; i < oldGrid.size(); i++) {
            for (int j = 0; j < oldGrid[0].size(); j++) {
                newGrid[i + shiftRow][j + shiftCol] = oldGrid[i][j];
            }
        }
    }

    void ensureFit(P position) {
        int shiftRow = 0;
        int shiftCol = 0;

        int numRows = (int)grid.size();
        if (position.first < 0) {
            shiftRow = numRows;
            numRows *= 2;
        } else if (position.first >= numRows) {
            numRows *= 2;
        }

        int numCols = (int)grid[0].size();
        if (position.second < 0) {
            shiftCol = numCols;
            numCols *= 2;
        } else if (position.second >= numCols) {
            numCols *= 2;
        }

        if (numRows != grid.size() || numCols != grid[0].size()) {
            vector<vector<bool>> newGrid(numRows, vector<bool>(numCols));
            copyWithShift(grid, newGrid, shiftRow, shiftCol);
            ant.adjustPosition(shiftRow, shiftCol);
            grid = newGrid;
        }
    }

    void flip(P position) {
        int row = position.first;
        int col = position.second;
        grid[row][col] = !grid[row][col];
    }

    void move() {
        bool clockWise = !grid[ant.position.first][ant.position.second];
        ant.turn(clockWise);
        flip(ant.position);
        ant.move();
        ensureFit(ant.position);
    }

    string toString() {
        int firstActiveRow = (int)grid.size();
        int firstActiveCol = (int)grid[0].size();
        int lastActiveRow = 0;
        int lastActiveCol = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] || (ant.position.first == i && ant.position.second == j)) {
                    firstActiveRow = min(firstActiveRow, i);
                    firstActiveCol = min(firstActiveCol, j);
                    lastActiveRow = max(lastActiveRow, i);
                    lastActiveCol = max(lastActiveCol, j);
                }
            }
        }

        string res;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (ant.position.first == i && ant.position.second == j) {
                    res += 'A';
                } else if (grid[i][j]) {
                    res += 'X';
                } else {
                    res += '_';
                }
            }
            res += '\n';
        }
        return res;
    }
};

int main() {
    int k = 10;

    Grid grid;
    for (int i = 0; i < k; i++) {
        grid.move();
    }

    cout << grid.toString() << endl;

    return 0;
}