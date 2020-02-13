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

int binarySearch(vector<int> &nums, int target, int left, int right) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == -1 || target < nums[mid]) {
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int search(vector<int> &listy, int target) {
    int index = 1;
    while (listy[index] != -1 && listy[index] < target) {
        index *= 2;
    }
    return binarySearch(listy, target, index / 2, index);
}

int main() {
    vector<int> listy(1000, -1);
    vector<int> values{1, 2, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 16, 18};
    for (int i = 0; i < values.size(); i++) listy[i] = values[i];

    cout << search(listy, 10) << endl; // 7

    return 0;
}