//Is Graph Bipartite?
//Compiler - C++
//https://leetcode.com/problems/is-graph-bipartite/?envType=problem-list-v2&envId=union-find

class Solution {
public:
    void helper(vector<vector<int>>& adj, vector<bool>& visited, string color, int src, vector<string>&colours) {
        visited[src] = true;
        colours[src] = color;
        for(auto it: adj[src]) {
            if(visited[it]) continue;
            if(color == "red") {
                helper(adj, visited, "blue", it, colours);
            }
            else helper(adj, visited, "red", it, colours);
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<string>colours(graph.size(), "null");
        string color = "red";
        vector<bool>visited(graph.size(), false);
        for(int i=0; i<graph.size(); i++) {
            if(visited[i] == false) {
                helper(graph, visited, color, i, colours);
            }
        }
        for(int i=0; i<graph.size(); i++) {
            for(auto it: graph[i]) {
                if(colours[i] == colours[it]) {
                    return false;
                }
            }
        }
        return true;
    }
};