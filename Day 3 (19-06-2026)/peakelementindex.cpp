#include<iostream>
#include<vector> 
using namespace std; 

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s = 0, e = nums.size() - 1;
        while (s < e) {
            int mid = s + (e-s)/ 2;

            if (nums[mid] < nums[mid + 1]) {
                s = mid + 1;
            }else {
                e = mid;
            }
        }
        return s;
    }
};

int main(){

    vector<int> nums = {1,2,3,1}; 
    Solution obj; 
    cout << obj.findPeakElement(nums); 

    return 0; 
}