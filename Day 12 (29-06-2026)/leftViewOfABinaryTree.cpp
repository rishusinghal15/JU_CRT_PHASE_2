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
    vector<int> leftView(Node *root) {
        vector<int> ans; 
        
        if(root==NULL)
        return ans; 
        
        queue<Node*> q; 
        q.push(root); 
        
        while(!q.empty())
        {
            int n = q.size(); 
            ans.push_back(q.front()->data); 
            while(n>0)
            {
                Node* temp = q.front(); 
                q.pop(); 
                
                if(temp->left != NULL)
                q.push(temp->left); 
                
                if(temp->right != NULL)
                q.push(temp->right); 
                
                n--; 
            }
        }
        return ans; 
        
    }
};