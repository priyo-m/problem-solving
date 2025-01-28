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
    void helper(TreeNode* root, vector<int> &postorder) {
        if(!root) return;
        if(root->left) helper(root->left, postorder);
        if(root->right) helper(root->right, postorder);
        postorder.push_back(root->val);
        return;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(!root) return postorder;
        helper(root, postorder);
        return postorder;
    }
};

// Iterative using 2 stack

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(!root) return postorder;
        stack<TreeNode*> s1, s2;
        s1.push(root);
        while(!s1.empty()) {
            TreeNode* node = s1.top(); s1.pop();
            s2.push(node);
            if(node->left) s1.push(node->left);
            if(node->right) s1.push(node->right);
        }
        while(!s2.empty()) {
            TreeNode* node = s2.top(); s2.pop();
            postorder.push_back(node->val);
        }
        return postorder;
    }
};