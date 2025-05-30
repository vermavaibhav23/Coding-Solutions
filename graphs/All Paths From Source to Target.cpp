//Directed Graph Cycle
//Compiler - C++
//https://leetcode.com/problems/all-paths-from-source-to-target/


class Solution {
public:
    void dfs(vector<vector<int>>&adj, vector<int>path, vector<vector<int>>&ans, int src, int dest) {
        path.push_back(src);
        if(src == dest) {
            ans.push_back(path);
        }
        else {
            for(auto it: adj[src]) {
                dfs(adj,path,ans,it,dest);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>adj(graph.size());
        int i=0;
        for(auto edge: graph) {
            adj[i] = edge;
            i++;
        }
        vector<vector<int>>ans;
        vector<int>path;
        dfs(adj,path,ans,0,adj.size()-1);
        return ans;
    }
};