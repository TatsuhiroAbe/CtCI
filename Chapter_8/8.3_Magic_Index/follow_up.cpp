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

int helper(vector<int> &array, int left, int right) {
    if (right < left) {
        return -1;
    }

    int middleIndex = (left + right) / 2;
    int middleValue = array[middleIndex];
    if (middleIndex == middleValue) {
        return middleIndex;
    }

    int leftIndex = min(middleIndex - 1, middleValue);
    int l = helper(array, left, leftIndex);
    if (l >= 0) {
        return l;
    }

    int rightIndex = max(middleIndex + 1, middleValue);
    int r = helper(array, rightIndex, right);

    return r;
}

int findMagicIndex(vector<int> &array) {
    return helper(array, 0, (int)array.size() - 1);
}

int main() {
    vector<int> array{-10, -5, 2, 2, 2, 3, 4, 7, 9, 12, 13};
    cout << findMagicIndex(array) << endl;
    return 0;
}