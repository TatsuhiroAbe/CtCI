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


void getAllLength(int k, int total, int shorter, int longer, unordered_set<int> &lengths) {
    if (k == 0) {
        lengths.insert(total);
        return;
    }

    getAllLength(k - 1, total + shorter, shorter, longer, lengths);
    getAllLength(k - 1, total + longer, shorter, longer, lengths);
}

unordered_set<int> allLength(int k, int shorter, int longer) {
    unordered_set<int> lengths;
    getAllLength(k, 0, shorter, longer, lengths);
    return lengths;
}

int main() {
    unordered_set<int> lengths = allLength(12, 2, 3);
    cout << lengths.size() << endl; // 13
    return 0;
}
