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


namespace Operations {
    int negate(int a) {
        int neg = 0;
        int newSign = a < 0 ? 1 : -1;
        int delta = newSign;
        while (a != 0) {
            bool differentSign = (a + delta > 0) != (a > 0);
            if (a + delta != 0 && differentSign) {
                delta = newSign;
            }
            neg += delta;
            a += delta;
            delta += delta;
        }
        return neg;
    }

    int abs(int a) {
        if (a < 0) {
            return negate(a);
        } else {
            return a;
        }
    }

    int minus(int a, int b) {
        return a + negate(b);
    }

    int multiply(int a, int b) {
        if (a < b) {
            return multiply(b, a);
        }

        int sum = 0;
        for (int i = abs(b); i > 0; i = minus(i, 1)) {
            sum += a;
        }
        if (b < 0) {
            sum = negate(sum);
        }
        return sum;
    }

    int divide(int a, int b) {
        if (b == 0) {
            return -1;
        }

        int absa = abs(a);
        int absb = abs(b);

        int product = 0;
        int x = 0;
        while (product + absb <= absa) {
            product += absb;
            x++;
        }

        if ((a < 0 && b < 0) || (a > 0 && b > 0)) {
            return x;
        } else {
            return negate(x);
        }
    }
}


int main() {
    cout << Operations::minus(5, 2) << endl;
    cout << Operations::multiply(5, -4) << endl;
    cout << Operations::divide(20, -3) << endl;
    return 0;
}