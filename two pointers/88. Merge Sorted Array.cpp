//88. Merge Sorted Array
//Compiler - C++
//https://leetcode.com/problems/merge-sorted-array/editorial/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0) {
            nums1 = nums2;
            return;
        }
        if(n == 0) {
            return;
        }
        vector<int>ans;
        int a = m-1;
        int b = n-1;
        int c = nums1.size() - 1;
        while(a >= 0 && b >= 0 ) {
            if(nums1[a] > nums2[b]) {
                nums1[c] = nums1[a];
                a--;
            }
            else {
                nums1[c] = nums2[b];
                b--;
            }
            c--;
        }
        while (b >= 0) {
            nums1[c] = nums2[b];
            b--;
            c--;
        }
        return;
    }
};