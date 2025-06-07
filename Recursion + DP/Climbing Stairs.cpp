//Climbing Stairs
//Compiler - C++
//https://leetcode.com/problems/climbing-stairs/

vector<int>dp(46, -1);
class Solution {
public:
    int climbStairs(int n) {
        if(dp[n] != -1){
            return dp[n];
        }
        if(n<1) {
            return dp[n] = 0;
        }
        if(n == 1) {
            return dp[n] = 1;
        }
        if(n == 2) {
            return dp[n] = 2;
        }
        return dp[n] = (climbStairs(n-1) + climbStairs(n-2));
    }
};