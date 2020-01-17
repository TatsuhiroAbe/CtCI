#include <bits/stdc++.h>
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