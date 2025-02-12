LeetCode - Number of Good Pairs
Compiler - C++
https://leetcode.com/problems/number-of-good-pairs/description/?envType=problem-list-v2&envId=array

class Solution {
    public int numIdenticalPairs(int[] nums) {
        int n = nums.length;
        int c=0;
        int j=1;
        for (int i=0; i<j; i++) {
            for (j=(i+1); j<n; j++) {
                if (nums[i] == nums[j]) {
                    c++ ;
                }
            }
        
        }
        System.out.print(c);
        return c;
    }
}