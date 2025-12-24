//515. Find Largest Value in Each Tree Row
//Compiler - C++
//https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/

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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        if(root == NULL) return ans;
        while(!q.empty()) {
            int size = q.size();
            int highest = INT_MIN;
            while(size > 0) {
                if(q.front()->left != NULL) q.push(q.front()->left);
                if(q.front()->right != NULL) q.push(q.front()->right);
                highest = max(highest, q.front()->val);
                q.pop();
                size--;
            }
            ans.push_back(highest);
        }
        return ans;
    }
};