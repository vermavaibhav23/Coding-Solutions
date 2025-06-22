//Permutations 2
//Compiler - C++
//https://leetcode.com/problems/permutations-ii/?envType=problem-list-v2&envId=backtracking

class Solution {
public:
    void helper(vector<int>& nums, int curr, vector<vector<int>>&res) {
        if(curr == nums.size()) {
            res.push_back(nums);
            return;
        }
        set<int> branch_created;
        for(int j = curr; j < nums.size(); j++) {
            if (branch_created.find(nums[j]) != branch_created.end()) {
                continue;
            }
            branch_created.insert(nums[j]);
            swap(nums[curr], nums[j]);
            helper(nums,curr+1,res);
            swap(nums[curr], nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>v;
        vector<int>branch_created;
        helper(nums,0,v);
        return v;
    }
};