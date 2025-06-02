//Number of Provinces
//Compiler - C++
//https://leetcode.com/problems/number-of-provinces/description/

class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&adj, vector<bool>&visited, int src) {
        visited[src] = true;
        for(auto it: adj[src]) {
            if(visited[it] == false) {
                dfs(adj, visited, it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>>adj;

        for(int i=0; i<isConnected.size(); i++) {
            for(int j=0; j<isConnected[0].size(); j++) {
                if(isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<bool>visited(isConnected.size(), false);
        int count = 0;
        for(int i=0; i< isConnected.size(); i++) {
            if(visited[i] == false) {
                count++;
                dfs(adj, visited, i);
            }
        }
        return count;
    }
};