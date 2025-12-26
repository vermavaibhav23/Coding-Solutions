//213. House Robber II
//C++
//https://leetcode.com/problems/house-robber-ii/

class Solution {
public:
    int helper(vector<int>& nums, int start, int n) {
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(nums[start]);
        
        int prev_of_prev = 0;
        int prev = nums[start];

        for(int i = start + 1; i <= n; i++) {
            dp.push_back(max( prev , nums[i] + prev_of_prev));
            prev_of_prev = prev;
            prev = dp.back();
        }
        return dp.back();
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int n = nums.size()-1;
        return max(helper(nums, 0, n-1), helper(nums, 1, n));
    }
};