#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int count = 0;
        int maxOne = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                count = 0;
            }
            else if (nums[i] == 1)
            {
                count++;
                maxOne = max(maxOne, count);
            }
        }
        return maxOne;
    }
};

int main()
{
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    Solution obj;
    cout << obj.findMaxConsecutiveOnes(nums);

    return 0;
}