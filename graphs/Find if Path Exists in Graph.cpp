//Find if Path Exists in Graph
//Compiler - C++
//https://leetcode.com/problems/find-if-path-exists-in-graph/description/?envType=problem-list-v2&envId=graph

class Solution {
public:
    bool dfs(unordered_map<int, vector<int>> &graph, vector<bool>& v, int n, int src, int des) {
        if(src == des) {
            return true;
        }
        v[src] = true;
        for(auto neighbour: graph[src]) {
            if(v[neighbour] == false) {
                if(dfs(graph,v,n,neighbour,des)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        vector<bool>v(n,false);
        for(auto edge: edges) {
            int u=edge[0], v=edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return dfs(graph, v, n, source, destination);
    }
};