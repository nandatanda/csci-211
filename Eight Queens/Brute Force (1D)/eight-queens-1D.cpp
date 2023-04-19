// Ali Elayni
// "Dumb" Eight Queens in 1D - CS 211 (Waxman)

#include <iostream>
using namespace std;


void printChessboard(int arr[8]);

bool isSolution(int arr[8]);

int main()
{
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


    for (int i0 = 0; i0 < 8; ++i0) {
        for (int i1 = 0; i1 < 8; ++i1) {
            for (int i2 = 0; i2 < 8; ++i2) {
                for (int i3 = 0; i3 < 8; ++i3) {
                    for (int i4 = 0; i4 < 8; ++i4) {
                        for (int i5 = 0; i5 < 8; ++i5) {
                            for (int i6 = 0; i6 < 8; ++i6) {
                                for (int i7 = 0; i7 < 8; ++i7) {
                                    board[0] = i0;
                                    board[1] = i1;
                                    board[2] = i2;
                                    board[3] = i3;
                                    board[4] = i4;
                                    board[5] = i5;
                                    board[6] = i6;
                                    board[7] = i7;

                                    if (isSolution(board)) {
                                        cout << "Solution # " << ++solutionCount << endl;
                                        printChessboard(board);
                                        cout << endl;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

bool isSolution(int arr[8])
{
    for (int col = 7; col > 0; --col)
    {
        for (int i = 0; i < col; ++i)
        {
            if (arr[col] == arr[i] || (col - i) == abs(arr[col] - arr[i]))
            {
                return false;
            }
        }
    }
    return true;
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