#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int solve(vector<int>& nums, int s, int e, int target) {
        // base case
        if (s > e) {
            return -1;
        }
        int mid = s+(e-s)/2; 
        if(nums[mid]==target){
            return mid; 
        } else if(target> nums[mid]){
            // right side
            return solve(nums, mid+1, e, target); 
        } else {
            // left side
            return solve(nums, s, mid-1, target); 
        }
    }

    int search(vector<int>& nums, int target) {
        return solve(nums, 0, nums.size()-1, target);
    }
};

int main()
{
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9; 

    Solution obj; 
    cout << obj.search(nums, target); 
}