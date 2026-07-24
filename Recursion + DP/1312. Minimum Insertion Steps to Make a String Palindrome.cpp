//1312. Minimum Insertion Steps to Make a String Palindrome
//Compiler : C++
//https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

class Solution {
public:
    int dp[501][501];
    int helper(string& s, int i, int j) {
        if(i >= j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]) {
            return dp[i][j] = helper(s, i+1, j-1);
        }
        else {
            int a = 1 + helper(s, i+1, j); //send i
            int b = 1 + helper(s, i, j-1); //send j
            return dp[i][j] = min(a,b);
        }
    }
    int minInsertions(string s) {
        memset(dp, -1, sizeof(dp));
        return helper(s, 0, s.size()-1);
    }
};