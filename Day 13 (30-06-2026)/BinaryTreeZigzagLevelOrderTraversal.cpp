#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (root == NULL) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
        bool flag = true; // direction
        // true: left to right
        // false: right to left

        while (!q.empty()) {
            int n = q.size(); // Current level m total kitne nodes h
            vector<int> v(n);
            int idx; // iterate to 1-D output array

            for (int i = 0; i < n;
                 i++) // uss curr level m jitne nodes h sbme iterate kr rha
            {
                TreeNode* temp = q.front();
                q.pop();

                if (flag == true) {
                    idx = i;
                } else {
                    idx = n - 1 - i;
                }
                v[idx] = temp->val;
                if (temp->left != NULL)
                    q.push(temp->left);

                if (temp->right != NULL)
                    q.push(temp->right);
            }
            flag = !flag;
            ans.push_back(v);
        }
        return ans;
    }
};