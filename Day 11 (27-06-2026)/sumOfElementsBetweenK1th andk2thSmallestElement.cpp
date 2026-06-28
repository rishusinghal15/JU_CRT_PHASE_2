#include<iostream>
#include<vector>
#include<queue> 
using namespace std; 

class Solution {
public:
    long long kthSmallest(long long A[], long long N, long long K)
    {
        priority_queue<long long> max_heap;
        for(int i = 0; i < N; i++)
        {
            max_heap.push(A[i]);
            if(max_heap.size() > K)
                max_heap.pop();
        }
        return max_heap.top();
    }

    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2)
    {
        long long first = kthSmallest(A, N, K1);
        long long second = kthSmallest(A, N, K2);
        long long sum = 0;

        for(int i = 0; i < N; i++)
        {
            if(A[i] > first && A[i] < second)
                sum += A[i];
        }

        return sum;
    }
};

int main()
{
    long long A[] = {20, 8, 22, 4, 12, 10, 14}; 
    long long K1 = 3, K2 = 6; 
    long long N = 7; 

    Solution obj; 
    cout << obj.sumBetweenTwoKth(A, N, K1, K2); 
}