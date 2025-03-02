//Increasing Order Search Tree
//Compiler - C++
//https://leetcode.com/problems/increasing-order-search-tree/description/?envType=problem-list-v2&envId=stack

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
    vector<int> inorder (TreeNode* root){
        if (root == NULL){
            return {};
        }
        vector<int>ans;
        vector<int>left = inorder(root->left);
        ans.insert(ans.end(), left.begin(), left.end());
        ans.push_back(root->val);
        vector<int>right = inorder(root->right);
        ans.insert(ans.end(), right.begin(), right.end());
        return ans;
    }

    TreeNode* increasingBST(TreeNode* root) {
        vector<int>arr = inorder(root);
        TreeNode* head = new TreeNode(0);
        TreeNode* current = head;
        for (int i = 0; i < arr.size(); i++) {
            current->right = new TreeNode(arr[i]); 
            current = current->right;
        }
        return head->right;
    }
};