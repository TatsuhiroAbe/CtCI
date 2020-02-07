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


class Box {
public:
    int width;
    int height;
    int depth;

    Box(int w, int h, int d) {
        width = w;
        height = h;
        depth = d;
    }

    bool canBeAbove(Box b) {
        return (width < b.width && height < b.height && depth < b.depth);
    }
};

static bool compare(Box a, Box b) {
    if (a.height != b.height) {
        return a.height > b.height;
    } else {
        return a.width > b.width;
    }
}

int helper(vector<Box> &boxes, int index, vector<int> &memo) {
    if (index < boxes.size() && memo[index] > 0) {
        return memo[index];
    }

    Box bottom = boxes[index];
    int maxHeight = 0;
    for (int i = index + 1; i < boxes.size(); i++) {
        if (boxes[i].canBeAbove(bottom)) {
            int height = helper(boxes, i, memo);
            maxHeight += height;
        }
    }
    maxHeight += bottom.height;
    return memo[index] = maxHeight;
}

int createStack(vector<Box> &boxes) {
    sort(boxes.begin(), boxes.end(), compare);
    int maxHeight = 0;
    vector<int> memo(boxes.size());
    for (int i = 0; i < boxes.size(); i++) {
        int height = helper(boxes, i, memo);
        maxHeight = max(maxHeight, height);
    }
    return maxHeight;
}

int main() {
    vector<Box> boxes{Box(6, 4, 4),
                      Box(8, 6, 2),
                      Box(5, 3, 3),
                      Box(7, 8, 3),
                      Box(4, 2, 2),
                      Box(9, 7, 3)};

    cout << createStack(boxes) << endl;

    return 0;
}