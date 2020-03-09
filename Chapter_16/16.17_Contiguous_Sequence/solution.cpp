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


int getMaxSum(vector<int> &array) {
    int res = 0;
    int sum = 0;
    for (int i = 0; i < array.size(); i++) {
        sum = max(sum + array[i], array[i]);
        res = max(res, sum);
    }
    return res;
}

int main() {
    vector<int> array{2, -8, 3, -2, 4, -10};

    cout << getMaxSum(array) << endl;

    return 0;
}