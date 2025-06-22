//Sum Root to Leaf Numbers
//Compiler - C++
//https://leetcode.com/problems/sum-root-to-leaf-numbers/?envType=problem-list-v2&envId=binary-tree


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
    int helper(TreeNode* root, int sum) {
        if(root == NULL) {
            return 0;
        }
        sum = (sum * 10) + root->val;
        if(root->left == NULL && root->right == NULL) {
            return sum;
        }
        return helper(root->left, sum) + helper(root->right, sum);
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        return helper(root, sum);
    }
};