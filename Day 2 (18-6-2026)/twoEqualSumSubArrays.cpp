#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canSplit(vector<int> &arr)
    {
        // find total Sum
        int totalSum = 0;
        int n = arr.size();
        for (int i = 0; i <= n - 1; i++)
        {
            totalSum += arr[i];
        }

        // find 1st subarray sum
        int prefix = 0;
        for (int i = 0; i <= n - 2; i++)
        {
            prefix += arr[i];
            int remaining = totalSum - prefix; // second subarray sum
            if (prefix == remaining)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{

    vector<int> arr = {4,3,2,1};
    Solution obj;
    cout << obj.canSplit(arr);
    return 0;
}
