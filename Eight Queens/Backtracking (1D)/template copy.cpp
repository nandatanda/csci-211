#include <iostream>
#include <cmath>
using namespace std;

bool ok(int board[], int column);
void print(int board[]);
void backtrack(int &column);

int main() {
    int board[8]={0};
    int column = 0;
    //put the queen in the upper left square
    //board[0] = 0; //b[0][0] = 1 in 2D version

    // if we backtrack beyond the first column, we are done
    while(column >= 0) {

        // if we have moved beyond the last column
        if(column > 7) {
            // print the board
            print(board);
            // backtrack
            backtrack(column);

        }
        // If we have moved beyond the last row 
        else if(board[col] > 7) {
            // reset queen
            board[col] = 0;
            // backtrack
            col--;
            if (col == -1) return 0;
            board[col]++;

        }

        // Check if the placed queen is ok.
        else if(ok(board, col)){
            // move to next column if ok
            
        } 
        else{
            // move to next row if not ok
        }
    }
    return 0;
}

void backtrack(int &column)
{
    // move cursor to previous column
    // if we leave the board going left, all solutions are exhausted
    column--;
    if (column < 0)
        exit(0);
}

bool ok(int board[], int column)
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