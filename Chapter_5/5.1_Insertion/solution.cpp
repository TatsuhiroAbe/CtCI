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

string decimalToBinary(int n) {
    string res;
    while (n > 0) {
        res = to_string(n % 2) + res;
        n /= 2;
    }
    return res;
}

int updateBits(int n, int m, int i, int j) {
    int allOnes = ~0;
    int left = allOnes << (j + 1);
    int right = ((1 << i) - 1);
    int mask = left | right;
    int n_cleared = n & mask;
    int m_shifted = m << i;
    return n_cleared | m_shifted;
}

int main() {
    int N = 1024;
    cout << decimalToBinary(N) << endl; // 10000000000
    int M = 19;
    cout << decimalToBinary(M) << endl; // 10011
    int updated = updateBits(N, M, 2, 6);
    cout << decimalToBinary(updated) << endl; // 10001001100
    return 0;
}