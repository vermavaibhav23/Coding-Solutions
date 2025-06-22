//Permutations
//Compiler - C++
//https://leetcode.com/problems/permutations/?envType=problem-list-v2&envId=backtracking

class Solution {
public:
    void helper(vector<int>& nums, int curr, int n, vector<vector<int>>&ans) {
        if(curr == n) {
            ans.push_back(nums);
            return;
        }
        for(int j = curr; j<n; j++) {
            swap(nums[curr], nums[j]);
            helper(nums, curr+1, n, ans);
            swap(nums[curr], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        helper(nums, 0, nums.size(), ans);
        return ans;
    }
};