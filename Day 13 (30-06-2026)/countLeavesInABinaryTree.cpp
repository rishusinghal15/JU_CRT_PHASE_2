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
	
	void preOrder(Node* node, int &count)
	{
	    if (node == NULL) 
	    return;
	    
		if (node->left == NULL && node->right == NULL) // Calculate leaf node both child doesn't exist
		{
			count++;
			return;
		}
		
		preOrder(node->left, count);
		preOrder(node->right, count);
	}
	
	int countLeaves(Node* root) {
		int count = 0;
		preOrder(root, count);
		return count;
		
	}
};

