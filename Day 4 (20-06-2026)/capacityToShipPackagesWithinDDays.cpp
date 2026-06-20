#include<iostream>
#include<vector> 
using namespace std; 

class Solution
{
public:
    bool isPossible(vector<int> &weights, int days, int mid)
    {
        int day = 1;
        int shipWeight = 0;

        for (int i = 0; i < weights.size();) // no i++ as without checking we cannot move forward
        {
            if (shipWeight + weights[i] <= mid)
            {
                shipWeight += weights[i];
                i++;
            }
            else
            {
                day++;
                shipWeight = 0;
            }

            if (day > days)
            {
                return false;
            }
        }
        return true;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int total = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            total += weights[i];
        }

        int s = 1;
        int e = total;
        int ans; // minimum capacity of the ship
        while (s <= e)
        {
            int mid =
                s + (e - s) / 2; // atmost capacity of the ship to hold packages
            if (isPossible(weights, days, mid))
            {
                ans = mid;
                e = mid - 1; // capacity dec krdo
            }
            else
            {
                s = mid + 1; // capacity inc krdo
            }
        }
        return ans;
    }
};

int main(){

    vector<int> weights = {1,2,3,4,5,6,7,8,9,10}; 
    int days = 5; 

    Solution obj; 
    cout << obj.shipWithinDays(weights, days); 


    return 0; 
}