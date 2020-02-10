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


int makeChange(int n) {
    const vector<int> denominations{1, 5, 10, 25};
    vector<vector<int>> dp(denominations.size() + 1, vector<int>(n + 1));
    for (int i = 1; i <= denominations.size(); i++) {
        dp[i][0] = 1;
    }

    for (int i = 0; i < denominations.size(); i++) {
        for (int j = 1; j <= n; j++) {
            dp[i + 1][j] += dp[i][j];

            int amount = denominations[i];
            if (j >= amount) {
                dp[i + 1][j] += dp[i + 1][j - amount];
            }
        }
    }

    return dp[denominations.size()][n];
}

int main() {
    cout << makeChange(10) << endl;
    return 0;
}