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

bool charToBool(char c) {
    return c == '1';
}

int countEval(string s, bool result, unordered_map<string, int> &memo) {
    if (s.empty()) {
        return 0;
    }
    int n = (int)s.size();
    if (n == 1) {
        return charToBool(s[0]) == result;
    }
    if (memo.find(to_string(result) + s) != memo.end()) {
        return memo[to_string(result) + s];
    }

    int ways = 0;
    for (int i = 1; i < n; i += 2) {
        char c = s[i];
        string left = s.substr(0, i);
        string right = s.substr(i + 1, n - i - 1);

        int leftTrue = countEval(left, true, memo);
        int leftFalse = countEval(left, false, memo);
        int rightTrue = countEval(right, true, memo);
        int rightFalse = countEval(right, false, memo);
        int total = (leftTrue + leftFalse) * (rightTrue + rightFalse);

        int totalTrue = 0;
        if (c == '^') {
            totalTrue = leftTrue * rightFalse + leftFalse * rightTrue;
        } else if (c == '&') {
            totalTrue = leftTrue * rightTrue;
        } else if (c == '|') {
            totalTrue = leftTrue * rightTrue + leftTrue * rightFalse + leftFalse * rightTrue;
        }

        int subWays = result ? totalTrue : total - totalTrue;
        ways += subWays;
    }

    return ways;
}

int main() {
    unordered_map<string, int> memo1;
    unordered_map<string, int> memo2;
    cout << countEval("1^0|0|1", false, memo1) << endl; // 2
    cout << countEval("0&0&0&1^1|0", true, memo2) << endl; // 10
    return 0;
}