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


void helper(int n, vector<string> &parens, int left, int right, string temp) {
    if (left < right) {
        return;
    }

    if (left == n && right == n) {
        parens.push_back(temp);
        return;
    }

    if (left < n) {
        helper(n, parens, left + 1, right, temp + '(');
    }
    if (right < n) {
        helper(n, parens, left, right + 1, temp + ')');
    }
}

vector<string> generateParens(int n) {
    vector<string> parens;
    string temp;
    helper(n, parens, 0, 0, temp);
    return parens;
}

int main() {
    vector<string> parens = generateParens(3);
    for (int i = 0; i < parens.size(); i++) {
        cout << parens[i] << endl;
    }
    return 0;
}