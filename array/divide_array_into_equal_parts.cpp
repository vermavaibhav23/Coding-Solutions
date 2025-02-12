LeetCode - Divide Array Into Equal Pairs
Compiler - C++
https://leetcode.com/problems/divide-array-into-equal-pairs/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int,int>m1;
        int c=0;
        for (int i=0; i< nums.size(); i++) {
            m1[nums[i]]++;
        }
        for (auto it:m1) {
            if (it.second % 2 != 0) {
            return false;
            }
        }
    return true;
    }
};