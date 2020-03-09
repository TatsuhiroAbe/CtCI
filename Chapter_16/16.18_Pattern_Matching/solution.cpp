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


int countOf(string pattern , char c) {
    int res = 0;
    for (int i = 0; i < pattern.size(); i++) {
        if (pattern[i] == c) {
            res++;
        }
    }
    return res;
}

string buildFromPattern(string pattern, string main, string alt) {
    string res;
    char first = pattern[0];
    for (int i = 0; i < pattern.size(); i++) {
        res += pattern[i] == first ? main : alt;
    }
    return res;
}

bool doesMatch(string pattern, string value) {
    char mainChar = pattern[0];
    char altChar = mainChar == 'a' ? 'b' : 'a';
    int size = (int)value.size();

    int countOfMain = countOf(pattern, mainChar);
    int countOfAlt = countOf(pattern, altChar);
    int firstAlt = (int)pattern.find(altChar);
    int maxMainSize = size / countOfMain;

    for (int mainSize = 0; mainSize <= maxMainSize; mainSize++) {
        int remainingLength = size - countOfMain * mainSize;
        string main = value.substr(0, mainSize);
        if (countOfAlt == 0 || remainingLength % countOfAlt == 0) {
            int altIndex = firstAlt * mainSize;
            int altSize = countOfAlt == 0 ? 0 : remainingLength / countOfAlt;

            string alt = countOfAlt == 0 ? "" : value.substr(altIndex, altSize);
            if (buildFromPattern(pattern, main, alt) == value) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    vector<pair<string, string>> pairs{pair<string, string>("aabab", "catcatgocatgo"),
                                       pair<string, string>("ababb", "backbatbackbatbat"),
                                       pair<string, string>("abab", "backsbatbackbats"),};

    for (int i = 0; i < pairs.size(); i++) {
        string pattern = pairs[i].first;
        string value = pairs[i].second;

        cout << doesMatch(pattern, value) << endl;
    }

    return 0;
}