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


int getTarget(vector<int> &A, vector<int> &B) {
    int sumA = 0;
    int sumB = 0;
    for (int a : A) sumA += a;
    for (int b : B) sumB += b;

    if ((sumA - sumB) % 2) {
        return INT32_MAX;
    } else {
        return (sumA - sumB) / 2;
    }
}

unordered_set<int> getContents(vector<int> &array) {
    unordered_set<int> contents;
    for (int n : array) {
        contents.insert(n);
    }
    return contents;
}

pair<int, int> findSwapValue(vector<int> &A, vector<int> &B) {
    int target = getTarget(A, B);
    if (target == INT32_MAX) {
        return make_pair(-1, -1);
    }

    unordered_set<int> contents = getContents(B);
    for (int a : A) {
        int b = a - target;
        if (contents.find(b) != contents.end()) {
            return make_pair(a, b);
        }
    }

    return make_pair(-1, -1);
}

int main() {
    vector<int> A{4, 1, 2, 1, 1, 2};
    vector<int> B{3, 6, 3, 3};

    pair<int, int> p = findSwapValue(A, B);

    cout << p.first << " " << p.second << endl; // 4 6

    return 0;
}