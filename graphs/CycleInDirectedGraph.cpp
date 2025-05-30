//CycleInDirectedGraph
//Compiler - C++
//https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

class Solution {
  public:
    bool dfs(vector<vector<int>>&adj, vector<bool>visited, vector<bool>revisited, int src, int parent) {
        if(visited[src] == true && revisited[src] == true) {
            return true;
        }
        visited[src] = true;
        revisited[src] = true;
        for(auto it: adj[src]) {
            if(0==0) {
                bool ans = dfs(adj,visited,revisited, it, src);
                if(ans){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector< vector<int> >adj(V);
        for(auto edge: edges) {
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
        }
        vector<bool>visited(V, false);
        for(int i=0; i<V; i++) {
            if(visited[i] == false) {
                vector<bool>revisited(V, false);
                bool ans = dfs(adj,visited,revisited, i, -1);
                if(ans) {
                    return true;
                }
            }
        }
        return false;
    }
};