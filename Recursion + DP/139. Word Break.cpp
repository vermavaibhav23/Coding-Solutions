//139. Word Break
//C++
//https://leetcode.com/problems/word-break/submissions/1880532227/?envType=company&envId=microsoft&favoriteSlug=microsoft-six-months


class Solution {
public:
    bool helper(string s, unordered_set<string> dict, int r, string temp, vector<int>& memo) {
        if(r >= s.size()) return true;
        if(memo[r] != -1) return memo[r];
        int permamnent_r = r;
        while(r < s.size()) {     
            temp = temp + s[r];
            cout<<temp<<endl;
            if(dict.count(temp)) {
                bool check = helper(s, dict, r+1, "", memo);
                if(check) {
                    memo[permamnent_r] = true;
                    return true;
                } 
            }
            r++;
        }
        memo[permamnent_r] = false;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        vector<int>memo(s.size()+1, -1);
        for(auto it: wordDict) {
            dict.insert(it);
        }
        return helper(s, dict, 0, "", memo);
    }
};