//Longest Harmonious Subsequence
//Compiler - C++
//https://leetcode.com/problems/longest-harmonious-subsequence/?envType=problem-list-v2&envId=sliding-window

class Solution {
public:
    map<int,int>frequency (vector<int>nums) {
        map<int,int>f;
        for(int i=0; i< nums.size(); i++) {
            f[nums[i]]++;
        }
        return f;
    }
    int findLHS(vector<int>& nums) {
        map<int,int>m = frequency(nums);
        int count = 0;
        int prev = -1;
        int ans = 0;
        for(auto it = (m.begin()); it != (m.end()); ++it) {
            if(count == 0) {
                prev = it->first;
                count++;
                continue;
            }
            if(it->first - prev == 1 && (m[prev] + m[it->first]) >= ans) {
                ans = m[prev] + m[it->first];
            }
            prev = it->first;
        }
        return ans;
    }
};