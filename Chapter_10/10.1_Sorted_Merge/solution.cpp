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


void merge(vector<int> &a, vector<int> &b, int lastA, int lastB) {
    int indexA = lastA - 1;
    int indexB = lastB - 1;
    int mergedIndex = lastA + lastB - 1;

    while (indexB >= 0) {
        if (a[indexA] > b[indexB]) {
            a[mergedIndex] = a[indexA];
            indexA--;
        } else {
            a[mergedIndex] = b[indexB];
            indexB--;
        }
        mergedIndex--;
    }
}

int main() {
    vector<int> a(20), b(10);
    vector<int> valuesA{1, 2, 4, 6, 7, 8, 10};
    vector<int> valuesB{2, 3, 5, 6, 11};
    for (int i = 0; i < valuesA.size(); i++) a[i] = valuesA[i];
    for (int i = 0; i < valuesB.size(); i++) b[i] = valuesB[i];

    merge(a, b, (int)valuesA.size(), (int)valuesB.size());

    for (int i = 0; i < valuesA.size() + valuesB.size(); i++) {
        cout << a[i] << " ";
    }

    return 0;
}