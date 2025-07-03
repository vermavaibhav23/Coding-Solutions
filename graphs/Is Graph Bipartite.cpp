//Is Graph Bipartite?
//Compiler - C++
//https://leetcode.com/problems/is-graph-bipartite/?envType=problem-list-v2&envId=union-find

class Solution {
public:
    bool helper(vector<vector<int>>& adj, vector<string>& color, int src, string c) {
        color[src] = c;
        string nextcolor;
        if(color[src] == "red") {
            nextcolor = "blue";
        }
        else if(color[src] == "blue") {
            nextcolor = "red";
        }
        for(auto it: adj[src]) {
            if(color[it] == c) return false;
            if(color[it] == "null") {
                if ( helper(adj, color, it, nextcolor) == false ) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<string>color(graph.size(), "null");
        for(int i=0 ; i< graph.size(); i++) {
            if(color[i] == "null") {
                bool ans = helper(graph, color, i, "red");
                if(!ans) {
                    return false;
                }
            }
        }
        return true;
    }
};