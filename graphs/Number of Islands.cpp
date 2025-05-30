//Number of Islands
//Compiler - C++
//https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    void dfs(vector<vector<char>>& grid,int m,int n,int i,int j){
        if(grid[i][j] == '1'){
            grid[i][j] = '0';
        }
        if(i>0 && grid[i-1][j] == '1') {
            dfs(grid,m,n,i-1,j); //up
        }
        if(j<n-1 && grid[i][j+1] == '1') {
            dfs(grid,m,n,i,j+1); //right
        }
        if(j>0 && grid[i][j-1] == '1') {
            dfs(grid,m,n,i,j-1); //left
        }
        if(i<m-1 && grid[i+1][j] == '1') {
            dfs(grid,m,n,i+1,j); //down
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(grid,m,n,i,j);
                }
            }
        }
    return ans;
    }
};