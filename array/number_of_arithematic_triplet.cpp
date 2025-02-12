LeetCode - Number of Arithmetic Triplets
Compiler - C++
https://leetcode.com/problems/number-of-arithmetic-triplets/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int size = nums.size();
        int c=0;
        for (int i=0; i<size; i++) {
            for (int j=1; j<size; j++) {
                for (int k=2; k<size; k++) {
                    if ( (nums[k] - nums[j]) == diff && nums[j] - nums[i] == diff)
                    c++;
                }
            }
        }
    return c;  
    }
};