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

void helper(vector<int> &nums, int start, vector<vector<int>> &subsets, vector<int> &temp) {
    subsets.push_back(temp);
    if (start == nums.size()) {
        return;
    }

    for (int i = start; i < nums.size(); i++) {
        temp.push_back(nums[i]);
        helper(nums, i + 1, subsets, temp);
        temp.pop_back();
    }
}

vector<vector<int>> getSubsets(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> temp;
    helper(nums, 0, res, temp);
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