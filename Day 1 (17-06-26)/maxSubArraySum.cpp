#include <iostream>
#include <climits>
using namespace std;

class Solution
{
public:
    int maxSubArraySum(int arr[], int n)
    {
        int prefixSum = 0;
        int maxSum = INT_MIN;
        for (int i = 0; i <= n - 1; i++)
        {
            prefixSum += arr[i];
            maxSum = max(prefixSum, maxSum);
            // Kadane's Algorithm approach:
            if (prefixSum < 0)
            {
                prefixSum = 0;
            }
        }
        return maxSum;
    }
};

int main()
{

    int arr[] = {1,2,-15,3,4,-36, 9};
    int n = 7;
    Solution result;
    cout << result.maxSubArraySum(arr, n);
    return 0;
}