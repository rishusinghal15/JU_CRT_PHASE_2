#include<iostream>
#include<vector> 
using namespace std; 

class Solution {
	public:
	
	void solve(vector<int> &arr, int i, int min, int max, vector<int> &ans)
	{
		// base case
		if (i == arr.size())
			{
			ans.push_back(min);
			ans.push_back(max);
			return;
		}
		
		if (arr[i] < min) {
			min = arr[i];
		}
		
		if (arr[i]> max) {
			max = arr[i];
		}
		
		solve(arr, i + 1, min, max,ans);
		
	}
	
	vector<int> getMinMax(vector<int> &arr) {
		vector<int> ans;
		int min = INT_MAX;
		int max = INT_MIN;
		
		solve(arr, 0, min, max, ans);
		return ans;
		
	}
};

int main()
{
    vector<int> arr = {1, 4, 3, 5, 8, 6}; 
    Solution obj; 
    obj.getMinMax(arr); 
}