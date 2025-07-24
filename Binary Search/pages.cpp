#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution
{
public:
    int find(vector<int> arr, int mid)
    {
        int sum = 0;
        int s = 1;
        for (int i = 0; i < arr.size(); i++)
        {
            if ((arr[i] + sum) <= mid)
            {
                sum += arr[i];
            }
            else
            {
                sum = arr[i];
                s++;
            }
        }
        return s;
    }
    int findPages(vector<int> &arr, int k)
    {
        // code here
        if (k > arr.size())
            return -1;
        auto low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            // int cnt+=sum(arr,mid);
            int s = find(arr, mid);
            if (s > k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
            // cout<<low<<" "<<high<<endl;
            // return low;
        }
        return low;
    }
};
int main()
{
    vector<int> books = {12, 34, 67, 90};
    int students = 2;

    Solution sol;
    int result = sol.findPages(books, students);

    if (result == -1)
        cout << "Not enough books for each student.\n";
    else
        cout << "Minimum number of pages: " << result << endl;

    return 0;
}