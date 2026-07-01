#include<iostream>
#include<vector>
using namespace std; 

class Solution {
public:
    void solve(vector<int>& candidates, int i, vector<int> temp,
               vector<vector<int>>& output, int target) {
        // base case
        if (target == 0) {
            output.push_back(temp);
            return;
        }

        if (i == candidates.size()) {
            return;
        }

        if (candidates[i] <= target) {
            temp.push_back(candidates[i]);
            solve(candidates, i, temp, output, target - candidates[i]);
            temp.pop_back();
        }
        solve(candidates, i + 1, temp, output, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> output;
        vector<int> temp;

        solve(candidates, 0, temp, output, target);
        return output;
    }
};