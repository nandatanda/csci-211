#include <iostream>
using namespace std;


void print(int matches[])
{
    cout << "Man\tWoman" << endl;
    for (int man = 0; man < 3; man++)
    {
        int woman = matches[man];
        
        cout << man + 1 << "\t" << woman + 1 << endl;
    }
    cout << endl;
}

bool ok(int pairings[], int column)
{
    int mens_preferences[3][3] =   {0, 2, 1,
                                    0, 2, 1,
                                    1, 2, 0};

    int womens_preferences[3][3] = {2, 1, 0,
                                    0, 1, 2,
                                    2, 0, 1};

    int current_man, current_woman;
    int new_man, new_woman;
    bool current_man_prefers_new_woman, current_woman_prefers_new_man;
    bool new_man_prefers_current_woman, new_woman_prefers_current_man;

    new_man = column;
    new_woman = pairings[column];

    for (int current_man = 0; current_man < column; current_man++)
    {
        current_woman = pairings[current_man];

        current_man_prefers_new_woman = (mens_preferences[current_man][new_woman] < mens_preferences[current_man][current_woman]);
        new_woman_prefers_current_man = (womens_preferences[new_woman][current_man] < womens_preferences[new_woman][new_man]);

        new_man_prefers_current_woman = (mens_preferences[new_man][current_woman] < mens_preferences[new_man][new_woman]);
        current_woman_prefers_new_man = (womens_preferences[current_woman][new_man] < womens_preferences[current_woman][current_man]);

        if (current_woman == new_woman)
            return false;
        if (current_man_prefers_new_woman && new_woman_prefers_current_man)
            return false;
        if (new_man_prefers_current_woman && current_woman_prefers_new_man)
            return false;
    }
    return true;
}

int main()
{
    // Start with the first man and all pairings set to the first woman
    int new_man = 0;
    int pairings[3] = {0};

    // Until we backtrack beyond the first man:
    while (new_man >= 0)
    {
        // If all the people have been matched, print the matches and backtrack
        if(new_man == 3)
        {
            print(pairings);
            new_man--;
            if(new_man >= 0)
                pairings[new_man]++;
        }
        // If all the available women are matched already, reset new woman to its starting value and backtrack
        else if (pairings[new_man] == 3)
        {
            pairings[new_man] = 0;
            new_man--;
            if(new_man >= 0)
                pairings[new_man]++;
        }
        // If the new pairing is acceptable, move to the next man
        else if(ok(pairings, new_man))
        {
            new_man++;
        }
        // Otherwise, pair the man with the next available woman
        else
        {
            pairings[new_man]++;
        }
    }
    return 0;
}