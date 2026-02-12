//3719. Longest Balanced Subarray I
//Compiler - C++
//https://leetcode.com/problems/longest-balanced-subarray-i/

class Solution {
public:

    int longestBalanced(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            unordered_set<int> odd;
            unordered_set<int> even;
            for(int j = i; j < nums.size(); j++) {
                if(nums[j] % 2 == 0) even.insert(nums[j]);
                else odd.insert(nums[j]);
                if(odd.size() == even.size()) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};