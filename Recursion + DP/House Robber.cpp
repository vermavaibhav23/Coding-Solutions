//House Robber
//Compiler - C++
//https://leetcode.com/problems/house-robber/description/

class Solution {
public:
    int robbing(vector<int>& nums, int n, vector<int>& dp) {
        if(dp[n] != -1) {
            return dp[n];
        }
        if(n<1) {
            return dp[n] = 0;
        }
        if(n == 1 || n == 2) {
            return dp[n] = nums[n-1];
        }
        return dp[n] = max(robbing(nums,n-2,dp), robbing(nums,n-3,dp)) + nums[n-1];
    }
    int rob(vector<int>& nums) {
        vector<int>dp(101, -1);
        int size = nums.size();
        return max(robbing(nums, size, dp), robbing(nums, size-1, dp));
    }
};