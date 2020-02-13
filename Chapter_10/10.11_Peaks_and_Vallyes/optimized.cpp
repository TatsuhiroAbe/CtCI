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


int getMaxIndex(vector<int> &array, int a, int b, int c) {
    int len = (int)array.size();
    int aValue = a < len ? array[a] : INT32_MIN;
    int bValue = b < len ? array[b] : INT32_MIN;
    int cValue = c < len ? array[c] : INT32_MIN;

    int maxValue = max({aValue, bValue, cValue});
    if (maxValue == aValue) return a;
    else if (maxValue == bValue) return b;
    else return c;
}

void sortValleyPeak(vector<int> &array) {
    for (int i = 1; i < array.size(); i += 2) {
        int maxIndex = getMaxIndex(array, i - 1, i, i + 1);
        if (maxIndex != i) {
            swap(array[i], array[maxIndex]);
        }
    }
}

int main() {
    vector<int> array{5, 3, 1, 2, 3};
    sortValleyPeak(array);
    for (int n : array) {
        cout << n << " ";
    }
    return 0;
}