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

void helper(string s, vector<string> &perms, string &temp) {
    if (temp.size() == s.size()) {
        perms.push_back(temp);
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        if (temp.find(s[i]) != string::npos) continue;
        temp.push_back(s[i]);
        helper(s, perms, temp);
        temp.pop_back();
    }
}

vector<string> getPerms(string s) {
    vector<string> res;
    string temp;
    helper(s, res, temp);
    return res;
}

int main() {
    vector<string> permutations = getPerms("abcde");
    for (int i = 0; i < permutations.size(); i++) {
        cout << permutations[i] << endl;
    }
    return 0;
}