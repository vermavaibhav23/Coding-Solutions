//Perfect Sum Problem
//Compiler - C++
//https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1

class Solution {
  public:
    int helper(vector<int>& arr, int target, int n, vector<vector<int>>& dp) {
        if(dp[n][target] != -1) {
            return dp[n][target];
        }
        if(target == 0) {
            return 1;
        }
        if (n ==0) {
            return 0;
        }
        if(arr[n-1] <= target) {
            return dp[n][target] = helper(arr, target - arr[n-1], n-1, dp) + helper(arr, target, n-1, dp);
        }
        else return dp[n][target] = helper(arr,target,n-1,dp);
    }
    int perfectSum(vector<int>& arr, int target) {
        vector<vector<int>>dp(1001, vector<int>(1001, -1));
        return helper(arr,target, arr.size(), dp);
    }
};