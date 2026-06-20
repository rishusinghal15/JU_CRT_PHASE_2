#include <iostream>
#include <vector>
#include<unordered_map> 
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;

        // store frequencies
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        vector<int> ans;
        int n = nums.size();

        // check frequency > n/3
        for (auto it : mp) {
            if (it.second > n / 3) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};

int main(){

    vector<int> nums = {3,2,3}; 
    Solution obj; 
    obj.majorityElement(nums); 
    return 0; 
}