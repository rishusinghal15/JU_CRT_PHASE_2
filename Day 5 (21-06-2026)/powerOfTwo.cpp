#include<iostream>
#include<cmath>
using namespace std; 

class Solution {
public:
    bool solve(int i, int n) {
        // base case
        if (pow(2, i) == n)
            return true;

        if (pow(2, i) > n)
            return false;

        return solve(i + 1, n);
    }
    bool isPowerOfTwo(int n) { return solve(0, n); }
};

int main()
{
    int n = 16; 
    Solution obj; 
    cout << obj.isPowerOfTwo(n); 
}