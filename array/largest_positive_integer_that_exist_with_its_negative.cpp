LeetCode - Largest Positive Integer That Exists With Its Negative
Compiler - C++
https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int>j;
        int p= -1;
        for (int i=0; i<nums.size() ; i++) {
            j.insert(nums[i]);
        }
        for (auto it:j){
            if (j.find(-it) != j.end()) {
                p = it;
            }
        }
    return p;
    }
};