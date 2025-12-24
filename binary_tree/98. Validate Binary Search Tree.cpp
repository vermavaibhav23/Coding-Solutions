//98. Validate Binary Search Tree
//Compiler - C++
//https://leetcode.com/problems/validate-binary-search-tree/description/

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
    bool bst(TreeNode* root, TreeNode* min, TreeNode* max) {
        if(root == NULL) return true;
        if(min != NULL && root->val <= min->val) return false;
        if(max != NULL && root->val >= max->val) return false;
        bool left = bst(root->left, min, root);
        bool right = bst(root->right, root, max);
        if(left == false || right == false) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        bool ans = bst(root, NULL, NULL);
        return ans;
    }
};