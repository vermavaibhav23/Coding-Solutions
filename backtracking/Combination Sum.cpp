//Combination Sum
//Compiler - C++
//https://leetcode.com/problems/combination-sum/?envType=problem-list-v2&envId=backtracking

class Solution {
public:
    void helper(vector<int>& candidates, int t, int curr, int n, vector<int>& ans, vector<vector<int>>& res){
        if(t == 0) {
            res.push_back(ans);
            return;
        }
        if(curr > n-1 || t<0) {
            return;
        }
        helper(candidates, t, curr+1, n, ans, res);
        ans.push_back(candidates[curr]);
        helper(candidates, t - candidates[curr], curr, n, ans, res);
        ans.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ans;
        vector<vector<int>>res;
        helper(candidates, target, 0, candidates.size(), ans, res);
        return res;
    }
};