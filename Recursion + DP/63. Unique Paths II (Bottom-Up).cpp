//63. Unique Paths II
//C++
//https://leetcode.com/problems/unique-paths-ii/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size(); 
        vector<vector<int>> memo(m, vector<int>(n));
        bool one = false;
        for(int i = 0; i < obstacleGrid[0].size(); i++) {
            if(obstacleGrid[0][i] == 1) one = true;
            if(one) memo[0][i] = 0;
            else memo[0][i] = 1;
        }
        one = false;
        for(int i = 0; i < obstacleGrid.size(); i++) {
            if(obstacleGrid[i][0] == 1) one = true;
            if(one) memo[i][0] = 0;
            else memo[i][0] = 1;
        }
        for(int i = 1; i < obstacleGrid.size(); i++) {
            for(int j = 1; j < obstacleGrid[0].size(); j++) {   
                if(obstacleGrid[i][j] == 1) memo[i][j] = 0;
                else memo[i][j] = memo[i-1][j] + memo[i][j-1];
            }
        }
        return memo[m-1][n-1];
    }
};