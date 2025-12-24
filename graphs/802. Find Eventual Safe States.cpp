//802. Find Eventual Safe States
//Compiler - C++
//https://leetcode.com/problems/find-eventual-safe-states/

class Solution {
public:
    bool cycle(vector<vector<int>>& graph, vector<bool> &visited, int src, vector<bool>&pathVisited) {
        if(visited[src] && pathVisited[src]) return true;
        if(visited[src]) return false;
        visited[src] = true;
        pathVisited[src] = true;
        for(auto it: graph[src]) {
            bool a = cycle(graph, visited, it, pathVisited);
            if(a) return true;
        }
        pathVisited[src] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool>visited(graph.size(), false);
        vector<bool>pathVisited(graph.size(), false);
        for(int i = 0; i < graph.size(); i++) {
            if(visited[i] == false) {
                cycle(graph, visited, i, pathVisited);
            }
        }
        vector<int>ans;
        for(int i = 0; i < graph.size(); i++) {
            if(pathVisited[i] == false) ans.push_back(i);
        }
        return ans;
    }
};