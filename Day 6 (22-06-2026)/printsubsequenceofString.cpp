#include<iostream>
#include<string> 
using namespace std; 

void print(string str, int i, int n, string ans){
    // base case 
    if(i==n)
    { 
        return; 
    }
    // exclude
    print(str, i+1, n, ans); 
    // include
    ans += str[i];
    cout << ans << " "; 
    print(str, i+1, n, ans); 
}

int main(){
    string str = "abc"; 
    print(str, 0, str.length(), " "); 
}