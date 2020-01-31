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


bool isSubstring(string s1, string s2) {
    int n = (int)s1.size();
    int m = (int)s2.size();
    for (int i = 0; i < n - m + 1; i++) {
        if (s1[i] == s2[0]) {
            string t = s1.substr(i, m);
            if (t == s2) {
                return true;
            }
        }
    }
    return false;
}

bool isRotation(string s1, string s2) {
    int n = (int)s1.size();
    int m = (int)s2.size();
    if (n != m || n == 0 || m == 0) {
        return false;
    }

    s1 += s1;
    return isSubstring(s1, s2);
}

int main() {
    cout << isRotation("waterbottle", "erbottlewat") << endl; // true
    return 0;
}