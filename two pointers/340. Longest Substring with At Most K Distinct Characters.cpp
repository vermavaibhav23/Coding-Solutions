//340. Longest Substring with At Most K Distinct Characters
//Compiler - C++
//https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int l = 0;
        int r = 0;
        unordered_map<char, int>freq;
        int ans = 0;
        while(r < s.size()) {
            freq[s[r]]++;
            while(freq.size() > k) {
                freq[s[l]]--;
                if(freq[s[l]] == 0) freq.erase(s[l]);
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};