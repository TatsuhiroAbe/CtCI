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

int getCharNumber(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a';
    } else if (c >= 'A' && c <= 'Z') {
        return c - 'A';
    } else {
        return -1;
    }
}

vector<int> buildFrequencyTable(string s) {
    vector<int> table(int('z') - int('a') + 1);
    for (char c : s) {
        int x = getCharNumber(c);
        if (x != -1) {
            table[x]++;
        }
    }
    return table;
}

bool checkMaxOneOdd(vector<int> &table) {
    bool findOdd = false;
    for (int count : table) {
        if (count % 2 == 1) {
            if (findOdd) {
                return false;
            }
            findOdd = true;
        }
    }
    return true;
}

bool isPermutationOfPalindrome(string s) {
    vector<int> table = buildFrequencyTable(s);
    return checkMaxOneOdd(table);
}

int main() {
    string s = "Tact Coa";
    cout << isPermutationOfPalindrome(s) << endl; //true
    return 0;
}