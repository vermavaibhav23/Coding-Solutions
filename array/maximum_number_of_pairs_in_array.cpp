LeetCode - Maximum Number of Pairs in Array
Compiler - C++
https://leetcode.com/problems/maximum-number-of-pairs-in-array/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        map<int,int>f;
        int odd=0, pair=0;
        vector<int>v;
        for (int i=0; i< nums.size(); i++) {
            f[nums[i]]++;
        }

        for (auto it:f) {
            if (it.second % 2 != 0) {
                odd++;
            }
        }

        for (auto ti:f) {
            if (ti.second >= 2) {
                pair = pair + (ti.second / 2);
            }
        }
        v.push_back(pair);
        v.push_back(odd);
    return v;
    }
};