//1594. Maximum Non Negative Product in a Matrix (Bottom Up)
//C++
//https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        vector<vector<pair<long long, long long>>> memo(grid.size(), vector<pair<long long, long long>> (grid[0].size()));
        for(int i = 0; i < grid[0].size(); i++) {
            if(i == 0) {
                pair<long long, long long> temp;
                temp.first = grid[0][i];
                temp.second = grid[0][i];
                memo[0][i] = temp;
            }
            else {
                pair<long long, long long> temp;
                temp.first = grid[0][i] * memo[0][i-1].first ;
                temp.second = grid[0][i] * memo[0][i-1].second;
                memo[0][i] = temp;
            }
        }
        for(int i = 1; i < grid.size(); i++) {
            pair<long long, long long> temp;
            temp.first = grid[i][0] * memo[i-1][0].first ;
            temp.second = grid[i][0] * memo[i-1][0].second;
            memo[i][0] = temp;
        }
        for(int i = 1; i < grid.size(); i++) {
            for(int j = 1; j < grid[0].size(); j++) {
                long long a = memo[i-1][j].first * grid[i][j];
                long long b = memo[i-1][j].second * grid[i][j];
                long long c = memo[i][j-1].first * grid[i][j];
                long long d = memo[i][j-1].second * grid[i][j];

                pair<long long, long long> temp;
                temp.first = min({a,b,c,d});
                temp.second = max({a,b,c,d});
                memo[i][j] = temp;
            }
        }
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                cout<<"{"<<memo[grid.size()-1][grid[0].size()-1].first<<", "<<memo[grid.size()-1][grid[0].size()-1].second<<"}"<<endl;
            }
        }
        
        if(memo[grid.size()-1][grid[0].size()-1].second < 0) return -1;
        return memo[grid.size()-1][grid[0].size()-1].second % 1000000007;
    }
};