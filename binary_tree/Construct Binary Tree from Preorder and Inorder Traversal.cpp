//Construct Binary Tree from Preorder and Inorder Traversal
//Compiler - C++
//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/?envType=problem-list-v2&envId=binary-tree

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.size() == 0 || preorder.size() == 0) {
            return NULL;
        }
        map<int,int>m;
        int a=0;
        for(auto it: inorder) {
            m[it] = a;
            a++;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        vector<int>in;
        for(auto it: inorder) {
            if(it == root->val) {
                break;
            }
            in.push_back(it);
        }
        vector<int>pre;
        int j = 1;
        for(j = 1 ; j < preorder.size(); j++) {
            if(pre.size() == in.size()) {
                break;
            }
            pre.push_back(preorder[j]);
        }
        root->left = buildTree(pre,in);
        in.clear();
        pre.clear();
        for(int i = m[root->val] + 1 ; i < inorder.size(); i++) {
            in.push_back(inorder[i]);
        }
        for(j = j ; j < preorder.size(); j++) {
            pre.push_back(preorder[j]);
        }
        root->right = buildTree(pre, in);

        return root;
    }
};