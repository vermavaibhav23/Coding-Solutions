//Max Area of Island
//Compiler - C++
//https://leetcode.com/problems/max-area-of-island/


class Solution {
public:
    void dfs(vector<vector<int>>& grid, int xsize, int ysize, int i, int j, int& area) {
        grid[i][j] = 0;
        area++;
        if(i>0 && grid[i-1][j] == 1) {    //up
            dfs(grid,xsize,ysize,i-1,j,area);
        }
        if(i<(ysize - 1) && grid[i+1][j] == 1) {    //down
            dfs(grid,xsize,ysize,i+1,j,area);
        }
        if(j>0 && grid[i][j-1] == 1) {    //left
            dfs(grid,xsize,ysize,i,j-1,area);
        }
        if(j<(xsize - 1) && grid[i][j+1] == 1) {    //right
            dfs(grid,xsize,ysize,i,j+1,area);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int xsize = grid[0].size();
        int ysize = grid.size();
        int ans = 0;
        
        for(int i=0; i<ysize; i++) {
            for(int j=0; j<xsize; j++) {
                if(grid[i][j] == 1) {
                    int area = 0;
                    dfs(grid, xsize, ysize, i, j, area);
                    if(area > ans) {
                        ans = area;
                    }
                } 
            }
        }
        return ans;
    }
};