#include<iostream>
#include<vector>
using namespace std; 

class Solution {
public:
   void solve(vector<int> &nums, int i, vector<int> temp, vector<vector<int>>&output)
   {
    // base case
    if(i==nums.size())
    {
        output.push_back(temp); 
        return; 
    }

    // ignoring ith element
    solve(nums, i+1, temp, output); 

    // accept kro ith element 
    int element = nums[i]; 
    temp.push_back(element); 
    solve(nums, i+1, temp, output); 
   }

    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> output; 
       vector<int> temp; 

       solve(nums, 0, temp, output); 
       return output;  
    }
};