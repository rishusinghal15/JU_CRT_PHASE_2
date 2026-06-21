#include<iostream>
#include<vector> 
using namespace std; 

class Solution {
	public:
	
	bool solve(vector<int> &arr, int i)
	{
		// Base case
		if (i == arr.size() - 1)
			{
			return true;
		}
		
		if (arr[i] > arr[i + 1])
			{
			return false;
		}
		
		return solve(arr, i + 1);
	}
	
	bool isSorted(vector<int>& arr) {
		return solve(arr, 0);
		
	}
};

int main()
{
    vector<int> arr = {10,20,30,40,50}; 
    Solution obj; 
    cout << obj.isSorted(arr); 
}
