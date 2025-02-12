LeetCode - Keep Multiplying Found Values by Two
Compiler - C++
https://leetcode.com/problems/keep-multiplying-found-values-by-two/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int c;
        set<int>s (nums.begin(), nums.end());
        for (auto it: s) {
            if (s.find(original) != s.end()) {
                original = original * 2;
            }
            else break;
        }
    return original;
    }
};