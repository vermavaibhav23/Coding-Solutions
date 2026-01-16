//63. Unique Paths II
//C++
//https://leetcode.com/problems/unique-paths-ii/


class Solution {
public:
    int helper(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>>& memo) {
        if(i >= obstacleGrid.size() || j >= obstacleGrid[0].size() || obstacleGrid[i][j] == 1) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        if(i == obstacleGrid.size()-1 && j == obstacleGrid[0].size()-1) return 1;
        int right = helper(obstacleGrid, i, j+1, memo);
        int down = helper(obstacleGrid, i+1, j, memo);
        return memo[i][j] = right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> memo(101, vector<int>(101, -1));
        return helper(obstacleGrid, 0, 0, memo);
    }
};