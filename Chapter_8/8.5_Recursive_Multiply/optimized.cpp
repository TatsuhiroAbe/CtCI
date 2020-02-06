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

int helper(int smaller, int bigger) {
    if (smaller == 0) {
        return 0;
    }
    if (smaller == 1) {
        return bigger;
    }

    int s = smaller >> 1;
    int halfProduct = helper(s, bigger);

    if (smaller % 2 == 0) {
        return halfProduct + halfProduct;
    } else {
        return halfProduct + halfProduct + bigger;
    }
}

int minProduct(int a, int b) {
    int smaller = (a < b) ? a : b;
    int bigger = (a < b) ? b : a;
    return helper(smaller, bigger);
}

int main() {
    cout << minProduct(17, 23) << endl;

    return 0;
}