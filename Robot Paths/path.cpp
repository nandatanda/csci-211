#include <iostream>
using namespace std;

int solutions[5][5] = {0};

int path(int i, int j)
{
    // Base case
    if (i == 0 || j == 0)
    {
        return 1;
    }

    // Check memo
    if (solutions[i][j] != 0)
    {
        return solutions[i][j];
    }

    // Recursive call
    solutions[i][j] = path(i, j - 1) + path(i - 1, j);
    solutions[j][i] = solutions[i][j];
    return solutions[i][j];
}

int main()
{
    cout << path(3, 4);
}