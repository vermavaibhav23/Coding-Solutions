//Kth Smallest Element in a BST
//Compiler - C++
//https://leetcode.com/problems/kth-smallest-element-in-a-bst/?envType=problem-list-v2&envId=binary-tree


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
    int inorder(TreeNode* root, int& k) {
        if(root == NULL) {
            return 0;
        }
        int left = inorder(root->left, k);
        k--;
        if(k == 0) {
            return root->val;
        }
        int right = inorder(root->right, k);
        
        if(left > 0) return left;
        else if(right > 0) return right;
        return 0;
    }
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
    }
};