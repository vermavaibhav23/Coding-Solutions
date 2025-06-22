//Binary Tree Right Side View
//Compiler - C++
//https://leetcode.com/problems/binary-tree-right-side-view/?envType=problem-list-v2&envId=binary-tree


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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            if(root == NULL) {
                return ans;
            }
            while(size>0) {
                TreeNode* node = q.front();
                if(size == 1) {
                    ans.push_back(q.front()->val);
                }
                if(node->left != NULL) {
                    q.push(node->left);
                }
                if(node->right != NULL) {
                    q.push(node->right);
                }
                q.pop();
                size--;
            }
        }
        return ans;
    }
};