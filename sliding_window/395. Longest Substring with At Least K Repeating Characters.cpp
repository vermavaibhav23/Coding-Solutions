//395. Longest Substring with At Least K Repeating Characters
//Compiler - C++
//https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/?envType=problem-list-v2&envId=sliding-window

class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char, int>freq;
        int unique = 0;
        for(int i = 0; i < s.size(); i++) {
            if(freq[s[i]] == 0) {
                unique++;
            }
            freq[s[i]]++;
        }
        freq.clear();
        int ans = 0;
        
        for(int i = 1; i <= unique; i++) {
            int start = 0;
            int end = 0;
            int countU = 0;
            int Kcount = 0;
            freq.clear();
            while(end < s.size()) {
                if( (freq[s[end]] == 0 && countU + 1 <= i) || (freq[s[end]] > 0) ) {
                    freq[s[end]]++;
                    
                    if(freq[s[end]] == 1) {
                        countU++;
                    }
                    if(freq[s[end]] == k) {
                        Kcount++;
                    }
                    end++;
                }
                else {
                  
                    freq[s[start]]--;
                    if(freq[s[start]] == 0) {
                        countU--;
                    }
                    if(freq[s[start]] + 1 == k) {
                        Kcount--;
                    }
                    start++;
                }
                if(Kcount == i) {
                    ans = max(ans, end-start);
                }
            }
        }
        return ans;
    }
};