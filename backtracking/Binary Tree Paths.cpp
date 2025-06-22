//Binary Tree Paths
//Compiler - C++
//https://leetcode.com/problems/binary-tree-paths/description/?envType=problem-list-v2&envId=backtracking

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
    void helper(TreeNode* root, string path, vector<string>& ans) {
        if(root == NULL) {
            return;
        }
        
        string added = to_string(root->val) + "->";
        path = path + added;
        int size = path.size();
        if(root->left == NULL && root->right == NULL){
            ans.push_back(path.substr(0,path.size()-2));
            return;
        }
        helper(root->left,path,ans);
        path = path.substr(0,size);
        helper(root->right,path,ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string path = "";
        vector<string>ans;
        helper(root,path, ans);
        return ans;
    }
};