LeetCode - N-Repeated Element in Size 2N Array
Compiler - C++
https://leetcode.com/problems/n-repeated-element-in-size-2n-array/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        map<int,int>f;
        for (int i=0 ; i< nums.size(); i++) {
            f[nums[i]] ++ ;
        }
        for (auto it: f) {
            if (it.second != 1) {
                return it.first;
            }
        }
    return 0;
    }
};