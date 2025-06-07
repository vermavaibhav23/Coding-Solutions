//Min Cost Climbing Stairs
//Compiler - C++
//https://leetcode.com/problems/min-cost-climbing-stairs/

class Solution {
public:
    int helper(vector<int>& cost, int n, vector<int>&dp) {
        if(dp[n] != -1) {
            return dp[n];
        }
        if(n <= 1) {
            return dp[n] = 0;
        }
        if(n == 2) {
            return dp[n] = min(cost[0], cost[1]);
        }
        return dp[n] = min( helper(cost, n-1, dp) + cost[n-1], helper(cost, n-2, dp) + cost[n-2] );
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(1001, -1);
        int size = cost.size();
        return helper(cost, size, dp);
    }
};