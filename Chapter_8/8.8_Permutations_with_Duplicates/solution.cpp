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

void helper(string s, vector<string> &perms, string &temp, vector<bool> &used) {
    if (temp.size() == s.size()) {
        perms.push_back(temp);
        return;
    }

    for (int i = 0; i < (int)s.size(); i++) {
        if (used[i] || (i > 0 && s[i] == s[i - 1] && used[i - 1])) continue;
        used[i] = true;
        temp.push_back(s[i]);
        helper(s, perms, temp, used);
        used[i] = false;
        temp.pop_back();
    }
}

vector<string> getPerms(string s) {
    vector<string> res;
    string temp;
    vector<bool> used((int)s.size(), false);
    sort(s.begin(), s.end());
    helper(s, res, temp, used);
    return res;
}

int main() {
    vector<string> permutations = getPerms("aabc");
    for (int i = 0; i < permutations.size(); i++) {
        cout << permutations[i] << endl;
    }
    return 0;
}