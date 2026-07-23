//416. Partition Equal Subset Sum
//Compiler : C++
//https://leetcode.com/problems/partition-equal-subset-sum/description/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it: nums) sum += it;
        if(sum % 2 != 0) return false;
        int tar = sum/2;
        vector<vector<int>> dp(nums.size() + 1, vector<int> (tar + 1, false));

        dp[0][0] = true;
        for(int i = 0; i < dp.size(); i++) {
            dp[i][0] = true;
        }
        for(int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[i].size(); j++) {
                if(nums[i - 1] == j || dp[i-1][j]) dp[i][j] = true;
                else {
                    int check = j - nums[i-1];
                    if(check >= 0 && check < dp[i].size()) {
                        if(dp[i-1][check] == true) dp[i][j] = true;
                    }
                }
            }
        }
        return dp[nums.size()][tar];
    }
};