#include<iostream>
#include<vector> 
using namespace std; 

class Solution {
	public:
	
	int reverse(int n, int rev)
	{
		// base case
		if (n == 0)
			return rev;
		
		int rem = n%10;
		rev = rev*10 + rem;
		
		// recursive case
		reverse(n/10, rev);
	}
	
	int reverseDigits(int n) {
		int rev = 0;
		return reverse(n, rev);
	}
};


int main()
{
    int n = 123; 
    Solution obj; 
    cout << obj.reverseDigits(n); 
}