//2300. Successful Pairs of Spells and Potions
//Compiler - C++
//https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/

class Solution {
public:
    int helper(vector<int>& nums, long long mul, long long target) {
        int l = 0;
        int r = nums.size() - 1;
        int idx = INT_MAX;
        while(l <= r) {
            int mid = l + (r - l)/2;
            if((long long)nums[mid] * (long long)mul >= target) {
                idx = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        if(idx == INT_MAX) return 0;
        return nums.size() - idx;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(), potions.end());
        for(int i = 0; i < spells.size(); i++) {
            long long mul = spells[i];
            long long count = helper(potions, mul, success);
            ans.push_back(count);
        }
        return ans;
    }
};