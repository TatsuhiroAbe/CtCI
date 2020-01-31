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

bool isPermutation(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }

    vector<int> count(128);
    for (char c : s) count[int(c)]++;

    for (char c : t) {
        count[int(c)]--;
        if (count[int(c)] < 0) {
            return false;
        }
    }

    return true;
}

int main() {
    cout << isPermutation("god", "dog") << endl; //. true;
    cout << isPermutation("god", "dot") << endl; // false;
    return 0;
}