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

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s == t;
}

int main() {
    cout << isPermutation("god", "dog") << endl; //. true;
    cout << isPermutation("god", "dot") << endl; // false;
    return 0;
}