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


int findSmallestDifference(vector<int> &array1, vector<int> &array2) {
    sort(array1.begin(), array1.end());
    sort(array2.begin(), array2.end());
    int p1 = 0;
    int p2 = 0;
    int res = INT32_MAX;
    while (p1 < array1.size() && p2 < array2.size()) {
        int diff = abs(array1[p1] - array2[p2]);
        res = min(res, diff);

        if (array1[p1] < array2[p2]) {
            p1++;
        } else {
            p2++;
        }
    }
    return res;
}

int main() {
    vector<int> array1{1, 3, 15, 11, 2};
    vector<int> array2{23, 127, 234, 19, 8};
    cout << findSmallestDifference(array1, array2) << endl; // 3
    return 0;
}