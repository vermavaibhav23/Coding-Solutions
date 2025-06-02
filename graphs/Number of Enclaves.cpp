//Number of Enclaves
//Compiler - C++
//https://leetcode.com/problems/number-of-enclaves/

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>&visited, int& count, int xsize, int ysize){
        visited[i][j] = true;
        count++;
        if(i>0 && grid[i-1][j] == 1 && visited[i-1][j] == false) { //up
            dfs(grid, i-1, j, visited, count, xsize, ysize);
        }
        if(i<ysize-1 && grid[i+1][j] == 1 && visited[i+1][j] == false) { //down
            dfs(grid, i+1, j, visited, count, xsize, ysize);
        }
        if(j>0 && grid[i][j-1] == 1 && visited[i][j-1] == false) { //left
            dfs(grid, i, j-1, visited, count, xsize, ysize);
        }
        if(j<xsize-1 && grid[i][j+1] == 1 && visited[i][j+1] == false) { //right
            dfs(grid, i, j+1, visited, count, xsize, ysize);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int land = 0;
        int xsize = grid[0].size();
        int ysize = grid.size();
        for(int i=0; i<ysize; i++) {
            for(int j=0; j<xsize; j++) {
                if(grid[i][j] == 1) {
                    land++;
                }
            }
        }
        int boundry = 0;
        vector<vector<bool>>visited(ysize,vector<bool>(xsize, false));
        for(int i=0; i<xsize; i++) { //1st row
            if(grid[0][i] == 1 && visited[0][i] == false) {
                int count = 0;
                dfs(grid, 0, i, visited, count, xsize, ysize);
                boundry = boundry + count;
            } 
        }
        for(int i=0; i<xsize; i++) { //last row
            if(grid[ysize-1][i] == 1 && visited[ysize-1][i] == false) {
                int count = 0;
                dfs(grid, ysize-1, i, visited, count, xsize, ysize);
                boundry = boundry + count;
            } 
        }
        for(int i=0; i<ysize; i++) { //1st column
            if(grid[i][0] == 1 && visited[i][0] == false) {
                int count = 0;
                dfs(grid, i, 0, visited, count, xsize, ysize);
                boundry = boundry + count;
            } 
        }
        for(int i=0; i<ysize; i++) { //last column
            if(grid[i][xsize-1] == 1 && visited[i][xsize-1] == false) {
                int count = 0;
                dfs(grid, i, xsize-1, visited, count, xsize, ysize);
                boundry = boundry + count;
            } 
        }
        return (land - boundry);
    }
};