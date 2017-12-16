#include <iostream>
using namespace std;

int totalResheniq = 0;

bool is_valid_place(int** board, int n, int row, int col)
{
    return (board[row][col] == -1);
}

void marker(int** board, int n, int row, int col, char dir, int markerInt)
{
    if(row < 0 || col < 0 || row >= n || col >= n)
        return;

    auto mark = [&](){ if(is_valid_place(board, n, row, col)) {board[row][col] = markerInt;} };
    switch (dir)
    {
        case 'r': mark(); marker(board, n, row, col+1, dir, markerInt); break;
        case 'd': mark(); marker(board, n, row+1, col, dir, markerInt); break;
        case 'm': mark(); marker(board, n, row+1, col+1, dir, markerInt); break;
        case 'n': mark(); marker(board, n, row-1, col-1, dir, markerInt); break;
        case 'o': mark(); marker(board, n, row-1, col+1, dir, markerInt); break;
        case 'p': mark(); marker(board, n, row+1, col-1, dir, markerInt); break;
    default: break;
    }
}

void mark_queen(int** board, int n, int row, int col)
{
    marker(board, n, row, 0, 'r', row);
    marker(board, n, 0, col, 'd', row);
    marker(board, n, row, col, 'm', row);
    marker(board, n, row, col, 'n', row);
    marker(board, n, row, col, 'o', row);
    marker(board, n, row, col, 'p', row);
}

void unmark_queen(int** board, int n, int row, int col)
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(board[i][j] == row)
                board[i][j] = -1;
}

void n_queens_solver(int** board, int n, int row, int col)
{
    if(row >= n)
    {
        ++totalResheniq;
        return;
    }

    for(int i=0; i<n; i++)
    {
        if(is_valid_place(board, n, row, i))
        {
            mark_queen(board, n, row, i);
            n_queens_solver(board, n, row + 1, 0);
            unmark_queen(board, n, row, i);
        }
    }
}

void n_queens(int n)
{
    int** board = new int* [n];

    for(int i=0; i<n; i++)
    {
        board[i] = new int[n];

        for(int j=0; j<n; j++)
            board[i][j] = -1;
    }

    n_queens_solver(board, n, 0, 0);
}

int main()
{
    int n; cin >> n;
    n_queens(n);

    cout << totalResheniq << endl;

    return 0;
}
