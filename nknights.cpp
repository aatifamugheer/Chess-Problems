#include <iostream>
using namespace std;

int n, k;
int board[10][10];

int rowMove[] = {2, 2, -2, -2, 1, 1, -1, -1};
int colMove[] = {1, -1, 1, -1, 2, -2, 2, -2};

bool isSafe(int row, int col)
{
    for (int i = 0; i < 8; i++)
    {
        int r = row + rowMove[i];
        int c = col + colMove[i];

        if (r >= 0 && r < n && c >= 0 && c < n)
        {
            if (board[r][c] == 1)
                return false;
        }
    }

    return true;
}
bool solve(int row, int col, int placed)
{
    if (placed == k)
        return true;
    if (row == n)
        return false;
    if (col == n)
        return solve(row + 1, 0, placed);
    if (isSafe(row, col))
    {
        board[row][col] = 1;
        if (solve(row, col + 1, placed + 1))
            return true;
        board[row][col] = 0;
    }
    return solve(row, col + 1, placed);
}

int main()
{
    cout << "Enter board size n: ";
    cin >> n;
    cout << "Enter number of knights k: ";
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }

    if (solve(0, 0, 0))
    {
        cout << "\nSolution:\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 1)
                    cout << "K ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "\nNo solution exists.\n";
    }
    return 0;
}