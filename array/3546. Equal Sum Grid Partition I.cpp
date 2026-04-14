//3546. Equal Sum Grid Partition I
//C++
//https://leetcode.com/problems/equal-sum-grid-partition-i/

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long total = 0;

        vector<long long> col(grid[0].size(), 0);
        vector<long long> row(grid.size(), 0);
        
        for(int i = 0; i < grid.size(); i++) {
            long long row_sum = 0;
            for(int j = 0; j < grid[0].size(); j++) {
                total += grid[i][j];
                row_sum += grid[i][j];
                col[j] += grid[i][j];
            }
            row[i] = row_sum;
        }

        long long temp_sum = 0;
        for(int i = 0; i < row.size(); i++) {
            temp_sum += row[i];
            if(total == temp_sum * 2) return true;
        }
        temp_sum = 0;
        for(int i = 0; i < col.size(); i++) {
            temp_sum += col[i];
            if(total == temp_sum * 2) return true;
        }
        return false;
    }
};