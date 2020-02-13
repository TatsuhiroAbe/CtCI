#include <iostream>
#include <fstream>
#include <istream>
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


void findOpenNumber(string filename) {
    long long numberOfInts = (long long)INT32_MAX + 1;
    vector< bitset<8> > bitField(numberOfInts / 8);

    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        int n = stoi(line);
        bitField[n / 8] |= 1 << (n % 8);
    }

    for (int i = 0; i < bitField.size(); i++) {
        for (int j = 0; j < 8; j++) {
            if (!bitField[i][j]) {
                cout << i * 8 + j << endl;
                return;
            }
        }
    }
}

int main() {
    findOpenNumber("input.txt");
}