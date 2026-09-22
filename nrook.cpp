#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<string>& board, int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'R')
            return false;
    }
    return true;
}

bool solve(int row, vector<string>& board, int n) {
    if (row == n)
        return true;
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'R';
            if (solve(row + 1, board, n))
                return true;
            board[row][col] = '.';
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<string> board(n, string(n, '.'));
    if (solve(0, board, n)) {
        for (auto row : board)
            cout << row << endl;
    } else {
        cout << "No solution";
    }
    return 0;
}