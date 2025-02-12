LeetCode - Next Greater Element I
Compiler - C++
https://leetcode.com/problems/next-greater-element-i/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        for (int i = 0; i< nums1.size(); i++){
            for (int j=0; j< nums2.size(); j++) {
                int z = j+1, a=0;
                if (nums1[i] == nums2[j]) {
                    for (z; z< nums2.size(); z++) {
                        if (nums2[z] > nums2[j]) {
                            v.push_back(nums2[z]);
                            a=1;
                            break;
                        }
                    }
                    if (a==0) {
                        v.push_back(-1);
                    }
                }
            }
        }
    return v;
    }
};