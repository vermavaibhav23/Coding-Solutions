//Merge Sorted Array
//Compiler - C++
//https://leetcode.com/problems/merge-sorted-array/?envType=problem-list-v2&envId=sorting

class Solution {
public:
    int zeroindex(vector<int>& nums1)  {
        int index = nums1.size() - 1;
        for(int i = nums1.size() - 1; i >=0 ; i--) {
            if (nums1[i] != 0) {
                return index;
            }
            if(nums1[i] == 0) {
                index = i;
            }
        }
        return 0;
    }
    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int a=0;
        int index=zeroindex(nums1);
        if(nums2.size() < 1) {
            return;
        }
        for(int i=0; i< nums1.size() && a< nums2.size(); i++) {
            if(i>= index && nums1[i] == 0) {
                nums1[i] = nums2[a];
                a++;
            }
            else if(nums1[i] >= nums2[a]) {
                index = zeroindex(nums1);
                for(int z = index; z>i; z--) {
                    nums1[z] = nums1[z-1];
                    nums1[z-1] = nums2[a];
                }
                a++;
            }
        }
    
    }
};