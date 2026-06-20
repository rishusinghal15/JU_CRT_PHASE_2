#include<iostream>
#include<algorithm>
#include<climits> 
#include<vector> 
using namespace std;

class Solution {
	public:
	
	bool isPossible(vector<int> &stalls, int k, int mid)
	{
		int cows = 1; // initially 1 cow h
		int pos = stalls[0]; // 1 cow ko first pos m rkh  diya
		
		for (int i = 0; i<stalls.size(); i++)
			{
			if (stalls[i]-pos >= mid)
				{
				cows++;
				pos = stalls[i];
			    }
			
			if (cows == k)
				{
				return true;
			}
		}
		return false;
	}
	
	int aggressiveCows(vector<int> &stalls, int k) {
		sort(stalls.begin(), stalls.end());
		int n = stalls.size();
		int s = 1; // Distance between two stalls is 1
		int e = stalls[n - 1] - stalls[0]; // Distance between two stalls is maximum
		int ans;
		while (s <= e)
			{
			int mid = s + (e-s)/2; // minimum distance between two stalls so that cows do not clash with each other
			if (isPossible(stalls, k, mid))
				{
				ans = mid;
				s = mid + 1; // distance ko inc krdo
			}
			else
				{
				e = mid - 1; // distance ko decrease krdo
			}
		}
		return ans;
	}
};

int main()
{
    vector<int> stalls = {1, 2, 4, 8, 9}; 
    int k = 3; 

    Solution obj; 
    cout << obj.aggressiveCows(stalls, k); 
    return 0; 
}