//64. Minimum Path Sum (top down)
//C++
//https://leetcode.com/problems/minimum-path-sum/description/

class Solution {
public:
    int helper(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& memo) {
        if(i > grid.size()-1 || j > grid[0].size()-1) return INT_MAX;
        if(memo[i][j] != -1) return memo[i][j];
        if(i == grid.size()-1 && j == grid[0].size()-1) return grid[i][j];
        int right = helper(grid, i, j+1, memo);
        int down = helper(grid, i+1, j, memo);
        return memo[i][j] = min(right, down) + grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> memo(grid.size(), vector<int>(grid[0].size(), -1));
        return helper(grid, 0, 0, memo);
    }
};