//523. Continuous Subarray Sum
//Compiler : C++
//https://leetcode.com/problems/continuous-subarray-sum/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prev = 0;
        unordered_map<int, int> idx;
        idx[0] = -1;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            int sum = prev + nums[i];
            int rem = sum % k;
            if(idx.count(rem) && i - idx[rem] >= 2) return true;
            if(idx.count(rem) == false) idx[rem] = i;
            prev = sum;
        }
        return false;
    }
};