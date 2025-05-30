//Undirected Graph Cycle
//Compiler - C++
//https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1


class Solution {
  public:
    bool dfs(vector<vector<int>>&adj, vector<bool>&visited, int src, int parent){
        visited[src] = true;
        
        for(auto it: adj[src]) {
            if(visited[it] == false) {
                bool ans = dfs(adj,visited,it,src);
                if(ans){
                    return true;
                }
            }
            else if(visited[it] == true && it != parent) {
                return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V);
        for(auto edge: edges) {
            int u= edge[0];
            int v= edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool ans = false;
        vector<bool>visited(V,false);
        for(int i=0; i<V; i++) {
            if(visited[i] == false) {
                ans = dfs(adj, visited, i, -1);
                if(ans) {
                    return true;
                }
            }
        }
        return ans;
    }
};