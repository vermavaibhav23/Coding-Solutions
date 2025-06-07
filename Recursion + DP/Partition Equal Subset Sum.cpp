//Partition Equal Subset Sum
//Compiler - C++
//https://leetcode.com/problems/partition-equal-subset-sum/description/

class Solution {
public:
    int sum(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
        }
        return sum;
    }
    bool helper(vector<int>& nums,int sum, int n, vector<vector<int>>&dp) {
        if(dp[sum][n] != -1) {
            return dp[sum][n];
        }
        if(sum == 0){
            return true;
        }
        if(n == 0) {
            return false;
        }
        if(nums[n-1] <= sum) {
            return dp[sum][n] = helper(nums,sum-nums[n-1],n-1,dp) || helper(nums, sum, n-1,dp);
        }
        else return dp[sum][n] = helper(nums, sum, n-1,dp);
    }
    bool canPartition(vector<int>& nums) {
        vector<vector<int>>dp(sum(nums) + 1,vector<int>(201,-1));
        if(sum(nums) % 2 != 0){
            return false;
        }
        return helper(nums, sum(nums)/2, nums.size(), dp);
    }
};