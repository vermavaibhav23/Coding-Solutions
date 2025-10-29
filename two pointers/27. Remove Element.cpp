//27. Remove Element
//Compiler - C++
//https://leetcode.com/problems/remove-element/description/?envType=problem-list-v2&envId=two-pointers

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        int no = 0;
        for(int i = 0 ; i < nums.size(); i++) {
            if(nums[i] != val) {
                nums[index] = nums[i];
                index++;
            }
            else no++;
        }
        return nums.size() - no;
    }
};