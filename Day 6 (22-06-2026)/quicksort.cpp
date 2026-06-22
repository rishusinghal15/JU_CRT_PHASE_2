#include <iostream>
using namespace std;

int partition(int arr[], int st, int end)
{
    int pivotElement = arr[st];
    int count = 0;
    for(int i=st;i<=end;i++)
    {
        if(arr[i] <= pivotElement)
        count++;
    }

    int pivotIndex = st+count;

    int i=st, j = end;
    while(i<pivotIndex && j>pivotIndex)
    {
        while(arr[i]<=pivotElement)
        i++;

        while(arr[j] > pivotElement)
        j--;

        if(i<pivotIndex && j>pivotIndex)
        {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }

    return pivotIndex;
}
void quickSort(int arr[], int st, int end)
{
    //base case
    if(st >= end)
    return;

    //partition Logic : find the pivot index
    int pi = partition(arr,st,end);
    quickSort(arr,st,pi);
    quickSort(arr,pi+1,end);
}
int main() 
{
    int arr[5] = {4,5,3,1,6};

    quickSort(arr,0,4);

    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}