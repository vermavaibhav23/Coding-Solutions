//1594. Maximum Non Negative Product in a Matrix
//C++
//https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/

class Solution {
public:
    pair<long long, long long> helper(vector<vector<int>>& grid, int i, int j, vector<vector<pair<long long,long long>>>& memo) {
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return {grid[i][j], grid[i][j]};
        }
        if (memo[i][j].first != -1 && memo[i][j].second != -1) return memo[i][j];
        long long max_val_right = INT_MIN;
        long long min_val_right = INT_MAX;
        if(j+1 < grid[0].size()) {
            pair<long long, long long> right = helper(grid, i, j + 1, memo);
            min_val_right = min(right.first * grid[i][j], right.second * grid[i][j]); 
            max_val_right = max(right.first * grid[i][j], right.second * grid[i][j]);
        }
        long long max_val_down = INT_MIN;
        long long min_val_down = INT_MAX;
        if(i+1 < grid.size()) {
            pair<long long ,long long> down = helper(grid, i+1, j, memo);
            min_val_down = min(down.first * grid[i][j], down.second * grid[i][j]); 
            max_val_down = max(down.first * grid[i][j], down.second * grid[i][j]);
        }
        return memo[i][j] = {min(min_val_down, min_val_right), max(max_val_right, max_val_down)};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        vector<vector<pair<long long,long long>>> memo(grid.size(), vector<pair<long long,long long>>(grid[0].size(), {-1, -1}));
        pair<long long,long long> ans = helper(grid, 0, 0, memo);
        if(ans.second < 0) return -1;
        return ans.second % 1000000007;
    }
};