LeetCode - Number of Employees Who Met the Target
Compiler - java
https://leetcode.com/problems/number-of-employees-who-met-the-target/description/?envType=problem-list-v2&envId=array

class Solution {
    public int numberOfEmployeesWhoMetTarget(int[] hours, int target) {
        int n = hours.length;
        int c=0;
        for (int i=0; i<n; i++) {
            if (hours[i]>=target) {
                c++;
            }
        }
        return c;
    }
}