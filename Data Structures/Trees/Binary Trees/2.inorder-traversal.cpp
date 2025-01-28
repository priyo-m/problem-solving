/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Recursive

class Solution {
public:
    void helper(TreeNode* root, vector<int> &inorder) {
        if(!root) return;
        helper(root->left, inorder);
        inorder.push_back(root->val);
        helper(root->right, inorder);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        if(!root) return inorder;
        helper(root, inorder);
        return inorder;
    }
};

// Iterative

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        if(!root) return inorder;
        TreeNode* node = root;
        stack<TreeNode*> s;
        while(true) {
            if(node) {
                s.push(node);
                node = node->left;
            }
            else {
                if(s.empty()) break;
                node = s.top(); s.pop();
                inorder.push_back(node->val);
                node = node->right;
            }
        }
        return inorder;
    }
};