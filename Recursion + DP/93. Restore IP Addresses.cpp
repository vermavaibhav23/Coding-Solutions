//93. Restore IP Addresses
//Compiler - C++
//https://leetcode.com/problems/restore-ip-addresses/?envType=company&envId=microsoft&favoriteSlug=microsoft-thirty-days

class Solution {
public:
    void helper(string s, int i, int last, string ans, int calls, vector<string>&res) {
        if( i > last+1) return;
        if(i == last+1 && calls == 4) {
            ans.pop_back();
            res.push_back(ans);
            return;
        }
        helper(s, i+1, last, ans + s.substr(i,1) + ".", calls+1, res);
        if(s[i] != '0' && i+1 <= last) {
            helper(s, i+2, last, ans + s.substr(i,2) + ".", calls+1, res);
            if(stoi(s.substr(i,3)) <= 255 && i+2 <= last) {
                helper(s, i+3, last, ans + s.substr(i,3) + ".", calls+1, res);
            }
        } 
        return;
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size() > 12) return {};
        vector<string>res;
        helper(s, 0, s.size()-1, "", 0, res);
        return res;
    }
};