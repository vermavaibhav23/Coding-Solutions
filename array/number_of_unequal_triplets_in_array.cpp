LeetCode - Number of Unequal Triplets in Array
Compiler - C++
https://leetcode.com/problems/number-of-unequal-triplets-in-array/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int c=0;
        int size = nums.size();
        for (int i=0; i<= (size - 3); i++){
            for (int j= i+1; j<= (size-2); j++) {
                for (int z=j+1; z<size; z++) {
                    if (nums[i] != nums[j] && nums[j] != nums[z] && nums[z] != nums[i]) {
                        c++;
                    }
                }
            }
        }
    return c;
    }
};