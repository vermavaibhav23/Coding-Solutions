LeetCode - Sum of Unique Elements
Compiler - C++
https://leetcode.com/problems/sum-of-unique-elements/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int sum = 0, key = 0;
        map<int,int>frequency;
        for (int i=0; i<nums.size(); i++) {
            frequency[nums[i]]++;
        }

        for (auto j=frequency.begin(); j!=frequency.end(); j++) {
            if (j->second == 1) {
                key = j->first;
                sum += key;
            }
        }
    return sum;
    }
};