//1091. Shortest Path in Binary Matrix
//Compiler - C++
//https://leetcode.com/problems/shortest-path-in-binary-matrix/

class Solution {
public:
    bool to_go(int i, int j, int n, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        if(i >= 0 && i < n && j >= 0 && j < n && visited[i][j] == false && grid[i][j] == 0) {
            visited[i][j] = true;
            return true;
        }
        return false;
    }
    int helper(vector<vector<int>>& grid, int a, int b, int n) {
        vector<vector<bool>>visited (n, vector<bool>(n, false));
        int ans = 1;
        queue<pair<int, int>> q;
        q.push({a, b});
        visited[a][b] = true;
        while(q.empty() == false) {
            int size = q.size();
            while(size > 0) {
                int i = q.front().first;
                int j = q.front().second;
                if(i == n-1 && j == n-1) return ans;
                q.pop();

                if(to_go(i+1, j, n, grid, visited)) q.push({i+1, j});
                if(to_go(i-1, j, n, grid, visited)) q.push({i-1, j});
                if(to_go(i, j+1, n, grid, visited)) q.push({i, j+1});
                if(to_go(i, j-1, n, grid, visited)) q.push({i, j-1});

                if(to_go(i+1, j+1, n, grid, visited)) q.push({i+1, j+1});
                if(to_go(i-1, j-1, n, grid, visited)) q.push({i-1, j-1});
                if(to_go(i+1, j-1, n, grid, visited)) q.push({i+1, j-1});
                if(to_go(i-1, j+1, n, grid, visited)) q.push({i-1, j+1});

                size--;
            } 
            ans++;
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] != 0) return -1;
        return helper(grid, 0, 0, grid.size());
    }
};