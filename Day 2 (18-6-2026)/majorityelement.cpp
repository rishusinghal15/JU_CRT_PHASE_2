#include <iostream>
#include <vector>
#include<unordered_map> 
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // create map
        unordered_map<int, int> mp; // to map the frequency of an array element

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        int maxFreq = INT_MIN;
        int ans; // stores majority element

        for (int i = 0; i < nums.size(); i++) {
            if (mp[nums[i]] > maxFreq) {
                maxFreq = mp[nums[i]]; // 
                ans = nums[i];
            }
        }
        return ans;
    }
};

int main(){

    vector<int> nums = {3,2,3}; 
    Solution obj; 
    cout << obj.majorityElement(nums); 
    return 0; 
}