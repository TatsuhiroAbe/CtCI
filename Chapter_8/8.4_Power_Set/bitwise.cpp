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


vector<vector<int>> getSubsets(vector<int> &nums) {
    vector<vector<int>> res;
    int n = (int)nums.size();
    for (int i = 0; i < (1 << n); i++) {
        vector<int> subset;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                subset.push_back(nums[j]);
            }
        }
        res.push_back(subset);
    }
    return res;
}

int main() {
    vector<int> nums{1, 2, 3, 4, 5};
    vector<vector<int>> subsets = getSubsets(nums);
    for (int i = 0; i < subsets.size(); i++) {
        for (int n : subsets[i]) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}