#include<iostream>
#include<vector>
#include<queue> 
using namespace std; 

class Solution {
	public:
	int kthSmallest(vector<int> &arr, int k) {
		// max heap
		priority_queue<int> max_heap;
		for (int i = 0; i<arr.size(); i++)
			{
			max_heap.push(arr[i]);
			if (max_heap.size() > k)
				{
				max_heap.pop();
			}
		}
		return max_heap.top();
	}
};

int main()
{
    vector<int> arr = {10,5,4,3,48,6,2,33,53,10}; 
    int k = 4; 

    Solution obj; 
    cout << obj.kthSmallest(arr, k); 
    return 0; 
}
