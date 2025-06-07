//Perfect Squares
//Compiler - C++
//https://leetcode.com/problems/perfect-squares/description/

class Solution {
public:
    static vector<int> dp;

    int numSquares(int n) {
        if (n <= 0) return 0;
        if (dp[n] != -1) return dp[n];

        int mini = INT_MAX;
        for (int i = 1; i * i <= n; i++) {
            int count = 1 + numSquares(n - i * i);
            mini = min(mini, count);
        }
        return dp[n] = mini;
    }
};

vector<int> Solution::dp(10001, -1);
