//159. Longest Substring with At Most Two Distinct Characters
//Compiler - C++
//https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/editorial/?envType=problem-list-v2&envId=sliding-window

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int ans = 0;
        int l = 0;
        int r = 0;
        int diff = 0;
        unordered_map<char, int>freq;
        while(r < s.size()) {
            if( (freq[s[r]] == 0 && diff + 1 <= 2) || (freq[s[r]] > 0) ) {
                if(freq[s[r]] == 0) {
                    diff++;
                }
                freq[s[r]]++;
                r++;
            }
            else {
                freq[s[l]]--;
                if(freq[s[l]] == 0) {
                    diff--;
                }
                l++;
            }
            if(diff <= 2) {
                ans = max(ans, r - l);
            }
        }
        return ans;
    }
};