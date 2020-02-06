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

    int mid = (left + right) / 2;
    if (array[mid] == mid) {
        return mid;
    } else if (array[mid] < mid) {
        return helper(array, mid + 1, right);
    } else {
        return helper(array, left, mid - 1);
    }
}

int findMagicIndex(vector<int> &array) {
    return helper(array, 0, (int)array.size() - 1);
}

int main() {
    vector<int> array{-40, -20, -1, 1, 2, 3, 5, 7, 9, 12, 13};
    cout << findMagicIndex(array) << endl;
    return 0;
}