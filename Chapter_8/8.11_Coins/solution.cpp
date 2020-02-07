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

int helper(int amount, vector<int> &denominations, int index, vector<vector<int>> &memo) {
    if (index == denominations.size() - 1) {
        return 1;
    }
    if (memo[index][amount] > 0) {
        return memo[index][amount];
    }

    int res = 0;
    for (int i = 0; i * denominations[index] <= amount; i++) {
        int remaining = amount - i * denominations[index];
        res += helper(remaining, denominations, index + 1, memo);
    }
    return memo[index][amount] = res;
}

int makeChange(int n) {
    vector<int> denominations{25, 10, 5, 1};
    vector<vector<int>> memo(denominations.size(), vector<int>(n + 1, 0));
    return helper(n, denominations, 0, memo);
}

int main() {
    cout << makeChange(10) << endl;
    return 0;
}