#include<iostream>
#include<algorithm>
#include<climits> 
#include<vector> 
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& position, int m, int mid) {
        int ball = 1;          // 1 ball liya
        int pos = position[0]; // first ball ko first pos m rkh diya

        for (int i = 1; i < position.size(); i++) {
            if (position[i] - pos >= mid) {
                ball++;
                pos = position[i];
            }

            if (ball == m) {
                return true;
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int s = 1; // Worst Case -> Distance between two balls is 1
        int e =
            position[n - 1] -
            position[0]; // Best Case -> Distance between two balls is maximum
        int ans;
        while (s <= e) {
            int mid = s + (e - s) / 2; // Miimum distance between two balls so
                                       // that they will not attach
            if (isPossible(position, m, mid)) {
                ans = mid;
                s = mid + 1; // distance ko increase krdo kyuki ho skta h jyada
                             // distance bhi ho skta h
            } else {
                e = mid - 1; // distance ko decrease krdo
            }
        }
        return ans;
    }
};

int main(){

    vector<int> position = {1,2,3,4,7}; 
    int m = 3; 

    Solution obj; 
    cout << obj.maxDistance(position, m); 
    return 0; 
}