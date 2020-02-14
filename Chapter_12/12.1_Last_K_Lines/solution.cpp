#include <iostream>
#include <fstream>
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


void printLastKLines(string filename, int K) {
    vector<string> L(K);
    int size = 0;

    ifstream file(filename);
    while (getline(file, L[size % K])) {
        size++;
    }

    int start = (size > K) ? size % K : 0;
    int count = min(K, size);
    for (int i = 0; i < count; i++) {
        cout << L[(start + i) % K] << endl;
    }
}

int main() {
    printLastKLines("input.txt", 3);
}