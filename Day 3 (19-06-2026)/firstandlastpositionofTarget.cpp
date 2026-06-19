#include<iostream>
#include<vector> 
using namespace std; 

class Solution {
public:
    int lowerBound(vector<int>& nums, int target) {
        int ans = -1;
        int s = 0, e = nums.size() - 1;

        while (s <= e) {
            int mid = (s + e) / 2;
            if (nums[mid] == target) {
                ans = mid;
                e = mid - 1;
            } else if (target > nums[mid]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }

    int upperBound(vector<int>& nums, int target) {
        int ans = -1;
        int s = 0, e = nums.size() - 1;

        while (s <= e) {
            int mid = (s + e) / 2;
            if (nums[mid] == target) {
                ans = mid;
                s = mid + 1;
            } else if (target > nums[mid]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;

        int first = lowerBound(nums, target);
        int second = upperBound(nums, target);

        ans.push_back(first);
        ans.push_back(second);

        return ans;
    }
};

int main(){

    vector<int> nums = {5,7,7,8,8,10}; 
    int target = 8; 

    Solution obj; 
    cout << obj.lowerBound(nums, target) << endl;  
    cout << obj.upperBound(nums, target) << endl; 

    return 0; 
}