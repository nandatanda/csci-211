#include <iostream>
using namespace std;

/*
1. Create the board
2. Generate a permutation
3. Check if that ordering is valid
4: Print the solution

*/

bool isSolution(int[8][8], int);

void printChessboard(int[8][8]);


int main() {
    // Create the board
    int board[8][8] = {0};
    
    // Generate the values
    for(int i0 = 0; i0 < 8; i0++) {
        for(int i1 = 0; i1 < 8; i1++) {
            for(int i2 = 0; i2 < 8; i2++) {
                for(int i3 = 0; i3 < 8; i3++) {
                    for(int i4 = 0; i4 < 8; i4++) {
                        for(int i5 = 0; i5 < 8; i5++) {
                            for(int i6 = 0; i6 < 8; i6++) {
                                for(int i7 = 0; i7 < 8; i7++) {
                                    board[i0][0] = 1;
                                    board[i1][1] = 1;
                                    board[i2][2] = 1;
                                    board[i3][3] = 1;
                                    board[i4][4] = 1;
                                    board[i5][5] = 1;
                                    board[i6][6] = 1;
                                    board[i7][7] = 1;
                                    
                                    /*
                                    Check if it's a solution
                                    if (isSolution(board)) {
                                    
                                    }
                                    */
                                    
                                    // Reset the board
                                    board[i0][0] = 0;
                                    
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printChessboard(board);
    return 0;
}

bool isSolution(int arr[8][8], int row) {
    return true;
}

void printChessboard(int arr[8][8]) {
    for (int a = 0; a < 8; a++) {
        for (int b = 0; b < 8; b++) {
            cout << arr[a][b] << " ";
        }
        cout << endl;
    }
}



