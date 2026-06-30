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
    int getSize(Node* root) {
        if(root==NULL)
        return 0; 
        
        return 1 + getSize(root->left) + getSize(root->right); 
    }
};