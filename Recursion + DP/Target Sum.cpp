//Target Sum
//Compiler - C++
//https://leetcode.com/problems/target-sum/

class Solution {
public:
    int helper(vector<int>& nums, int target, int n) {
        if(n == 0) {
            if(target == 0) {
                return 1;
            }
            else return 0;
        }
        return helper(nums,target-nums[n-1],n-1) + helper(nums,target+nums[n-1],n-1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums,target,nums.size());
    }
};