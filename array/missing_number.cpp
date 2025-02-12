LeetCode - Missing Number
Compiler - C++
https://leetcode.com/problems/missing-number/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        set <int> s1;
        for (int i=0; i< size; i++) {
            s1.insert(nums[i]);
        }
       
        int var = 0;
        for (auto it = s1.begin(); it != s1.end(); ++it, var++) {
            auto find = s1.find(var);
            if (find == s1.end()) {
                return var;
            }
        }
    return size;
    }
};