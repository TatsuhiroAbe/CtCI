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

void replaceSpace(string &s, int trueLength) {
    int spaceCount = 0;
    for (int i = 0; i < trueLength; i++) {
        if (s[i] == ' ') spaceCount++;
    }

    int index = spaceCount * 2 + trueLength;
    for (int i = trueLength - 1; i >= 0; i--) {
        if (s[i] == ' ') {
            s[index - 1] = '0';
            s[index - 2] = '2';
            s[index - 3] = '%';
            index -= 3;
        } else {
            s[index - 1] = s[i];
            index--;
        }
    }
}

int main() {
    string s = "Mr John Smith    ";
    replaceSpace(s, 13);
    cout << s << endl; // "Mr%20John%20Smith"
    return 0;
}