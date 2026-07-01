#include<iostream>
#include<cstring> 
#include<vector>
using namespace std; 

class Solution {
public:
    int solve(vector<int>& coins, int i, int amount, int t[301][5001]) {
        // base case: amount ban gaya
        if (amount == 0)
            return 1;

        // base case: coins khatam ho gaye
        if (i == coins.size())
            return 0;
            if(t[i][amount] != -1)
            return t[i][amount]; 


        int ways = 0;

        // Choice 1: current coin ko include karo (dobara use kar sakte ho, isliye index same rahega)
        if (coins[i] <= amount)
            ways += solve(coins, i, amount - coins[i], t);

        // Choice 2: current coin ko chhodo, agle coin pe jao
        ways += solve(coins, i + 1, amount, t);

        return t[i][amount] = ways;
    }

    int change(int amount, vector<int>& coins) {
        int t[301][5001];
        memset(t, -1, sizeof(t)); 
        return solve(coins, 0, amount, t);
    }
};