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

bool hasWonRow(vector<vector<Piece>> &board, int row) {
    for (int c = 1; c < board[row].size(); c++) {
        if (board[row][c] != board[row][0]) {
            return false;
        }
    }
    return true;
}

bool hasWonColumn(vector<vector<Piece>> &board, int column) {
    for (int r = 1; r < board.size(); r++) {
        if (board[r][column] != board[0][column]) {
            return false;
        }
    }
    return true;
}

bool hasWonDiagonal(vector<vector<Piece>> &board, int direction) {
    int row = 0;
    int column = direction == 1 ? 0 : (int)board.size() - 1;
    Piece first = board[0][column];
    for (int i = 0; i < board.size(); i++) {
        if (board[row][column] != first) {
            return false;
        }
        row += 1;
        column += direction;
    }
    return true;
}

Piece hasWon(vector<vector<Piece>> &board, int row, int column) {
    if (board.empty() || board[0].empty()) {
        return Piece::Empty;
    }

    Piece piece = board[row][column];
    if (piece == Piece::Empty) {
        return Piece::Empty;
    }

    if (hasWonRow(board, row) || hasWonColumn(board, column)) {
        return piece;
    }

    if (row == column && hasWonDiagonal(board, 1)) {
        return piece;
    }

    if (row == (board.size() - column - 1) && hasWonDiagonal(board, -1)) {
        return piece;
    }

    return Piece::Empty;
}

int main() {
    vector<vector<Piece>> board{{Piece::Empty, Piece::Empty, Piece::Red},
                                {Piece::Empty, Piece::Red, Piece::Empty},
                                {Piece::Blue, Piece::Blue, Piece::Blue}};
    cout << hasWon(board, 2, 2) << endl; // 2 (Blue)
    return 0;
}
