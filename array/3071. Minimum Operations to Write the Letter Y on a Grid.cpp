//3071. Minimum Operations to Write the Letter Y on a Grid
//Compiler - C++
//https://leetcode.com/problems/minimum-operations-to-write-the-letter-y-on-a-grid/?envType=company&envId=visa&favoriteSlug=visa-all

class Solution {
public:
    bool isinY(int i, int j, int n) {
        if(i == j && i <= n/2) return true;
        if(i > n/2 && j == n/2) return true;
        if(i < n/2 && i + j == n-1) return true;
        return false;
    }
    
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int minimum = INT_MAX;
        int y_cells = 0;
        int g_cells = 0;
        vector<int>Y(3,0);
        vector<int>G(3,0);
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if( isinY(i, j, grid.size()) ) {
                    y_cells++;
                    Y[grid[i][j]]++;
                }
                else {
                    G[grid[i][j]]++;
                    g_cells++;
                }
            }
        }

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(i == j) continue;
                minimum = min(minimum, (y_cells - Y[i]) + (g_cells - G[j]) );
            }
        }
        return minimum;
    }
};