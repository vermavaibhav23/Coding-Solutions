//53. Maximum Subarray
//C++
//https://leetcode.com/problems/maximum-subarray/description/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int currSum = 0;
        int maxSum = 0;
        int max_num = INT_MIN;
        for(auto it: nums) {
            if(it <= 0 && it > max_num) max_num = it;
            currSum += it;
            maxSum = max(maxSum, currSum);
            if(currSum < 0) currSum = 0;
        }
        if(maxSum == 0) return max_num;
        return maxSum;
    }
};