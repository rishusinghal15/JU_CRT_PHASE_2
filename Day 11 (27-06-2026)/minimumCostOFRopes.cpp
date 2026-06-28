#include<iostream>
#include<vector>
#include<queue> 
using namespace std; 

class Solution {
  public:
    int minCost(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int>> min_heap; 
        
        for(int i=0; i<arr.size(); i++)
        {
            min_heap.push(arr[i]); 
        }
        
        int cost = 0; 
        while(min_heap.size() >=2)
        {
            int first = min_heap.top(); 
            min_heap.pop(); 
            
            int second = min_heap.top(); 
            min_heap.pop(); 
            
            cost += first + second; 
            min_heap.push(first + second); 
        }
        return cost; 
    }
};

int main()
{
    vector<int> arr = {4,3,2,6}; 
    Solution obj; 
    cout << obj.minCost(arr); 
}