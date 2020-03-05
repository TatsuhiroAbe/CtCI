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


vector<pair<int, int>> printPairSums(vector<int> &array, int sum) {
    vector<pair<int, int>> res;
    unordered_map<int, int> hash;
    for (int x : array) {
        int complement = sum - x;
        if (hash[complement]) {
            res.push_back(make_pair(x, complement));
            hash[complement]--;
        } else {
            hash[x]++;
        }
    }
    return res;
}

int main() {
    vector<int> array{9, 3, 6, 5, 5, 7, -1, 13, 14, -2, 12, 0};
    vector<pair<int, int>> pairs = printPairSums(array, 12);
    for (pair<int, int> p : pairs) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}