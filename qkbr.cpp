#include <bits/stdc++.h>
using namespace std;

struct Piece {
    char type;
};

bool attacks(char p, int r1, int c1, int r2, int c2) {
    int dr = abs(r1 - r2);
    int dc = abs(c1 - c2);
    if (p == 'Q') {
        return r1 == r2 ||
               c1 == c2 ||
               dr == dc;
    }
    if (p == 'R') {
        return r1 == r2 ||
               c1 == c2;
    }
    if (p == 'B') {
        return dr == dc;
    }
    if (p == 'N') {
        return (dr == 2 && dc == 1) ||
               (dr == 1 && dc == 2);
    }

    return false;
}
bool isSafe(vector<string>& board,
            vector<pair<int,int>>& pos,
            vector<char>& pieces,
            int row, int col,
            char current) {

    for (int i = 0; i < pos.size(); i++) {

        int r = pos[i].first;
        int c = pos[i].second;
        char previous = pieces[i];
        if (attacks(current, row, col, r, c))
            return false;
        if (attacks(previous, r, c, row, col))
            return false;
    }

    return true;
}
bool solve(int index,
           vector<char>& pieces,
           vector<string>& board,
           vector<pair<int,int>>& pos,
           int n) {
    if (index == pieces.size())
        return true;
    char current = pieces[index];
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (board[row][col] != '.')
                continue;
            if (isSafe(board, pos, pieces,
                       row, col, current)) {
                board[row][col] = current;
                pos.push_back({row, col});
                if (solve(index + 1,
                          pieces,
                          board,
                          pos,
                          n))
                    return true;
                pos.pop_back();
                board[row][col] = '.';
            }
        }
    }

    return false;
}

int main() {

    int n;
    cin >> n;

    vector<char> pieces = {'Q', 'N', 'B', 'R'};
    vector<string> board(n, string(n, '.'));
    vector<pair<int,int>> pos;
    if (solve(0, pieces, board, pos, n)) {
        for (auto row : board)
            cout << row << endl;
    } else {
        cout << "No solution";
    }
    return 0;
}