#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

int countWays(int n, vector<int> &memo) {
    if (n < 0) {
        return 0;
    } else if (n == 0) {
        return 1;
    } else if (memo[n] > -1) {
        return memo[n];
    } else {
        memo[n] = countWays(n - 1, memo) + countWays(n - 2, memo) + countWays(n - 3, memo);
        return memo[n];
    }
}

int countWays2(int n) {
    if (n <= 2) {
        return n;
    }

    vector<int> dp(n + 1);
    dp[0] = 1, dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;

    vector<int> memo(n + 1, -1);
    cout << countWays(n, memo) << endl;
    cout << countWays2(n) << endl;

    return 0;
}