#include<iostream>
#include<cstring> 
using namespace std; 


class Solution {
public:
    int solve(int n, int t[46]) {
        // base case
        if (n == 0 || n==1)
            return 1;

        if(t[n] != -1)
        return t[n]; 

        return t[n] = solve(n - 1, t) + solve(n - 2, t);
    }
    int climbStairs(int n) 
    { 
        int t[46]; 
        memset(t, -1, sizeof(t)); 
        return solve(n, t); 
    }
};