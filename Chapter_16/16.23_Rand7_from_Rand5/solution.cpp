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
#include <random>

using namespace std;

int rand5() {
    random_device r;
    default_random_engine e1(r());
    uniform_int_distribution<int> uniform_dist(0, 4);
    return uniform_dist(e1);
}

int rand7() {
    while (true) {
        int num = 5 * rand5() + rand5();
        if (num < 21) {
            return num % 7;
        }
    }
}

int main() {
    for (int i = 0; i < 7; i++) {
        cout << rand7() << endl;
    }
}