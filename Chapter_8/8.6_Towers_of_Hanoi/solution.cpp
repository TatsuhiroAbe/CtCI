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

void towerOdHanoi(int n, string source, string destination, string buffer) {
    if (n > 0) {
        towerOdHanoi(n - 1, source, buffer, destination);
        cout << "Move disk " << n << " from " << source << " to " << destination << endl;
        towerOdHanoi(n - 1, buffer, destination, source);
    }
}

int main() {
    int n = 4;
    towerOdHanoi(n, "Source", "Destination", "Buffer");

    return 0;
}