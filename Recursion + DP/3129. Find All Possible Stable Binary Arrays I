//3129. Find All Possible Stable Binary Arrays I
//C++
//https://leetcode.com/problems/find-all-possible-stable-binary-arrays-i/submissions/1946761564/

class Solution {
public:

    // vector<vector<vector<long long>>> dp(201, vector<vector<long long>>(201, vector<long long> (2, -1)));
    int dp[201][201][201];
    long long helper(int zero, int one, int lastused, int limit) {
        if(zero < 0 || one < 0) return 0;
        if(zero == 0 && one == 0) return 1;
        if(dp[zero][one][lastused] != -1) return dp[zero][one][lastused];
        long long count = 0;
        if(lastused == 1 ) {
            for(int i = 1; i <= min(limit, zero); i++) {
                long long add_i_zeros =  helper(zero - i, one, 0, limit);
                count += add_i_zeros % 1000000007;
            }
        }
        if(lastused == 0 ) {
            for(int i = 1; i <= min(limit, one); i++) {
                long long add_i_ones =  helper(zero, one - i, 1, limit);
                count += add_i_ones % 1000000007;
            }
        }
        return dp[zero][one][lastused] = count % 1000000007;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        // vector<vector<vector<long long>>> dp(201, vector<vector<long long>>(201, vector<long long> (2, -1)));
        memset(dp, -1, sizeof(dp));
        return (helper(zero, one, 1, limit) + helper(zero, one, 0, limit))  % 1000000007;
    }
};