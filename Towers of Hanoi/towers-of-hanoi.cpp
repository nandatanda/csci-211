#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> tower[3];   // The three towers {A, B, C} represented as an array of 3 vectors.
  int n;                  // The number of rings we are given to solve.
  int candidate = 1;      // The next ring we should move. The smallest ring that was not just moved. Starts at 1.
  int moves = 0;          // The number of moves we have made so far.
  int from = 0;           // The tower we will move the next ring from. Starts at the first tower, index 0.
  int to, near, far;

  // Get the number of rings to solve from the user.
  cout << "Please enter the number of rings to move: ";
  cin >> n;
  cout << endl;

  // Place all the rings, plus a larger 'ring' (size n + 1) that helps us make comparisons, on tower A.
  // Initialize towers B and C by placing our safety 'ring' on each. These larger rings act as a floor.
  for (int i = n + 1; i >= 1; i--)
  {
    tower[0].push_back(i);
  }
  tower[1].push_back(n + 1);
  tower[2].push_back(n + 1);

  // Determine the starting positions of the towers based on the number of rings.
  // If there are an even number of rings, the empty tower is tower 2 (B).
  // Otherwise, the empty tower is tower 1 (B).
  if (n % 2 == 0)
  {
    near = 2;
    far = 1;
  }
  else
  {
    near = 1;
    far = 2;
  }

  to = near;

  // Move the rings until all of the rings are on tower 2 (B).
  while (tower[1].size() < n + 1)
  {
    // Print the move that we are making.
    cout << ++moves << ":\t";
    cout << char(from + 'A') << " -> " << char(to + 'A') << "\t";
    cout << "(Ring " << candidate << ")\n";

    // Move the ring to the new tower.
    tower[to].push_back(tower[from].back());
    tower[from].pop_back();

    // Determine which tower to move the next ring from based on the position of the candidate ring.
    if (tower[(to + 1) % 3].back() < tower[(to + 2) % 3].back())
    {
      from = (to + 1) % 3;
    }
    else
    {
      from = (to + 2) % 3;
    }

    // Update the candidate ring to be the top ring on the tower that we just moved a ring from.
    candidate = tower[from].back();

    // Determine which tower to move the candidate ring to based on the position of the other towers.
    if (tower[(from + near) % 3].back() > candidate)
    {
      to = (from + near) % 3;
    }
    else
    {
      to = (from + far) % 3;
    }
  }

  return 0;
}