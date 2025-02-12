LeetCode - Merge Two 2D Arrays by Summing Values
Compiler - C++
https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int>m1,m2;
        vector<vector<int>>result;
        int sum=0;
        for (int i=0 ; i<nums1.size(); i++) {
            m1[nums1[i][0]] = nums1[i][1];
        }
        for (int i=0 ; i<nums2.size(); i++) {
            m2[nums2[i][0]] = nums2[i][1];
        }
        map<int,int>combined;
        for (auto it:m1) {
            combined[it.first]++;
        }
        for (auto it:m2) {
            combined[it.first]++;
        }
        for (auto ti: combined) {
            if (m1.find(ti.first) != m1.end()) {
                sum = m1[ti.first];
            }
            else if (m2.find(ti.first) != m2.end()) {
                sum = m2[ti.first];
            }
            if (ti.second > 1) {
                sum = m1[ti.first] + m2[ti.first];
            }
            result.push_back({ti.first, sum});
        }
    return result;
    }
};