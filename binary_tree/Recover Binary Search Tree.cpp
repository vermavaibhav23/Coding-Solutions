//Recover Binary Search Tree
//Compiler - C++
//https://leetcode.com/problems/recover-binary-search-tree/?envType=problem-list-v2&envId=binary-tree

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
    vector<int>inorder(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        vector<int>left = inorder(root->left);
        vector<int>right = inorder(root->right);
        left.push_back(root->val);
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
    void traverse(TreeNode* root, int a, int b) {
        if(root == NULL) {
            return;
        }
        if(root->val == a) {
            root->val = b;
        }
        else if(root->val == b) {
            root->val = a;
        }
        traverse(root->left,a,b);
        traverse(root->right,a,b);
    }
    void recoverTree(TreeNode* root) {
        vector<int>bst = inorder(root);
        vector<int>sorted = bst;
        sort(sorted.begin(), sorted.end());
        
        vector<int>swapped;
        for(int i=0; i<bst.size(); i++) {
            if(sorted[i] != bst[i]) {
                cout<<"swapped = "<<bst[i]<<endl;
                swapped.push_back(bst[i]);
            }
        }
        traverse(root, swapped[0], swapped[1]);
        return;
    }
};