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

const vector<int> dr{1, 0, -1, 0};
const vector<int> dc{0, 1, 0, -1};

void helper(vector<vector<int>> &screen, int r, int c, int oldColor, int newColor) {
    screen[r][c] = newColor;

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nr < screen.size() && nc >= 0 && nc < screen[0].size() && screen[nr][nc] == oldColor) {
            helper(screen, nr, nc, oldColor, newColor);
        }
    }
}

void paintFill(vector<vector<int>> &screen, int r, int c, int newColor) {
    if (screen[r][c] == newColor) {
        return;
    }
    helper(screen, r, c, screen[r][c], newColor);
}

int main() {
    vector<vector<int>> screen{{0, 0, 0, 1, 0, 0, 0, 0},
                               {0, 0, 1, 0, 1, 0, 0, 0},
                               {0, 1, 0, 0, 1, 1, 0, 0},
                               {0, 1, 0, 0, 0, 0, 1, 0},
                               {0, 0, 1, 0, 1, 1, 0, 0},
                               {0, 0, 0, 1, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0}};
    paintFill(screen, 3, 3, 2);

    /*
        0 0 0 1 0 0 0 0 
        0 0 1 2 1 0 0 0 
        0 1 2 2 1 1 0 0 
        0 1 2 2 2 2 1 0 
        0 0 1 2 1 1 0 0 
        0 0 0 1 0 0 0 0 
        0 0 0 0 0 0 0 0 
    */

    for (int i = 0; i < screen.size(); i++) {
        for (int j = 0; j < screen[0].size(); j++) {
            cout << screen[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}