//Combinations
//Compiler - C++
//https://leetcode.com/problems/combinations/?envType=problem-list-v2&envId=backtracking

class Solution {
public:
    void helper(int curr, int n, int k, vector<int>&ans, vector<vector<int>>&res) {
        if(k == 0) {
            res.push_back(ans);
            return;
        }
        if(curr > n) return;
        for(int i=curr; i<=n; i++) {
            ans.push_back(i);
            helper(i+1,n, k-1, ans, res);
            ans.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>ans;
        vector<vector<int>>res;
        helper(1, n,k,ans,res);
        return res;
    }
};