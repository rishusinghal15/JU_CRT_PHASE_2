#include<iostream>
#include<vector> 
using namespace std; 

void insertionSort(vector<int>& v)
{
    int n = v.size();

    for(int i = 1; i < n; i++)
    {
        int key = v[i];
        int j = i - 1;

        while(j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = key;
    }
}

int main(){
    vector<int> nums = {5,4,3,2,1}; 
    insertionSort(nums); 

    // print sorted array 
    for(int i=0; i<nums.size(); i++)
    {
        cout << nums[i] << " "; 
    }
    return 0; 
}