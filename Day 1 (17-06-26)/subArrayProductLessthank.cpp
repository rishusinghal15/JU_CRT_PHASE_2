#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // sliding window
        // j-> grow window size
        // i-> shrink window size
        int i = 0, j = 0;
        int count = 0;

        int prod = 1;
        while (j < nums.size()) {
            prod *= nums[j];
            while (prod >= k && i <= j) {
                prod = prod / nums[i];
                i++;
            }

            // product less than k
            count += (j - i + 1);
            j++;
        }
        return count;
    }
};

int main() {

    vector<int> arr = {1,2,3};
    int k = 0;

    Solution obj;

    cout << obj.numSubarrayProductLessThanK(arr, k) << endl;

    return 0;
}