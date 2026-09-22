#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<string>& board, int row, int col, int n) {
    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0; i--, j++) {
        if (board[i][j] == 'B')
            return false;
    }
    for (int i = row - 1, j = col + 1;
         i >= 0 && j < n; i--, j--) {
        if (board[i][j] == 'B')
            return false;
    }

    return true;
}

bool solve(int row, int count, vector<string>& board, int n) {
    if (count == n)
        return true;
    if (row == n)
        return false;
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'B';
            if (solve(row + 1, count + 1, board, n))
                return true;
            board[row][col] = '.';
        }
    }
    return solve(row + 1, count, board, n);
}

int main() {
    int n;
    cin >> n;
    vector<string> board(n, string(n, '.'));
    if (solve(0, 0, board, n)) {
        for (auto row : board)
            cout << row << endl;
    }

    return 0;
}