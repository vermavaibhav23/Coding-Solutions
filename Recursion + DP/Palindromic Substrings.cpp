//Palindromic Substrings
//C++
//https://leetcode.com/problems/palindromic-substrings/


class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;
        if (n == 0) return 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int count = 0;
        for (int L = 1; L <= n; L++) {
            for(int i = 0; (i + L - 1) < n; i++) {
                int j = i + L - 1;
                if(i == j) {dp[i][j] = true; count++;}
                else if(i+1 == j && s[i] == s[j]) {dp[i][j] = true; count++;}
                else if(s[i] == s[j] && dp[i+1][j-1]) {dp[i][j] = true; count++;}
                else dp[i][j] = false;
            }
        } 
        return count;
    }
};