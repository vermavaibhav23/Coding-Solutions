//701. Insert into a Binary Search Tree
//Compiler - C++
//https://leetcode.com/problems/insert-into-a-binary-search-tree/

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        if(val < root->val) {
            TreeNode* left = insertIntoBST(root->left, val);
            if(left->val == val) {
                root->left = new TreeNode(val);
            }
        }
        if(val > root->val) {
            TreeNode* right = insertIntoBST(root->right, val);
            if(right->val == val) {
                root->right = new TreeNode(val);
            }
        } 
        return root;
    }
};