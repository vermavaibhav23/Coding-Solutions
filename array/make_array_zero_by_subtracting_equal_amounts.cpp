LeetCode - Make Array Zero by Subtracting Equal Amounts
Compiler - C++
https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/description/?envType=problem-list-v2&envId=array

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int x=0, count=0;
        set <int> s;
        while (!all_of(nums.begin(), nums.end(), [](int i){ return i == 0; })) {
            count++;
            for (int j=0; j< nums.size(); j++) {
                s.insert(nums[j]);
            }
            for (auto it: s) {
                if (it > 0) {
                    x = it;
                    break;
                }
            }
            for (int i=0; i< nums.size(); i++) {
                if (nums[i] != 0) {
                    nums[i] = nums[i] - x;
                }
            }
            s.clear();
        }
    return count;
    }
};