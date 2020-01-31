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

string compress(string s) {
    string compressed;
    char pre = s[0];
    int count = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == pre) {
            count++;
        } else {
            compressed += pre;
            compressed += to_string(count);
            count = 1;
        }
        pre = s[i];
    }
    compressed += pre;
    compressed += to_string(count);

    return compressed.size() < s.size() ? compressed : s;
}

int main() {
    cout << compress("aabcccccaaa") << endl; // a2b1c5a3
    return 0;
}