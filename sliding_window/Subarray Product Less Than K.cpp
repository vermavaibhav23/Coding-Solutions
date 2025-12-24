//Subarray Product Less Than K
//Compiler - C++
//https://leetcode.com/problems/subarray-product-less-than-k/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int prod = 1;
        int count = 0;
        while(r < nums.size()) {
            prod = prod * nums[r];
            while(prod >= k && l <= r) {
                prod = prod / nums[l];
                l++;
            }
            count += r - l + 1;
            r++;
        }
        return count;
    }
};