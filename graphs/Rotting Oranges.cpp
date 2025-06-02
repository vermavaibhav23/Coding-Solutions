//Rotting Oranges
//Compiler - C++
//https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int xsize = grid[0].size();
        int ysize = grid.size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>> visited(ysize, vector<int>(xsize, -1));
        for(int i=0; i<ysize; i++) {
            for(int j=0; j<xsize; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i,j},0});
                    visited[i][j] = 2;
                }
            }
        }
        while(!q.empty()) {
            pair<pair<int,int>,int>u = q.front();
            q.pop();
            pair<int,int>index = u.first;
            int x = index.first;
            int y = index.second;
            time = max(u.second, time);
            if(x>0 && grid[x-1][y] == 1 && visited[x-1][y] == -1) { //up
                q.push({{x-1,y},u.second+1});
                visited[x-1][y] = 1;
            }
            if(x<(ysize-1) && grid[x+1][y] == 1 && visited[x+1][y] == -1) { //down
                q.push({{x+1,y},u.second+1});
                visited[x+1][y] = 1;
            }
            if(y>0 && grid[x][y-1] == 1 && visited[x][y-1] == -1) { //left
                q.push({{x,y-1},u.second+1}); //left
                visited[x][y-1] = 1;
            }
            if(y<(xsize-1) && grid[x][y+1] == 1 && visited[x][y+1] == -1) { //right
                q.push({{x,y+1},u.second+1});
                visited[x][y+1] = 1;
            }
        }
        for(int i=0; i<ysize; i++) {
            for(int j=0; j<xsize; j++) {
                if(grid[i][j] == 1 && visited[i][j] == -1) {
                    return -1;
                }
            }
        }
        return time;
        
    }
};