//222. Count Complete Tree Nodes
//Compiler - C++
//https://leetcode.com/problems/count-complete-tree-nodes/

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
    int height_left(TreeNode* root) {
        if(root == NULL) return 0;
        int count = 1;
        while(root != NULL) {
            root = root->left;
            count++;
        }
        return count;
    }
    int height_right(TreeNode* root) {
        if(root == NULL) return 0;
        int count = 0;
        while(root != NULL) {
            root = root->right;
            count++;
        }
        return count;
    }
    int countNodes(TreeNode* root) {
        int left = height_left(root);
        int right = height_right(root);
        if(left == right) {
            int temp = 1;
            int n = left;
            while(n > 0) {
                temp = temp * 2;
                n--;
            }
            return temp - 1;
        }
        else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};