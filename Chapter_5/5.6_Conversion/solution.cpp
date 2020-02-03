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

int bitSwapRequired(int a, int b) {
    int count = 0;
    for (int c = a ^ b; c != 0; c &= (c - 1)) {
        count++;
    }
    return count;
}

int main() {
    int a = 29, b = 15;
    cout << "a = " << a << " : " << bitset<5>(a) << endl;
    cout << "b = " << b << " : " << bitset<5>(b) << endl;
    cout << bitSwapRequired(a, b) << endl;
    return 0;
}