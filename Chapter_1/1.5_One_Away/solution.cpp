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

bool oneEditReplace(string s1, string s2) {
    bool findDifference = false;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            if (findDifference) {
                return false;
            }
            findDifference = true;
        }
    }
    return true;
}

bool oneEditInsertion(string s1, string s2) {
    int index1 = 0, index2 = 0;
    while (index1 < s1.size() && index2 < s2.size()) {
        if (s1[index1] != s2[index2]) {
            if (index1 != index2) {
                return false;
            }
            index2++;
        } else {
            index1++;
            index2++;
        }
    }
    return true;
}

bool oneEditAway(string s1, string s2) {
    if (s1.size() == s2.size()) {
        return oneEditReplace(s1, s2);
    } else if (s1.size() + 1 == s2.size()) {
        return oneEditInsertion(s1, s2);
    } else if (s1.size() - 1 == s2.size()) {
        return oneEditInsertion(s2, s1);
    } else {
        return false;
    }
}

int main() {
    cout << oneEditAway("pale", "ple") << endl; // true
    cout << oneEditAway("pales", "pale") << endl; // true;
    cout << oneEditAway("pale", "bale") << endl; // true
    cout << oneEditAway("pale", "bae") << endl; //false
    return 0;
}