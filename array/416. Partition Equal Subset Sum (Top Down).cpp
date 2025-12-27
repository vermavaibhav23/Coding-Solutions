//416. Partition Equal Subset Sum
//C++
//https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
public:
    bool helper(vector<int>& nums, int sum, int i, vector<vector<int>>& dp) {
        if(i >= nums.size() || sum < 0) return false;
        if(sum == 0) return true;
        if(dp[i][sum] != -1) return dp[i][sum];
        bool pick = helper(nums, sum - nums[i], i+1, dp);
        bool skip = helper(nums, sum, i+1, dp);
        if(pick || skip) return dp[i][sum] = true;
        return dp[i][sum] = false;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it: nums) {
            sum += it;
        }
        if(sum % 2 != 0) return false;
        vector<vector<int>>dp(nums.size()+1, vector<int>(sum+1, -1));
        return helper(nums, sum/2, 0, dp);
    }
};