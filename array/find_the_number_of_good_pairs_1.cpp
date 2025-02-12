LeetCode - Find the Number of Good Pairs I
Compiler - C++
https://leetcode.com/problems/find-the-number-of-good-pairs-i/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int c= 0;
        int n = nums1.size();
        int m = nums2.size();
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (nums1[i] % (nums2[j] * k) == 0 )
                c++ ;
            }
        }
    return c;
    }
};