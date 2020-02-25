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


enum Piece {
    Empty, Red, Blue
};

int convertBoardToInt(vector<vector<Piece>> &board) {
    int sum = 0;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            int value = board[i][j];
            sum = 3 * sum + value;
        }
    }
    return sum;
}

int main() {
    vector<vector<Piece>> board{{Piece::Empty, Piece::Empty, Piece::Red},
                                {Piece::Empty, Piece::Red, Piece::Empty},
                                {Piece::Blue, Piece::Blue, Piece::Blue}};
    int v = convertBoardToInt(board);
    cout << v << endl;
}
