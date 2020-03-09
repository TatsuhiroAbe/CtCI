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


pair<int, int> findUnsortedSequence(vector<int> &array) {
    int n = (int)array.size();
    int left = 0, right = n - 1;
    while (left < right && array[left] <= array[left + 1]) {
        left++;
    }
    if (left == right) {
        pair<int, int> res(-1, -1);
        return res;
    }
    while (left < right && array[right - 1] <= array[right]) {
        right--;
    }

    int maxNum = INT32_MIN, minNum = INT32_MAX;
    for (int i = left; i <= right; i++) {
        maxNum = max(maxNum, array[i]);
        minNum = min(minNum, array[i]);
    }

    while (left >= 0 && array[left] > minNum) left--;
    while (right < n && array[right] < maxNum) right++;

    pair<int, int> res(left + 1, right - 1);
    return res;
}

int main() {
    vector<int> array{1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};
    pair<int, int> indices = findUnsortedSequence(array);

    cout << "left: " << indices.first << " right: " << indices.second << endl;
    return 0;
}