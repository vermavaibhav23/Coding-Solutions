LeetCode - Intersection of Two Arrays
Compiler - C++
https://leetcode.com/problems/intersection-of-two-arrays/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1,s2;
        vector<int>v,result;
        for (int i=0; i<nums1.size(); i++) {
            s1.insert(nums1[i]);
        }
         for (int i=0; i<nums2.size(); i++) {
            s2.insert(nums2[i]);
        }
        for (auto it:s1) {
            if(s2.find(it) != s2.end()) {
                v.push_back(it);
            }
        }
        set<int>final(v.begin(), v.end());
        for (auto ti:final) {
            result.push_back(ti);
        }
    return result;
    }
};