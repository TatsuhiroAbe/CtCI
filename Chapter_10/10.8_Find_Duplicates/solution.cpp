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


void checkDuplicates(vector<int> &array) {
    vector<bitset<8>> bs(1 << 10);

    for (int n : array) {
        int n0 = n - 1;
        if (bs[n0 / 8][n0 % 8]) {
            cout << n << endl;
        } else {
            bs[n0 / 8] |= 1 << (n0 % 8);
        }
    }
}

int main() {
    vector<int> array{1, 2, 3, 3, 4, 5, 6, 6, 7, 8, 9};
    checkDuplicates(array);
    return 0;
}