//Graph Valid Tree
//Compiler - C++
//https://leetcode.com/problems/graph-valid-tree/?envType=problem-list-v2&envId=graph


class Solution {
public:
    bool helper(vector<vector<int>>& adj, vector<int>& visited, int src, int parent) {
        if(visited[src] != -1 && src != parent) return true;
        visited[src] = 0;
        for(auto it:adj[src]) {
            if(it == parent) continue;
            bool ans = helper(adj, visited, it, src);
            if(ans == true) return true;
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() == 0 && n>1) return false;
        if(edges.size() == 0 && n<=1) return true;
        vector<vector<int>> adj(n);
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>visited(n, -1);
        bool ans = helper(adj, visited, edges[0][0], -1);
        for(int i=0; i<n; i++) {
            if(visited[i] == -1) return false;
        }
        return !ans;
    }
};