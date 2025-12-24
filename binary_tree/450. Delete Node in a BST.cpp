//450. Delete Node in a BST
//Compiler - C++
//https://leetcode.com/problems/delete-node-in-a-bst/description/

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
    TreeNode* max_inTree(TreeNode* root) {
        if(root->right == NULL) return root;
        TreeNode* right = max_inTree(root->right);
        return right;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val > key) {
            TreeNode* left = deleteNode(root->left, key);
            root->left = left;
        }
        else if(root->val < key) {
            TreeNode* right = deleteNode(root->right, key);
            root->right = right;
        }
        else {
            if(root-> left != NULL && root->right != NULL) {
                TreeNode* temp = max_inTree(root->left);
                root->val = temp->val;
                root->left = deleteNode(root->left, temp->val);
            }
            else if(root->left == NULL && root->right == NULL) {
                return NULL;
            }
            else {
                if(root->left != NULL) return root->left;
                else return root->right;
            }
        }
        return root;
    }
};