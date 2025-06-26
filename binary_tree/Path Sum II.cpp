//Path Sum II
//Compiler - C++
//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/?envType=problem-list-v2&envId=binary-tree


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
    void helper(TreeNode* root, int n, vector<int>path, vector<vector<int>>&ans) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL && n - root->val == 0) {
            path.push_back(root->val);
            ans.push_back(path);
            return;
        }
        path.push_back(root->val);
        helper(root->left, n - root->val, path, ans);
        helper(root->right, n - root->val, path, ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        vector<vector<int>>ans;
        helper(root, targetSum, path, ans);
        return ans;
    }
};