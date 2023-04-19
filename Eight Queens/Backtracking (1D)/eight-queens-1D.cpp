// Ali Elayni
// Eight Queens in 1D - CS 211 (Waxman)

#include <iostream>
using namespace std;


void printChessboard(int arr[8]);


int main()
{
    int col = 0;
    int solutionCount = 0;
    int board[8] = {0};

    /*     Starting board:
       [1] 1  1  1  1  1  1  1
        0  0  0  0  0  0  0  0
        0  0  0  0  0  0  0  0
        0  0  0  0  0  0  0  0
        0  0  0  0  0  0  0  0
        0  0  0  0  0  0  0  0
        0  0  0  0  0  0  0  0
        0  0  0  0  0  0  0  0  */

nextColumn:
    // move cursor to next column
    // if we leave the board going right, print the current solution
    // reset to the top of the row (off the board)
    ++col;
    if (col == 8)
        goto print;
    board[col] = -1;

nextRow:
    // move cursor to next row
    // if we leave the board going down, backtrack to another possible solution
    ++board[col];
    if (board[col] == 8)
        goto backtrack;
    
    // check if a queen placed here would be threatened on a row or diagonal
    // if a queen would be threatened in this square, go to the next row
    for (int i = 0; i < col; ++i)
        if (board[col] == board[i] || col - i == abs(board[col] - board[i]))
            goto nextRow;

    // if not, leave the value in this index alone and go to the next column
    goto nextColumn;

backtrack:
    // move cursor to previous column
    // if we leave the board going left, all solutions are exhausted
    --col;
    if (col < 0)
        return 0;
    
    // attempt to place the queen in the next row
    goto nextRow;

print:
    cout << "Solution # " << ++solutionCount << endl;
    printChessboard(board);
    cout << endl;

    // retrace steps to find next solution
    goto backtrack;
}


void printChessboard(int arr[8])
{
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if (arr[col] == row) {
                cout << "1  ";
            }
            else {
                cout << "0  ";
            }
        }
        cout << endl;
    }
}