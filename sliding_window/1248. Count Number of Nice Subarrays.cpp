//1248. Count Number of Nice Subarrays
//Compiler : C++
//https://leetcode.com/problems/count-number-of-nice-subarrays/

class Solution {
public:
    int atmostk(vector<int>& nums, int k) {
        int odd = 0;
        int l = 0;
        int r = 0;
        int ans = 0;
        while(r < nums.size()) {
            if(nums[r] % 2 != 0) odd++;
            while(l <= r && odd > k) {
                if(nums[l] % 2 != 0) odd--;
                l++;
            }
            ans = ans + (r - l + 1);
            r++;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmostk(nums, k) - atmostk(nums, k-1);
    }
};