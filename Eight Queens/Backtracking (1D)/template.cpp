#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c);
void print(int q[]);

int main() {
    int board[8]={0}, col = 0;
    //put the queen in the upper left square
    //board[0] = 0; //b[0][0] = 1 in 2D version

    while( /* */){// if we backtrack beyond the first col, we are done

        // if we have moved beyond the last column
        if(/* */){
            // print the board
            // backtrack

        }
        // If we have moved beyond the last row 
        else if(/* */){
            // reset queen
            // backtrack

        }

        // Check if the placed queen is ok.
        else if(/* */){
            // move to next column if ok
        } 
        else{
            // move to next row if not ok
        }
    }
    return 0;
}