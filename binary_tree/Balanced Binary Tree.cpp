//Balanced Binary Tree
//Compiler - C++
//https://leetcode.com/problems/balanced-binary-tree/?envType=problem-list-v2&envId=binary-tree


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
    int height(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        return max(height(root->left), height(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        int ht_l = height(root->left);
        int ht_r = height(root->right);
        int diff = abs(ht_l - ht_r);
        if(diff>1) {
            return false;
        }
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        if(left == false) return false;
        if(right == false) return false;
        return true;
    }
};