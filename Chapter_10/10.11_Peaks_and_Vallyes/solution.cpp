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


void sortValleyPeak(vector<int> &array) {
    sort(array.begin(), array.end());
    for (int i = 1; i < array.size(); i += 2) {
        swap(array[i], array[i - 1]);
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