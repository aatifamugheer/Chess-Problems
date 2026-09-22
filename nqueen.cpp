#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<string>& board, int row, int col, int n) {

    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q')
            return false;

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q')
            return false;

    return true;
}

void solve(int row, vector<string>& board, int n) {

    if (row == n) {
        for (auto x : board)
            cout << x << endl;

        cout << endl;
        return;
    }

    for (int col = 0; col < n; col++) {

        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solve(row + 1, board, n);
            board[row][col] = '.';
        }
    }
}

int main() {

    int n;
    cin >> n;
    vector<string> board(n, string(n, '.'));
    solve(0, board, n);
    return 0;
}