//2055. Plates Between Candles
//Compiler - C++
//https://leetcode.com/problems/plates-between-candles/

class Solution {
public:
    vector<int> prefixSum(string s) {
        vector<int> pS;
        int candle = -1;
        int plates = 0;
        int temp_plates = 0;
        bool cand = false;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '|') {
                cand = true;
                plates = plates + temp_plates;
                temp_plates = 0;
            }
            else {
                if(cand) {
                    temp_plates++;
                }
            }
            pS.push_back(plates);
        }
        return pS;
    }
    vector<int> upcoming_ones(string s) {
        vector<int> ones(s.size(), INT_MAX);
        int next = INT_MAX;
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] == '*') {
                ones[i] = next;
            }
            else {
                ones[i] = i;
                next = i;
            }
        }
        return ones;
    }
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> pS = prefixSum(s);
        for(auto it: pS) cout<<it<<" ";
        vector<int> up_ones = upcoming_ones(s);
        vector<int> ans;
        for(auto it: queries) {
            if(up_ones[it[0]] == INT_MAX || up_ones[it[0]] >= it[1]) {ans.push_back(0); continue;}
            int temp = pS[it[1]] - pS[ up_ones[it[0]] ];
            ans.push_back(temp);
        }
        return ans;
    }
};