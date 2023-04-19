/*
  Question:
    https://venus.cs.qc.cuny.edu/~waxman/211/stable%20marriage%20using%20backtrack%20assignment.pdf
  References:
    https://repl.it/@CerverizzoE/StableMarriage-iterative-for-StudentUse
*/
#include <iostream>
using namespace std;

void printMatching(int q[]){
    /*Fill-in this section*/
}
  
bool ok(int q[], int col){  

    //mp = man's preference; wp = women's preference
    //mp[i][j] gives man i's ranking of woman j
    //lower value implies higher ranking
    int mp[3][3] = {{0,2,1},   //man 0 likes woman 0 the most and woman 1 the least.
                    {0,2,1},
                    {1,2,0}};   

    int wp[3][3] = {{2,1,0},
                    {0,1,2},
                    {2,0,1}};

    //cm = a currently assigned man
    //cw = a currently assigned woman
    //nm = new man
    //nw = new woman
    //nm and nw are the proposed pair to add to the match

    int cm, cw, nm, nw;

    nm = col;
    nw = q[col];

    for (int i = 0; i < col; i++)
        /*Fill-in*/

    /*
       Check the new pair (new man, new woman) against each existing pair consisting of
       (current man, current woman) to see if the new pair would make the match unstable.
    */
    for (cm = 0; /*Fill-in*/) {
        cw = q[cm];
        //Lower value implies a higher preference

        //   a. if the current man prefers the new woman to his partner and
        //   b. if the new woman prefers the current man to her partner, reject
        if(/*Fill-in*/ 
        && /*Fill-in*/) return false;

        //   c. if the new man prefers the current woman to his partner and
        //   d. if the current woman prefers the new man to her partner, reject
        if(/*Fill-in*/
        && /*Fill-in*/) return false;
    }

    return true; //since the pair nm & nw do not introduce an instability
}

int main() {

    //Start with the first male
    int newMan = 0;
    int q[3] = {0};
    // While we have not backtracked beyond the first male:
    while (/*Fill-in*/){

        // If all the people have been matched, 
        if(/*Fill-in*/){
            printMatching(q);// print 
            // backtrack
            /*Fill-in 2 lines*/
        }
        // If all the available women are matched already
        else if (/*Fill-in*/){
            q[newMan] = 0;//reset new woman to starting value
            //backtrack
            /*Fill-in 2 lines*/
        }
        //check if the q is stable
        else if(/*Fill-in*/){
            newMan++;// move to the next man
        }
        else{
            // pair the man with the next available woman
            /*Fill-in*/
        }
    }
    return 0;
}
