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
