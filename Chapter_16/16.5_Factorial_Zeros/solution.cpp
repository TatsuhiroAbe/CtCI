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


int countFactZeros(int num) {
    int count = 0;
    for (int i = 5; i <= num; i *= 5) {
        count += num / i;
    }
    return count;
}

int main() {
    int n = 10;
    cout << countFactZeros(n) << endl; // 2 (3628800)
    return 0;
}