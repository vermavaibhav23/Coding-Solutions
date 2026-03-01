//1589. Maximum Sum Obtained of Any Permutation
//Compiler - C++
//https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/description/

class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        vector<int> freq(nums.size()+1, 0);
        for(auto it : requests) {
            freq[it[0]]++;
            freq[it[1] + 1]--;
        }
        for(int i = 1; i < freq.size(); i++) {
            freq[i] += freq[i-1];
        }
        sort(freq.begin(), freq.end(), greater<int>());
        sort(nums.begin(), nums.end(), greater<int>());
        int l = 0;
        long long sum = 0;
        for(int i = 0; i < freq.size(); i++) {
            if(l >= nums.size()) break;
            sum = ((sum) + ((long long)freq[i] * (long long)nums[l])% 1000000007) % 1000000007;
            l++;
        }
        return sum % 1000000007;
    }
};