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
#include <cstddef>

using namespace std;


void sortStrings(vector<string> &array) {
    int n = (int)array.size();
    if (n < 2) {
        return;
    }

    unordered_map<string, list<string>> hash;
    for (string s : array) {
        string key = s;
        sort(key.begin(), key.end());
        hash[key].push_back(s);
    }

    int index = 0;
    for (pair<string, list<string>> p : hash) {
        list<string> l = p.second;
        for (string s : l) {
            array[index++] = s;
        }
    }
}

int main() {
    vector<string> array{"apple", "banana", "carrot", "ele", "duck", "papel", "tarroc", "cudk", "eel", "lee"};
    sortStrings(array);
    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << endl;
    }
    return 0;
}