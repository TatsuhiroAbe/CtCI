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


int swapOddEvenBits(int x) {
    return ((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1);
}

int main() {
    int a = 156;
    cout << bitset<8>(a) << endl; // 10011100
    int swapped = swapOddEvenBits(a);
    cout << bitset<8>(swapped) << endl; // 01101100
    return 0;
}