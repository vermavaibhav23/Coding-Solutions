//Binary Tree Level Order Traversal
//Compiler - C++
//https://leetcode.com/problems/binary-tree-level-order-traversal/?envType=problem-list-v2&envId=binary-tree
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if(root != NULL) {
            q.push(root);
        }
        while(!q.empty()) {
            vector<int>levels;
            int size = q.size();
            for(int i=0; i<size; i++) {
                TreeNode* front = q.front();
                q.pop();
                if(front->left != NULL) {
                    q.push(front->left);
                }
                if(front->right != NULL) {
                    q.push(front->right);
                }
                levels.push_back(front->val);
            }
            ans.push_back(levels);
        }
        return ans;
    }
};