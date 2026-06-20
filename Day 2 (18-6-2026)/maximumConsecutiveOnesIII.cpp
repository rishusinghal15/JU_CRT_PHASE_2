#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int i = 0, j = 0;
        int zeroCount = 0;
        int maxOne = 0;

        while (j < nums.size())
        {
            if (nums[j] == 0)
            {
                zeroCount++;
            }

            while (zeroCount > k)
            {
                if (nums[i] == 0)
                {
                    zeroCount--;
                }
                i++;
            }
            maxOne = max(maxOne, j - i + 1);
            j++;
        }
        return maxOne;
    }
};

int main()
{

    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;

    Solution obj;
    cout << obj.longestOnes(nums, k);
    return 0;
}