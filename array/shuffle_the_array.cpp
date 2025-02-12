LeetCode - Shuffle the Array
Compiler - C++
https://leetcode.com/problems/shuffle-the-array/description/?envType=problem-list-v2&envId=array

class Solution {
    public int[] shuffle(int[] nums, int n) {
        int l = nums.length;
        n = l/2 ;
        int [] arr = new int[ l ];

        for (int i=0 ; i < n; i++) {
            arr [ 2*i ] = nums [ i ] ;
            arr[(2*i) + 1] = nums[i + n];
        }
    return arr;           
    }
    
}