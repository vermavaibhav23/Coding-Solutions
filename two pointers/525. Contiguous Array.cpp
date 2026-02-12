//525. Contiguous Array
//C++
//https://leetcode.com/problems/contiguous-array/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> diff;
        int no_ones = 0;
        int no_zeros = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) no_zeros++;
            else if(nums[i] == 1) no_ones++;

            if(no_ones - no_zeros == 0) {
                ans = max(ans, i + 1);
            }
            else if(diff.count(no_ones - no_zeros)) {
                ans = max(ans, i - diff[no_ones - no_zeros]);
            }
            else {
                diff[no_ones - no_zeros] = i;
            }
        }
        return ans;
    }
};