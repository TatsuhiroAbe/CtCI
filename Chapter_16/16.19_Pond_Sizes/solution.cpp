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


int computeSize(vector<vector<int>> &land, int row, int col) {
    land[row][col] = -1;

    int res = 1;
    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            int nr = row + dr;
            int nc = col + dc;
            if (nr >= 0 && nr < land.size() && nc >= 0 && nc < land[0].size() && land[nr][nc] == 0) {
                res += computeSize(land, nr, nc);
            }
        }
    }

    return res;
}

vector<int> computePondSizes(vector<vector<int>> &land) {
    vector<int> res;
    int h = (int)land.size();
    int w = (int)land[0].size();

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (land[i][j] == 0) {
                res.push_back(computeSize(land, i, j));
            }
        }
    }

    return res;
}

int main() {
    vector<vector<int>> land{{0, 2, 1, 0},
                             {0, 1, 0, 1},
                             {1, 1, 0, 1},
                             {0, 1, 0, 1}};
    vector<int> sizes = computePondSizes(land);
    for (int size : sizes) {
        cout << size << " ";
    }
    cout << endl;

    return 0;
}