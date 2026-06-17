#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int maxSum = INT_MIN;

        // Sliding Window
        int i = 0, j = 0;
        int currSum = 0;

        while (j < arr.size()) {
            currSum += arr[j];

            if (j - i + 1 < k) {
                j++;
            }
            else if (j - i + 1 == k) {
                maxSum = max(maxSum, currSum);
                currSum -= arr[i];
                i++;
                j++;
            }
        }
        return maxSum;
    }
};

int main() {

    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    int k = 3;

    Solution obj;

    cout << obj.maxSubarraySum(arr, k) << endl;

    return 0;
}