#include<iostream>
#include<algorithm>
#include<climits> 
#include<vector> 
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        long long s = 1; 
        long long e = num; 
        while(s<=e)
        {
            long long mid = s+(e-s)/2;
            if(mid*mid == num)
            {
                return true; 
            } else if(mid*mid >= num)
            {
                e = mid - 1; 
            } else 
            {
                s = mid+1; 
            }
        }
        return false; 
    }
};

int main()
{ 
    int num = 16; 
    Solution obj; 
    cout << obj.isPerfectSquare(num); 
    return 0; 
}