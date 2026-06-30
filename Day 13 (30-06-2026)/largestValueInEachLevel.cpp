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
	vector<int> largestValues(Node* root) {
		if (root == NULL)
			return {};
		
		vector<int> ans;
		queue<Node*> q;
		q.push(root);
		
		while (!q.empty())
			{
			int n = q.size();
			int maxVal = INT_MIN;
			while (n>0)
				{
				Node* temp = q.front();
				q.pop();
				n--;
				
				maxVal = max(maxVal, temp->data); // max update karo
				
				if (temp->left != NULL) q.push(temp->left); // children push karo
				if (temp->right != NULL) q.push(temp->right);
			}
			ans.push_back(maxVal); 
		}
		return ans; 
	}
};