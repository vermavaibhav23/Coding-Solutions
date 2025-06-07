//Decode Ways
//Compiler - C++
//https://leetcode.com/problems/decode-ways/description/

class Solution {
public:
    int decode(string s, int pos, vector<int>&dp) {
        if(dp[pos] != -1){
            return dp[pos];
        }
        if(pos == s.size()) return 1;
        if(s[pos] == '0') return 0;
        int count = decode(s, pos + 1, dp);
        if(pos < s.size() -1 && s.substr(pos,2) < "27") {
            count = count + decode(s, pos + 2, dp);
        }
        return dp[pos] = count;
    }
    int numDecodings(string s) {
        vector<int>dp(101, -1);
        return decode(s,0, dp);
    }
};