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

// assume the character set is ASCII
bool isUnique(string s) {
    if (s.size() > 128) {
        return false;
    }
    vector<bool> exists(128);
    for (char c : s) {
        if (exists[int(c)]) return false;
        exists[int(c)] = true;
    }

    return true;
}

int main() {
    cout << isUnique("abcde") << endl; // true;
    cout << isUnique("abcda") << endl; // false;
    return 0;
}