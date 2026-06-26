#include<iostream>
#include<vector>
#include<stack>
using namespace std; 

class Solution {
	public:
	vector<int> prevSmaller(vector<int>& arr) {
		int n = arr.size();
		vector<int> ans;
		stack<int> s;
		s.push(-1);
		
		for (int i = 0; i <= n-1; i++) {
			int element = arr[i];
			while (s.top() != -1 && s.top() >= element) {
				s.pop();
			}
			ans.push_back(s.top());
			s.push(element);
		}
		return ans;
	}
};

int main() {
    Solution obj;

    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> ans = obj.prevSmaller(arr);

    cout << "Array: ";
    for (int x : arr)
        cout << x << " ";

    cout << "\nPrevious Smaller Elements: ";
    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}
