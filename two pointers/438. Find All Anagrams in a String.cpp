//438. Find All Anagrams in a String
//Compiler - C++
//https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int>pfreq;
        for(auto it: p) pfreq[it]++;
        unordered_map<char, int>sfreq;
        int l = 0;
        int r = 0;
        vector<int>ans;
        while(r < s.size()) {
            int window = r - l + 1;
            sfreq[s[r]]++;
            if(window == p.size()) {
                if(pfreq == sfreq) ans.push_back(l);
                sfreq[s[l]]--;
                if(sfreq[s[l]] == 0) sfreq.erase(s[l]);
                l++;
            }
            r++;
        }
        return ans;
    }
};