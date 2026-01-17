//64. Minimum Path Sum (bottom up)
//C++
//https://leetcode.com/problems/minimum-path-sum/description/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> memo(grid.size(), vector<int>(grid[0].size()));
        for(int i = 0; i < grid[0].size(); i++) {
            if (i == 0) memo[0][i] = grid[0][0];
            else memo[0][i] = grid[0][i] + memo[0][i-1];
        }
        for(int i = 1; i < grid.size(); i++) {
            memo[i][0] = grid[i][0] + memo[i-1][0];
        }
        for(int i = 1; i < grid.size(); i++) {
            for(int j = 1; j < grid[0].size(); j++) {
                memo[i][j] = min(memo[i-1][j] , memo[i][j-1]) + grid[i][j];
            }
        }
        return memo[grid.size()-1][grid[0].size()-1];
    }
};