//40. Combination Sum II
//C++
//https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    void helper(vector<int>& candidates, int target, int index, vector<int> path, vector<vector<int>>& ans) {
        if(target == 0) ans.push_back(path);
        if(index >= candidates.size() || target < 0) return;
        for(int i = index; i < candidates.size(); i++) {
            if(i > index && candidates[i-1] == candidates[i]) continue;
            path.push_back(candidates[i]);
            helper(candidates, target - candidates[i], i+1, path, ans);
            path.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0, path, ans);
        return ans;
    }
};
