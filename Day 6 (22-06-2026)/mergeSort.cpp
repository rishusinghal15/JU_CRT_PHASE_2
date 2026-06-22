#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int s, int mid, int e)
{
    vector<int> output(e - s + 1);
    int i = s; //  pointer on first subarray
    int j = mid + 1; // pointer on second subarray
    int k = 0; // Iterate in output array

    while (i <= mid && j <= e)
    {
        if (arr[i] < arr[j])
        {
            output[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            output[k] = arr[j];
            j++;
            k++;
        }
    }

    // if left array elements remaining h
    while (i <= mid)
    {
        output[k] = arr[i];
        i++;
        k++;
    }

    // if right array elements remaining h
    while (j <= e)
    {
        output[k] = arr[j];
        j++;
        k++;
    }

    // copy all elements of output array into original array
    k = 0;
    for (int i = s; i <= e; i++)
    {
        arr[i] = output[k];
        k++;
    }
}

void mergeSort(int arr[], int s, int e)
{
    // base case
    if (s >= e)
        return;
        
    int mid = (s + e) / 2;
    mergeSort(arr, s, mid);     // left Subarray
    mergeSort(arr, mid + 1, e); // right subarray

    merge(arr, s, mid, e);
}

int main()
{
    int arr[5] = {5, 3, 1, 4, 6};
    mergeSort(arr, 0, 4);

    // Print sorted array
    for(int i = 0; i <= 4; i++)
    {
        cout << arr[i] << " ";
    }
}