//72. Edit Distance
//Compiler : C++
//https://leetcode.com/problems/edit-distance/

class Solution {
public:
    int helper(string word1, string word2, int i, int j, int dp[501][501]) {
        if(j >= word2.size()) return word1.size() - i;
        if(i >= word1.size()) return word2.size() - j;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        if(word1[i] == word2[j]) {
            ans = helper(word1, word2, i+1, j+1, dp);
        }
        int rep = 1 + helper(word1, word2, i+1, j+1, dp);
        int del = 1 + helper(word1, word2, i+1, j, dp);
        int ins = 1 + helper(word1, word2, i, j+1, dp);
        return dp[i][j] = min(ans, min(rep, min(del, ins)));
    }
    int minDistance(string word1, string word2) {
        int dp[501][501];
        memset(dp, -1, sizeof(dp));
        return helper(word1, word2, 0, 0, dp);
    }
};