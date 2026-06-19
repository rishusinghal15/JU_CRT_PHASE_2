#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &arr, int k, int mid)
    {
        int student = 1;
        int readPages = 0;

        for (int i = 0; i < arr.size();)
        {
            if (readPages + arr[i] <= mid)
            {
                readPages += arr[i];
                i++;
            }
            else
            {
                student++;
                readPages = 0;
            }

            if (student > k)
            {
                return false;
            }
        }
        return true;
    }

    int findPages(vector<int> &arr, int k)
    {
        if (k > arr.size())
        {
            return -1;
        }

        int total = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            total += arr[i];
        }

        int s = 1;
        int e = total;
        int ans = -1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2; // atmost mid capacity of students to read books
            if (isPossible(arr, k, mid))
            {
                ans = mid;
                e = mid - 1; // Capacity decrease krdo
            }
            else
            {
                s = mid + 1; // capacity inc krdo
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = {12, 34, 67, 90};
    int k = 2;

    Solution obj; 
    cout << obj.findPages(arr, k); 
}