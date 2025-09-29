//15. 3Sum
//Compiler - C++
//https://leetcode.com/problems/3sum/?envType=problem-list-v2&envId=two-pointers

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> s;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++) {
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int lock = nums[i];
            int l = i+1;
            int r = nums.size()-1;
            while(l < r) {
                if(nums[l] + nums[r] ==  -1 * lock) {
                    s.push_back({lock, nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1]) {
                        l++;
                    }
                    while (l < r && nums[r] == nums[r - 1]) {
                        r--;
                    }
                    l++;
                    r--;
                }
                else if(nums[l] + nums[r] <  -1 * lock) {
                    l++;
                }
                else r--;
            }
        }
        return s;
    }
};