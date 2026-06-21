#include<iostream>
#include<vector> 
using namespace std; 


class Solution {
  public:
  
  void solve(vector<int> &arr, int i)
  {
      // Base case
        if (i >= arr.size() / 2) {
            return;
        }

        swap(arr[i], arr[arr.size() - 1 - i]);
        solve(arr, i + 1);

  }
  
    void reverseArray(vector<int> &arr) {
        solve(arr, 0); 
        
    }
};

int main()
{
    vector<int> arr = {1, 4, 3, 2, 6, 5}; 
    Solution obj; 
    cout << obj.reverseArray(arr); 
}