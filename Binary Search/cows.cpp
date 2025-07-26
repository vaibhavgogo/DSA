#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool find(vector<int> &stalls, int cows, int minDist)
    {
        cows--; // first cow already placed at first stall
        int prev = 0;

        for (int i = 1; i < stalls.size(); i++)
        {
            if ((stalls[i] - stalls[prev]) >= minDist)
            {
                prev = i;
                cows--;
            }
            if (cows == 0)
                return true;
        }

        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k)
    {
        sort(stalls.begin(), stalls.end());

        int low = 1; // min possible distance between cows
        int high = stalls[stalls.size() - 1] - stalls[0];
        int result = 0;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (find(stalls, k, mid))
            {
                result = mid; // mid is a possible answer
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;

    // Example input
    vector<int> stalls = {1, 2, 8, 4, 9};
    int cows = 3;

    int result = sol.aggressiveCows(stalls, cows);
    cout << "Maximum minimum distance between cows: " << result << endl;

    return 0;
}
