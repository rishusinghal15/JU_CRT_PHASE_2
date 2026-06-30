#include<iostream>
#include<vector> 
#include<queue> 
using namespace std; 

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    int sumBT(Node* root) {
        if(root==NULL)
        return 0; 
        
        int sum = 0; 
        sum += root->data; 
        sum += sumBT(root->left); 
        sum += sumBT(root->right); 
        return sum; 
        
    }
};