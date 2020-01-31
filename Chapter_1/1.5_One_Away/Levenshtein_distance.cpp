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

bool oneEditAway(string s, string t) {
    int n = (int)s.size();
    int m = (int)t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT32_MAX));
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int i = 0; i <= m; i++) dp[0][i] = i;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (s[i - 1] != t[j - 1]));
        }
    }
    return dp[n][m] <= 1;
}

int main() {
    cout << oneEditAway("pale", "ple") << endl; // true
    cout << oneEditAway("pales", "pale") << endl; // true;
    cout << oneEditAway("pale", "bale") << endl; // true
    cout << oneEditAway("pale", "bae") << endl; //false
    return 0;
}