//103. Binary Tree Zigzag Level Order Traversal
//Compiler - C++
//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/?envType=company&envId=amazon&favoriteSlug=amazon-thirty-days

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool lock = false;
        while(!q.empty()) {
            int size = q.size();
            vector<int>temp;
            if(lock) lock = false;
            else if(!lock) lock = true;
            while(size > 0) {
                size--;
                TreeNode* top = q.front();
                temp.push_back(top->val);
                q.pop();
                if(top->left != NULL) {
                    q.push(top->left);
                }
                if(top->right != NULL) {
                    q.push(top->right);
                }
            }
            if(!lock) {
                reverse(temp.begin(), temp.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};