LeetCode - Relative Sort Array
Compiler - C++
https://leetcode.com/problems/relative-sort-array/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
     map<int,int>m1;
     set<int>m2;
     vector<int>v;
        for (int i=0; i<arr1.size(); i++) {
            m1[arr1[i]]++;
        } 
        for (int i=0; i<arr2.size(); i++) {
            m2.insert(arr2[i]);
        } 
        for (int j=0; j<arr2.size(); j++) {
            if (m1.find(arr2[j]) != m1.end()) {
                for (int z=0; z < (m1[arr2[j]]) ; z++) {
                    v.push_back(arr2[j]);
                }
            }
        } 
        for (auto it:m1) {
            if (m2.find(it.first) == m2.end()) {
                for (int z=0; z<it.second; z++) {
                     v.push_back(it.first);
                }
            }
        }
    return v;
    }
};