LeetCode - Richest Customer Wealth
Compiler - C++
https://leetcode.com/problems/richest-customer-wealth/?envType=problem-list-v2&envId=array

class Solution {
    public int maximumWealth(int[][] accounts) {
        int i = accounts.length;
        int j = accounts[0].length;
        int max=0;
        for (int r=0 ; r<i ; r++) {
            int w=0;
            for (int c=0; c<j ; c++) {
                w = w + accounts [r][c];
            }
            if (w>max){
                max = w;
            }
        }
        return max;
    }
}