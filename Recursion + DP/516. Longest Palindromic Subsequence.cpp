//516. Longest Palindromic Subsequence
//Compiler : C++
//https://leetcode.com/problems/longest-palindromic-subsequence/

class Solution {
public:
    int helper(string& s, int i, int j, int dp[1001][1001]) {
        if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int temp = 0;
        if(s[i] == s[j]) {
            temp = 2 + helper(s, i+1, j-1, dp);
            return dp[i][j] = temp;
        }
        int left = helper(s, i+1, j, dp);
        int right = helper(s, i, j-1, dp);
        return dp[i][j] = max(left, right);
    }
    int longestPalindromeSubseq(string s) {
        int dp[1001][1001];
        memset(dp, -1, sizeof(dp));
        return helper(s, 0, s.size() - 1, dp);
    }
};