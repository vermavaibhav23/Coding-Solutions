//Invert Binary Tree
//Compiler - C++
//https://leetcode.com/problems/invert-binary-tree/?envType=problem-list-v2&envId=binary-tree


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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        TreeNode* r = root->right;
        root->right = root->left;
        root->left = r;
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        return root;
    }
};