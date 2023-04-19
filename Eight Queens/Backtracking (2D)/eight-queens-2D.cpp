// Ali Elayni
// Eight Queens in 2D - CS 211 (Waxman)

#include <iostream>
using namespace std;


void printChessboard(int arr[][8]);


int main()
{
    int row = 0;
    int col = 0;
    int solutionCount = 0;
    int board[8][8] = {1};

    /*     Starting board:
       [1] 0  0  0  0  0  0  0
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
    row = -1;

nextRow:
    // move cursor to next row
    // if we leave the board going down, backtrack to another possible solution
    ++row;
    if (row == 8)
        goto backtrack;

    // check if a queen placed here would be threatened on a row
    // if a queen would be threatened in this square, go to the next row
    for (int i = 0; i < col; ++i)
        if (board[row][i] == 1)
            goto nextRow;

    // check if the queen would be threatened on an upward diagonal
    for (int i = 1; row - i >= 0 && col - i >= 0; ++i)
        if (board[row - i][col - i] == 1)
            goto nextRow;

    // check if the queen would be threatened on a downward diagonal
    for (int i = 1; row + i < 8 && col - i >= 0; ++i)
        if (board[row + i][col - i] == 1)
            goto nextRow;

    // if not, place a queen in the current square and go to the next column
    board[row][col] = 1;
    goto nextColumn;

backtrack:
    // move cursor to previous column
    // if we leave the board going left, all solutions are exhausted
    --col;
    if (col < 0)
        return 0;
    
    // find and remove the previous queen
    for (row = 0; board[row][col] != 1; ++row);
    board[row][col] = 0;

    // attempt to place the queen in the next row
    goto nextRow;
    
print:
    // print and label the latest solution
    cout << "Solution # " << ++solutionCount << endl;
    printChessboard(board);
    cout << endl;

    // retrace steps to find next solution
    goto backtrack;
}


void printChessboard(int arr[][8])
{
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            cout << arr[row][col] << "  ";
        }
        cout << endl;
    }
}