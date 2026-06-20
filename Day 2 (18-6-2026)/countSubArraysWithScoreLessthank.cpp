#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, long long k)
    {
        long long sum = 0;
        long long count = 0;

        long long i = 0, j = 0;
        while (j < nums.size())
        {
            sum += nums[j];

            // sum greater than k
            while (sum * (j - i + 1) >= k)
            {
                sum = sum - nums[i];
                i++;
            }

            // score less than k
            count += j - i + 1;
            j++;
        }
        return count;
    }
};

int main()
{

    vector<int> nums = {2, 1, 4, 3, 5};
    int k = 10;

    Solution obj;
    cout << obj.countSubarrays(nums, k);
    return 0;
}