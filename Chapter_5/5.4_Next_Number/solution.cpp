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

int getNext(int n) {
    int c = n;
    int c0 = 0;
    int c1 = 0;
    while (((c & 1) == 0) && (c != 0)) {
        c0++;
        c >>= 1;
    }

    while ((c & 1) == 1) {
        c1++;
        c >>= 1;
    }

    if (c0 + c1 == 31 || c0 + c1 == 0) {
        return -1;
    }

    int p = c0 + c1;

    n |= (1 << p);

    // Clear all bits to the right of p
    n &= ~((1 << p) - 1);
    // Insert (c1 - 1) ones on the right
    n |= ((1 << (c1 - 1)) - 1);

    return n;
}

int getPrev(int n) {
    int c = n;
    int c0 = 0;
    int c1 = 0;
    while ((c & 1) == 1) {
        c1++;
        c >>= 1;
    }
    if (c == 0) return -1;

    while ((c & 1) == 0 && (c != 0)) {
        c0++;
        c >>= 1;
    }

    int p = c0 + c1;
    n &= ((~0) << (p + 1));

    int mask = (1 << (c1 + 1)) - 1;
    n |= mask << (c0 - 1);

    return n;
}

int main() {
    int n = 13948;
    cout << n << " : " << decimalToBinary(n) << endl; // 11011001111100
    int next = getNext(n);
    cout << next << " : " << decimalToBinary(next) << endl;
    int prev = getPrev(n);
    cout << prev << " : " << decimalToBinary(prev) << endl;
    return 0;
}