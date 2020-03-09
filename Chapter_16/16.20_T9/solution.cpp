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


const vector<string> letters{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void getValidWord(string number, unordered_set<string> wordList, int i, string temp, vector<string> &result) {
    if (i == number.size()) {
        if (wordList.find(temp) != wordList.end()) {
            result.push_back(temp);
        }
        return;
    }

    int digit = number[i] - '0';
    for (int j = 0; j < letters[digit].size(); j++) {
        getValidWord(number, wordList, i + 1, temp + letters[digit][j], result);
    }
}

vector<string> getValidT9Words(string number, unordered_set<string> &wordList) {
    vector<string> res;
    getValidWord(number, wordList, 0, "", res);
    return res;
}

int main() {
    unordered_set<string> wordList;
    wordList.insert("used");
    wordList.insert("tree");

    vector<string> res = getValidT9Words("8733", wordList);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }

    return 0;
}