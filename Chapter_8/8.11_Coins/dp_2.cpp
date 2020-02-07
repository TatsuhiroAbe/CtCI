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
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 0; i < denominations.size(); i++) {
        int amount = denominations[i];
        for (int j = amount; j <= n; j++) {
            dp[j] += dp[j - amount];
        }
    }
    return dp[n];
}

int main() {
    cout << makeChange(10) << endl;
    return 0;
}