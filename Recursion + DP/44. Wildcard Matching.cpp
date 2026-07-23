//44. Wildcard Matching
//Compiler : C++
//https://leetcode.com/problems/wildcard-matching/

class Solution {
public:
    int dp[2001][2001];

    bool helper(string& s, string& p, int i, int j) {
        if(i >= s.size() && j >= p.size()) return true;
        if(i >= s.size() && j < p.size()) {
            while( j < p.size()) {
                if(p[j] != '*') return false;
                j++;
            }
            return true;
        }

        if(i < s.size() && j >= p.size()) return false;

        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == p[j] || p[j] == '?') return dp[i][j] = helper(s, p, i+1, j+1);
        else if(p[j] == '*') {
            bool a = helper(s, p, i, j+1);
            bool b = helper(s, p, i+1, j);
            if(a || b) return dp[i][j] = true;
            else return dp[i][j] = false;
        }
        else return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        return helper(s, p, 0, 0);
    }
};