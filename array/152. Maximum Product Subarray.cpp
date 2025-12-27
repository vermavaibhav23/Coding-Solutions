//152. Maximum Product Subarray
//C++
//https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int l = 0;
        int r = 0;
        int prod = 1;
        int max_prod = INT_MIN;
        int zeros = 0;
        while(r < nums.size()) {
            if(nums[r] == 0) {
                while(l < r-1) {
                    prod = prod/nums[l];
                    max_prod = max(max_prod, prod);
                    l++;
                }
                r++;
                l = r;
                zeros++; 
                prod = 1; 
                continue;
            }
            prod = nums[r] * prod;
            max_prod = max(max_prod, prod);
            r++;
        }
        while(l < nums.size()-1) {
            prod = prod/nums[l];
            max_prod = max(max_prod, prod);
            l++;
        }
        if(zeros == nums.size() || (max_prod < 0 && zeros > 0) ) return 0;
        return max_prod;
    }
};