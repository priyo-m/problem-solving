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
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        int height = Height(root, diameter);
        return diameter;
    }
    int Height(TreeNode* root, int &diameter) {
        if(!root) return 0;
        int lh = Height(root->left, diameter);
        int rh = Height(root->right, diameter);
        diameter = max(diameter, lh+rh);
        return 1+max(lh,rh);
    }
};