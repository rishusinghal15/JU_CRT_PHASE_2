#include <iostream>
#include<vector>
#include<stack>
using namespace std;

//khud ka stack banaenge using class
class Stack{
    public:
    //data member of noraml container as array
    vector<int> arr;
    
    //insert
    void push(int v)
    {
        arr.push_back(v);
    }
    
    //delete
    void pop()
    {
        arr.pop_back();
    }
    
    //top
    int top()
    {
        return arr[arr.size()-1];
    }
    
    bool empty()
    {
        if(arr.size()==0)
        return true;
        else
        return false;
    }
};

int main() {
   Stack st;
   st.push(1);
   st.push(2);
   st.push(3);
   
   while(!st.empty())
   {
       cout<<st.top()<<" ";
       st.pop();
   }
    return 0;
}