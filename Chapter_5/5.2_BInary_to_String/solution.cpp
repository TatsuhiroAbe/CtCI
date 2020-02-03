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

string printBinary(double num) {
    if (num >= 1 || num <= 0) {
        return "ERROR";
    }

    string binary;
    binary.push_back('.');
    while (num > 0) {
        if (binary.size() >= 32) {
            return "ERROR";
        }

        double r = num * 2;
        if (r >= 1) {
            binary.push_back('1');
            num = r - 1;
        } else {
            binary.push_back('0');
            num = r;
        }
    }
    return binary;
}

int main() {
    for (int i = 0; i < 1000; i++) {
        double num = (double)i / 1000;
        string b = printBinary(num);
        if (b != "ERROR") {
            cout << b << endl;
        }
    }
    return 0;
}