#include<iostream>
#include<vector> 
using namespace std; 

void selectionSort(vector<int> &nums)
{
    int n = nums.size(); 
    for(int i=0; i<=n-1;i++)
    {
        int minIndex = i; 
        for(int j=i+1; j<n;j++)
        {
            if(nums[j] < nums[minIndex])
            {
                minIndex = j; 
            }
        }
        swap(nums[i], nums[minIndex]);  
    }
}

int main(){
    vector<int> nums = {64,25,12,22}; 
    selectionSort(nums); 

    // print sorted array 
    for(int i=0; i<nums.size(); i++)
    {
        cout << nums[i] << " "; 
    }
    return 0; 
}