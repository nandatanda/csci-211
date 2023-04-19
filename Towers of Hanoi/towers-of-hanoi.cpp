#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> t[3];   // The three towers {A, B, C} represented as an array of 3 vectors.
    int n;              // The number of rings we are given to solve.
    int candidate = 1;  // The next ring we should move. The smallest ring that was not just moved. Starts at 1.
    int moves = 0;      // The number of moves we have made so far.
    int from = 0;       // The tower we will move the next ring from. Starts at the first tower, index 0.
    int to, near, far;

    // Get the number of rings to solve from the user.
    cout << "Please enter the number of rings to move: ";
    cin >> n;
    cout << endl;

    // Place all the rings, plus a larger 'ring' (size n + 1) that helps us make comparisons, on tower A.
    // Initialize towers B and C by placing our safety 'ring' on each. These larger rings act as a floor.
    for (int i = n + 1; i >= 1; i--) {t[0].push_back(i);}
    t[1].push_back(n+1);
    t[2].push_back(n+1);

    // Initialize towers and candidate
    if (n % 2 == 0) {near = 2;}
    else {near = 1;}

    to = near;

    while(t[1].size() < n+1) { // There are still rings to transfer to tower B = t[1]
      // Make moves (^ w ^)
    }
    return 0;
}