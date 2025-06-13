//https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/description/?envType=problem-list-v2&envId=dynamic-programming
//Compiler - C++
//Longest Unequal Adjacent Groups Subsequence I

class Solution {
public:
    void helper(vector<string>& words, vector<int>& groups, int n, int used, vector<string>&ans) {
        if(n == 0) {
            return;
        }
        if(groups[n-1] != used) {
            ans.push_back(words[n-1]);
            helper(words, groups, n-1, groups[n-1], ans);
        }
        else helper(words, groups, n-1, used, ans);
    }
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string>ans;
        int used = groups[groups.size() - 1];
        if(used == 1){
            used = 0;
        }
        else if(used == 0){
            used = 1;
        }
        helper(words, groups, words.size(), used, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};