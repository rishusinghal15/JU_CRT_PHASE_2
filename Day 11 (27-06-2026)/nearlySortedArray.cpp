#include<iostream>
#include<vector>
#include<queue> 
using namespace std; 

class Solution {
	public:
	void nearlySorted(vector<int>& arr, int k) {
		priority_queue<int, vector<int>, greater<int>> min_heap;
		vector<int> output;
		
		for (int i = 0; i<arr.size(); i++)
			{
			min_heap.push(arr[i]);
			if (min_heap.size() > k)
				{
				output.push_back(min_heap.top());
				min_heap.pop();
			}
		}
		
		while (min_heap.size() != 0)
			{
			output.push_back(min_heap.top());
			min_heap.pop();
		}
		
		arr = output;
	}
};

int main()
{
   vector<int> arr = {2, 3, 1, 4}; 
    int k = 2; 

    Solution obj; 
    obj.nearlySorted(arr, k); 
    return 0; 
}
