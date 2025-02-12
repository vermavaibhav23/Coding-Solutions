LeetCode - Search Insert Position
Compiler - C++
https://leetcode.com/problems/search-insert-position/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        for (int i=0; i < size; i++) {
            if (target == nums[i]) {
                return i;
            }
        }
        int z=0;
        for (target; target>=nums[0] ; target--) {
            z=0;
            for (z; z<size; z++) {
                if (target == nums[z]) {
                return (z+1);
                }
            }
        }
        return 0;
    }
};