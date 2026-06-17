#include <iostream>
using namespace std;

class Solution
{
public:
    void twoSum(int arr[], int n, int target)
    // if array is sorted, then we can use one pointer 
    // in start and one in end 
    // {

    //     for (int i = 0; i <= n - 1; i++)
    //     {
    //         for (int j = n-1; j >=0; j--)
    //         {
    //             if (arr[i] + arr[j] == target)
    //             {
    //                 cout << i << " " << j << endl;
    //                 return;
    //             }
    //         }
    //     }
    //     cout << "No pair exist" << endl;
    // }

    {

        for (int i = 0; i <= n - 2; i++)
        {
            for (int j = i + 1; j <= n - 1; j++)
            {
                if (arr[i] + arr[j] == target)
                {
                    cout << i << " " << j << endl;
                    return;
                }
            }
        }
        cout << "No pair exist" << endl;
    }
};

int main()
{

    int arr[] = {2,7,11,15};
    int n = 4;
    int target = 18;

    Solution findTwoSum;
    findTwoSum.twoSum(arr, n, target);

    return 0;
}