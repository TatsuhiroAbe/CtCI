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


int **my2DAlloc(int rows, int cols) {
    int i;
    int header = rows * sizeof(int*);
    int data = rows * cols * sizeof(int);
    int **rowptr = (int**)malloc(header + data);
    if (rowptr == nullptr) {
        return nullptr;
    }

    int *buf = (int*) (rowptr + rows);
    for (int i = 0; i < rows; i++) {
        rowptr[i] = buf + i * cols;
    }
    return rowptr;
}
