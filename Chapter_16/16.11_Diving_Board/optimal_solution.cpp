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


unordered_set<int> allLength(int k, int shorter, int longer) {
    unordered_set<int> lengths;
    for (int nShorter = 0; nShorter <= k; nShorter++) {
        int nLonger = k - nShorter;
        int length = nShorter * shorter + nLonger * longer;
        lengths.insert(length);
    }
    return lengths;
}

int main() {
    unordered_set<int> lengths = allLength(12, 2, 3);
    cout << lengths.size() << endl; // 13
    return 0;
}
