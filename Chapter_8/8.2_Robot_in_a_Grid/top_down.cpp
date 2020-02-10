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

struct Point {
public:
    int x;
    int y;

    Point(int row, int col) : x(row), y(col) {}
};

bool getPath(vector<vector<bool>> &maze, int row, int col, vector<Point*> &path, unordered_set<Point*> &failedPoints) {
    if (row < 0 || col < 0 || !maze[row][col]) {
        return false;
    }

    Point* p = new Point(row, col);
    if (failedPoints.find(p) != failedPoints.end()) {
        return false;
    }

    bool isOrigin = (row == 0 && col == 0);

    if (isOrigin || getPath(maze, row - 1, col, path, failedPoints) || getPath(maze, row, col - 1, path, failedPoints)) {
        path.push_back(p);
        return true;
    }

    return false;
}

vector<Point*> getPath(vector<vector<bool>> &maze) {
    vector<Point*> res;
    if (maze.empty() || maze[0].empty()) {
        return res;
    }
    unordered_set<Point*> failedPoints;
    if (getPath(maze, (int)maze.size() - 1, (int)maze[0].size() - 1, res, failedPoints)) {
        return res;
    } else {
        return {};
    }
}

int main() {
    vector<vector<bool>> maze{{true, true, true, true, true},
                              {true, false, true, true, true,},
                              {true, true, false, false, true},
                              {true, true, true, true, true}};
    vector<Point*> path = getPath(maze);
    if (path.empty()) {
        cout << "No path found." << endl;
    } else {
        for (Point* p : path) {
            cout << p->x << " " << p->y << endl;
        }
    }

    return 0;
}