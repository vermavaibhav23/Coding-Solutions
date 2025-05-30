//Find Center of Star Graph
//Compiler - C++
//https://leetcode.com/problems/find-center-of-star-graph/description/?envType=problem-list-v2&envId=graph

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>graph;
        for(auto edge: edges) {
            int u=edge[0], v= edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int n = edges.size();
        for(auto it: graph){
            if (it.second.size() == n) {
                return it.first;
            }
        }
        return -1;
    }
};