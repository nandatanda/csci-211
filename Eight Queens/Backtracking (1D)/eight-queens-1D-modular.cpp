// Ali Elayni
// Eight Queens in 1D, No Goto Statements Allowed! - CS 211 (Waxman)

#include <iostream>
using namespace std;


void print(int board[])
{
    for (int row = 0; row < 8; ++row)
    {
        for (int column = 0; column < 8; ++column)
        {
            if (board[column] == row) {cout << "1  ";}
            else {cout << "0  ";}
        }
        cout << endl;
    }
}

bool isSafe(int board[], int column)
{
    for (int c = 0; c < column; ++c)
    {
        int dx = column - c;
        int dy = abs(board[column] - board[c]);

        if (board[column] == board[c] || dx == dy)
            return false;
    }
    return true;
}

void backtrack(int &column)
{
    // move cursor to previous column
    // if we leave the board going left, all solutions are exhausted
    column--;
    if (column < 0)
        exit(0);
}


int main()
{
    int column = 0;
    int solutionCount = 0;
    int board[8] = {0};
    bool backtracking = false;

    while (true)
    {
        // traverse the columns
        while (column < 8)
        {
            // reset to the top of the row (off the board) if not backtracking
            if (!backtracking) {board[column] = (-1);}
            backtracking = true;

            // traverse the rows
            while(board[column] < 8)
            {
                // move cursor to next row
                // if we leave the board going down, backtrack to another possible solution
                board[column]++;
                if (board[column] == 8)
                {
                    backtracking = true;
                    backtrack(column);
                    break;
                }
                // check if a queen placed here would be threatened on a row or diagonal
                // if a queen would be safe in this square, go to the next column
                if (isSafe(board, column))
                {
                    backtracking = false;
                    ++column;
                    break;
                }
            }
        }
        // if we leave the board going right, print the current solution
        // retrace steps (backtrack) to find next solution
        cout << "Solution # " << ++solutionCount << endl;
        print(board);
        cout << endl;
        backtracking = true;
        backtrack(column);
    }
}