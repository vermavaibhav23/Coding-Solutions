//Lowest Common Ancestor of a Binary Tree
//Compiler - C++
//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/?envType=problem-list-v2&envId=binary-tree


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root == p) {
            return p;
        }
        if(root == q) {
            return q;
        }
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        if(l != NULL && r != NULL) return root;
        if(l != NULL) return l;
        else return r;
    }
};