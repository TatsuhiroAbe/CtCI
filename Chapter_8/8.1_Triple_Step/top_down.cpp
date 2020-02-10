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

int countWays(int n, vector<int> &memo) {
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    if (memo[n] > -1) {
        return memo[n];
    }

    int res = countWays(n - 1, memo) + countWays(n - 2, memo) + countWays(n - 3, memo);
    return memo[n] = res;
}

int main() {
    int n = 8;
    vector<int> memo(n + 1, -1);
    cout << countWays(n, memo) << endl; // 81
    return 0;
}