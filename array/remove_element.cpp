LeetCode - Remove Element
Compiler - C++
https://leetcode.com/problems/remove-element/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        int size = nums.size() ;
        for (int i=0; i<size; i++) {
            if (nums[i] != val) {
                nums[count] = nums[i];
                count++ ;
            }
        }
    return count;
    }
};