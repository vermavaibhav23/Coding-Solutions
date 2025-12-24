//1984. Minimum Difference Between Highest and Lowest of K Scores
//Compiler - C++
//https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = k-1;
        if(k == 0) return 0;
        int ans = INT_MAX;
        while(r < nums.size()) {
            ans = min(ans, nums[r] - nums[l]);
            l++;
            r++;
        }
        return ans;
    }
};