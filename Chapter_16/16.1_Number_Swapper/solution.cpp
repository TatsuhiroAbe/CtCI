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

void mySwap(int &a, int &b) {
    a = b - a;
    b = b - a;
    a = a + b;
}

int main() {
    int a = 2, b = 3;
    cout << "a = " << a << " b = " << b << endl;

    mySwap(a, b);
    cout << "a = " << a << " b = " << b << endl;
    return 0;
}
