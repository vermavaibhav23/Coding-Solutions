//437. Path Sum III
//Compiler - C++
//https://leetcode.com/problems/path-sum-iii/description/

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
    void helper(TreeNode* root, int targetSum, unordered_map<long long, int>& freq, long long pS, int &count) {
        if(root == NULL) return;
        pS += root->val;
        if(freq[pS - targetSum] != 0) count += freq[pS - targetSum];
        freq[pS]++;
        helper(root->left, targetSum, freq, pS, count);
        helper(root->right, targetSum, freq, pS, count);
        freq[pS]--;
        return;
    }
    int pathSum(TreeNode* root, int targetSum) {
        long long pS = 0;
        int count = 0;
        unordered_map<long long, int>freq;
        freq[0] = 1;
        helper(root, targetSum, freq, pS, count);
        return count;
    }
};