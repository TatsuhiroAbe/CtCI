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


class Solution {
public:
    int minProduct(int a, int b) {
        int smaller = (a < b) ? a : b;
        int bigger = (a < b) ? b : a;
        vector<int> memo(smaller + 1);
        return helper(smaller, bigger, memo);
    }

    int helper(int smaller, int bigger, vector<int> &memo) {
        if (smaller == 0) {
            return 0;
        }
        if (smaller == 1) {
            return bigger;
        }
        if (memo[smaller] > 0) {
            return memo[smaller];
        }

        int s = smaller >> 1;
        int side1 = helper(s, bigger, memo);
        int side2 = side1;
        if (smaller % 2 == 1) {
            side2 = helper(s + 1, bigger, memo);
        }

        return memo[smaller] = side1 + side2;
    }
};

int main() {
    Solution solution = Solution();

    cout << solution.minProduct(17, 23) << endl;

    return 0;
}