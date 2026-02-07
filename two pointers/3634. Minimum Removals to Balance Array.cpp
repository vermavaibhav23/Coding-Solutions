//3634. Minimum Removals to Balance Array
//C++
//https://leetcode.com/problems/minimum-removals-to-balance-array/description/?envType=daily-question&envId=2026-02-06

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        if(nums.size() == 1) return 0;
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = 1;
        int max_len = INT_MIN;
        while(r < nums.size()) {
            long long x = (long long)nums[l] * (long long)k;
            if( x >= nums[r] ) {
                max_len = max(max_len, r - l + 1);
                r++;
            }
            else l++;
            if(l == r) r++;
        }
        if(max_len == INT_MIN) return nums.size() - 1;
        return nums.size() - max_len;
    }
};